/*	6LoWPAN fragment reassembly
 *
 *
 *	Authors:
 *	Alexander Aring		<aar@pengutronix.de>
 *
 *	Based on: net/ipv6/reassembly.c
 *
 *	This program is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License
 *	as published by the Free Software Foundation; either version
 *	2 of the License, or (at your option) any later version.
 */

#define pr_fmt(fmt) "6LoWPAN: " fmt

#include <linux/net.h>
#include <linux/list.h>
#include <linux/netdevice.h>
#include <linux/random.h>
#include <linux/jhash.h>
#include <linux/skbuff.h>
#include <linux/slab.h>
#include <linux/export.h>

#include <net/ieee802154_netdev.h>
#include <net/6lowpan.h>
#include <net/ipv6.h>
#include <net/inet_frag.h>

#include "reassembly.h"

struct lowpan_frag_info {
	__be16 d_tag;
	u16 d_size;
	u8 d_offset;
};

struct lowpan_frag_info *lowpan_cb(struct sk_buff *skb)
{
	return (struct lowpan_frag_info *)skb->cb;
}

static struct inet_frags lowpan_frags;

static int lowpan_frag_reasm(struct lowpan_frag_queue *fq,
			     struct sk_buff *prev, struct net_device *dev);

static unsigned int lowpan_hash_frag(__be16 tag, u16 d_size,
				     const struct ieee802154_addr *saddr,
				     const struct ieee802154_addr *daddr)
{
	u32 c;

	net_get_random_once(&lowpan_frags.rnd, sizeof(lowpan_frags.rnd));
	c = jhash_3words(ieee802154_addr_hash(saddr),
			 ieee802154_addr_hash(daddr),
			 (__force u32)(tag + (d_size << 16)),
			 lowpan_frags.rnd);

	return c & (INETFRAGS_HASHSZ - 1);
}

static unsigned int lowpan_hashfn(struct inet_frag_queue *q)
{
	struct lowpan_frag_queue *fq;

	fq = container_of(q, struct lowpan_frag_queue, q);
	return lowpan_hash_frag(fq->tag, fq->d_size, &fq->saddr, &fq->daddr);
}

static bool lowpan_frag_match(struct inet_frag_queue *q, void *a)
{
	struct lowpan_frag_queue *fq;
	struct lowpan_create_arg *arg = a;

	fq = container_of(q, struct lowpan_frag_queue, q);
	return	fq->tag == arg->tag && fq->d_size == arg->d_size &&
		ieee802154_addr_equal(&fq->saddr, arg->src) &&
		ieee802154_addr_equal(&fq->daddr, arg->dst);
}

static void lowpan_frag_init(struct inet_frag_queue *q, void *a)
{
	struct lowpan_frag_queue *fq;
	struct lowpan_create_arg *arg = a;

	fq = container_of(q, struct lowpan_frag_queue, q);

	fq->tag = arg->tag;
	fq->d_size = arg->d_size;
	fq->saddr = *arg->src;
	fq->daddr = *arg->dst;
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,9,0)
	spin_lock_init(&fq->lru_lock);
#endif
}

static void lowpan_frag_expire(unsigned long data)
{
	struct frag_queue *fq;
	struct net *net;

	fq = container_of((struct inet_frag_queue *)data, struct frag_queue, q);
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,15,0))
	net = container_of(fq->q.net, struct net, ieee802154_lowpan.frags);
#else
	net = &init_net;
#endif

	spin_lock(&fq->q.lock);

	if (fq->q.last_in & INET_FRAG_COMPLETE)
		goto out;

	inet_frag_kill(&fq->q, &lowpan_frags);
out:
	spin_unlock(&fq->q.lock);
	inet_frag_put(&fq->q, &lowpan_frags);
}

static inline struct lowpan_frag_queue *
fq_find(struct net *net, const struct lowpan_frag_info *frag_info,
	const struct ieee802154_addr *src,
	const struct ieee802154_addr *dst)
{
	struct inet_frag_queue *q;
	struct lowpan_create_arg arg;
	unsigned int hash;

	arg.tag = frag_info->d_tag;
	arg.d_size = frag_info->d_size;
	arg.src = src;
	arg.dst = dst;

	read_lock(&lowpan_frags.lock);
	hash = lowpan_hash_frag(frag_info->d_tag, frag_info->d_size, src, dst);

	q = inet_frag_find(&net->ieee802154_lowpan.frags,
			   &lowpan_frags, &arg, hash);
	if (IS_ERR_OR_NULL(q)) {
		inet_frag_maybe_warn_overflow(q, pr_fmt());
		return NULL;
	}
	return container_of(q, struct lowpan_frag_queue, q);
}

static int lowpan_frag_queue(struct lowpan_frag_queue *fq,
			     struct sk_buff *skb, const u8 frag_type)
{
	struct sk_buff *prev, *next;
	struct net_device *dev;
	int end, offset;

	if (fq->q.last_in & INET_FRAG_COMPLETE)
		goto err;

	offset = lowpan_cb(skb)->d_offset << 3;
	end = lowpan_cb(skb)->d_size;

	/* Is this the final fragment? */
	if (offset + skb->len == end) {
		/* If we already have some bits beyond end
		 * or have different end, the segment is corrupted.
		 */
		if (end < fq->q.len ||
		    ((fq->q.last_in & INET_FRAG_LAST_IN) && end != fq->q.len))
			goto err;
		fq->q.last_in |= INET_FRAG_LAST_IN;
		fq->q.len = end;
	} else {
		if (end > fq->q.len) {
			/* Some bits beyond end -> corruption. */
			if (fq->q.last_in & INET_FRAG_LAST_IN)
				goto err;
			fq->q.len = end;
		}
	}

	/* Find out which fragments are in front and at the back of us
	 * in the chain of fragments so far.  We must know where to put
	 * this fragment, right?
	 */
	prev = fq->q.fragments_tail;
	if (!prev || lowpan_cb(prev)->d_offset < lowpan_cb(skb)->d_offset) {
		next = NULL;
		goto found;
	}
	prev = NULL;
	for (next = fq->q.fragments; next != NULL; next = next->next) {
		if (lowpan_cb(next)->d_offset >= lowpan_cb(skb)->d_offset)
			break;	/* bingo! */
		prev = next;
	}

found:
	/* Insert this fragment in the chain of fragments. */
	skb->next = next;
	if (!next)
		fq->q.fragments_tail = skb;
	if (prev)
		prev->next = skb;
	else
		fq->q.fragments = skb;

	dev = skb->dev;
	if (dev)
		skb->dev = NULL;

	fq->q.stamp = skb->tstamp;
	if (frag_type == LOWPAN_DISPATCH_FRAG1) {
		/* Calculate uncomp. 6lowpan header to estimate full size */
		fq->q.meat += lowpan_uncompress_size(skb, NULL);
		fq->q.last_in |= INET_FRAG_FIRST_IN;
	} else {
		fq->q.meat += skb->len;
	}
	add_frag_mem_limit(&fq->q, skb->truesize);

	if (fq->q.last_in == (INET_FRAG_FIRST_IN | INET_FRAG_LAST_IN) &&
	    fq->q.meat == fq->q.len) {
		int res;
		unsigned long orefdst = skb->_skb_refdst;

		skb->_skb_refdst = 0UL;
		res = lowpan_frag_reasm(fq, prev, dev);
		skb->_skb_refdst = orefdst;
		return res;
	}

	inet_frag_lru_move(&fq->q);
	return -1;
err:
	kfree_skb(skb);
	return -1;
}

/*	Check if this packet is complete.
 *	Returns NULL on failure by any reason, and pointer
 *	to current nexthdr field in reassembled frame.
 *
 *	It is called with locked fq, and caller must check that
 *	queue is eligible for reassembly i.e. it is not COMPLETE,
 *	the last and the first frames arrived and all the bits are here.
 */
static int lowpan_frag_reasm(struct lowpan_frag_queue *fq, struct sk_buff *prev,
			     struct net_device *dev)
{
	struct sk_buff *fp, *head = fq->q.fragments;
	int sum_truesize;

	inet_frag_kill(&fq->q, &lowpan_frags);

	/* Make the one we just received the head. */
	if (prev) {
		head = prev->next;
		fp = skb_clone(head, GFP_ATOMIC);

		if (!fp)
			goto out_oom;

		fp->next = head->next;
		if (!fp->next)
			fq->q.fragments_tail = fp;
		prev->next = fp;

		skb_morph(head, fq->q.fragments);
		head->next = fq->q.fragments->next;

		consume_skb(fq->q.fragments);
		fq->q.fragments = head;
	}

	/* Head of list must not be cloned. */
	if (skb_unclone(head, GFP_ATOMIC))
		goto out_oom;

	/* If the first fragment is fragmented itself, we split
	 * it to two chunks: the first with data and paged part
	 * and the second, holding only fragments.
	 */
	if (skb_has_frag_list(head)) {
		struct sk_buff *clone;
		int i, plen = 0;

		clone = alloc_skb(0, GFP_ATOMIC);
		if (!clone)
			goto out_oom;
		clone->next = head->next;
		head->next = clone;
		skb_shinfo(clone)->frag_list = skb_shinfo(head)->frag_list;
		skb_frag_list_init(head);
		for (i = 0; i < skb_shinfo(head)->nr_frags; i++)
			plen += skb_frag_size(&skb_shinfo(head)->frags[i]);
		clone->len = head->data_len - plen;
		clone->data_len = clone->len;
		head->data_len -= clone->len;
		head->len -= clone->len;
		add_frag_mem_limit(&fq->q, clone->truesize);
	}

	WARN_ON(head == NULL);

	sum_truesize = head->truesize;
	for (fp = head->next; fp;) {
		bool headstolen;
		int delta;
		struct sk_buff *next = fp->next;

		sum_truesize += fp->truesize;
		if (skb_try_coalesce(head, fp, &headstolen, &delta)) {
			kfree_skb_partial(fp, headstolen);
		} else {
			if (!skb_shinfo(head)->frag_list)
				skb_shinfo(head)->frag_list = fp;
			head->data_len += fp->len;
			head->len += fp->len;
			head->truesize += fp->truesize;
		}
		fp = next;
	}
	sub_frag_mem_limit(&fq->q, sum_truesize);

	head->next = NULL;
	head->dev = dev;
	head->tstamp = fq->q.stamp;

	fq->q.fragments = NULL;
	fq->q.fragments_tail = NULL;

	return 1;
out_oom:
	net_dbg_ratelimited("lowpan_frag_reasm: no memory for reassembly\n");
	return -1;
}

static int lowpan_get_frag_info(struct sk_buff *skb, const u8 frag_type,
				struct lowpan_frag_info *frag_info)
{
	bool fail;
	u8 pattern = 0, low = 0;

	fail = lowpan_fetch_skb(skb, &pattern, 1);
	fail |= lowpan_fetch_skb(skb, &low, 1);
	frag_info->d_size = (pattern & 7) << 8 | low;
	fail |= lowpan_fetch_skb(skb, &frag_info->d_tag, 2);

	if (frag_type == LOWPAN_DISPATCH_FRAGN) {
		fail |= lowpan_fetch_skb(skb, &frag_info->d_offset, 1);
	} else {
		skb_reset_network_header(skb);
		frag_info->d_offset = 0;
	}

	if (unlikely(fail))
		return -EIO;

	return 0;
}

int lowpan_frag_rcv(struct sk_buff *skb, const u8 frag_type)
{
	struct lowpan_frag_queue *fq;
	struct net *net = dev_net(skb->dev);
	struct lowpan_frag_info *frag_info = lowpan_cb(skb);
	struct ieee802154_addr source, dest;
	int err;

	source = mac_cb(skb)->source;
	dest = mac_cb(skb)->dest;

	err = lowpan_get_frag_info(skb, frag_type, frag_info);
	if (err < 0)
		goto err;

	if (frag_info->d_size > net->ieee802154_lowpan.max_dsize)
		goto err;

	inet_frag_evictor(&net->ieee802154_lowpan.frags, &lowpan_frags, false);

	fq = fq_find(net, frag_info, &source, &dest);
	if (fq != NULL) {
		int ret;
		spin_lock(&fq->q.lock);
		ret = lowpan_frag_queue(fq, skb, frag_type);
		spin_unlock(&fq->q.lock);

		inet_frag_put(&fq->q, &lowpan_frags);
		return ret;
	}

err:
	kfree_skb(skb);
	return -1;
}
EXPORT_SYMBOL(lowpan_frag_rcv);

#ifdef CONFIG_SYSCTL
static struct ctl_table lowpan_frags_ns_ctl_table[] = {
	{
		.procname	= "6lowpanfrag_high_thresh",
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,15,0))
		.data		= &init_net.ieee802154_lowpan.frags.high_thresh,
#else
		.data		= &ieee802154_lowpan.frags.high_thresh,
#endif
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec
	},
	{
		.procname	= "6lowpanfrag_low_thresh",
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,15,0))
		.data		= &init_net.ieee802154_lowpan.frags.low_thresh,
#else
		.data		= &ieee802154_lowpan.frags.low_thresh,
#endif
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec
	},
	{
		.procname	= "6lowpanfrag_time",
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,15,0))
		.data		= &init_net.ieee802154_lowpan.frags.timeout,
#else
		.data		= &ieee802154_lowpan.frags.timeout,
#endif
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec_jiffies,
	},
	{
		.procname	= "6lowpanfrag_max_datagram_size",
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,15,0))
		.data		= &init_net.ieee802154_lowpan.max_dsize,
#else
		.data		= &ieee802154_lowpan.max_dsize,
#endif
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec
	},
	{ }
};

static struct ctl_table lowpan_frags_ctl_table[] = {
	{
		.procname	= "6lowpanfrag_secret_interval",
		.data		= &lowpan_frags.secret_interval,
		.maxlen		= sizeof(int),
		.mode		= 0644,
		.proc_handler	= proc_dointvec_jiffies,
	},
	{ }
};

static int __net_init lowpan_frags_ns_sysctl_register(struct net *net)
{
	struct ctl_table *table;
	struct ctl_table_header *hdr;

	table = lowpan_frags_ns_ctl_table;
	if (!net_eq(net, &init_net)) {
		table = kmemdup(table, sizeof(lowpan_frags_ns_ctl_table),
				GFP_KERNEL);
		if (table == NULL)
			goto err_alloc;

		table[0].data = &net->ieee802154_lowpan.frags.high_thresh;
		table[1].data = &net->ieee802154_lowpan.frags.low_thresh;
		table[2].data = &net->ieee802154_lowpan.frags.timeout;
		table[3].data = &net->ieee802154_lowpan.max_dsize;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,8,0)
		/* Don't export sysctls to unprivileged users */
		if (net->user_ns != &init_user_ns)
			table[0].procname = NULL;
#endif /* LINUX_VERSION_CODE <= KERNEL_VERSION(3,8,0) */
	}

	hdr = register_net_sysctl(net, "net/ieee802154/6lowpan", table);
	if (hdr == NULL)
		goto err_reg;

	net->ieee802154_lowpan.sysctl.frags_hdr = hdr;
	return 0;

err_reg:
	if (!net_eq(net, &init_net))
		kfree(table);
err_alloc:
	return -ENOMEM;
}

static void __net_exit lowpan_frags_ns_sysctl_unregister(struct net *net)
{
	struct ctl_table *table;

	table = net->ieee802154_lowpan.sysctl.frags_hdr->ctl_table_arg;
	unregister_net_sysctl_table(net->ieee802154_lowpan.sysctl.frags_hdr);
	if (!net_eq(net, &init_net))
		kfree(table);
}

static struct ctl_table_header *lowpan_ctl_header;

static int lowpan_frags_sysctl_register(void)
{
	lowpan_ctl_header = register_net_sysctl(&init_net,
						"net/ieee802154/6lowpan",
						lowpan_frags_ctl_table);
	return lowpan_ctl_header == NULL ? -ENOMEM : 0;
}

static void lowpan_frags_sysctl_unregister(void)
{
	unregister_net_sysctl_table(lowpan_ctl_header);
}
#else
static inline int lowpan_frags_ns_sysctl_register(struct net *net)
{
	return 0;
}

static inline void lowpan_frags_ns_sysctl_unregister(struct net *net)
{
}

static inline int lowpan_frags_sysctl_register(void)
{
	return 0;
}

static inline void lowpan_frags_sysctl_unregister(void)
{
}
#endif

static int __net_init lowpan_frags_init_net(struct net *net)
{
	net->ieee802154_lowpan.frags.high_thresh = IPV6_FRAG_HIGH_THRESH;
	net->ieee802154_lowpan.frags.low_thresh = IPV6_FRAG_LOW_THRESH;
	net->ieee802154_lowpan.frags.timeout = IPV6_FRAG_TIMEOUT;
	net->ieee802154_lowpan.max_dsize = 0xFFFF;

	inet_frags_init_net(&net->ieee802154_lowpan.frags);

	return lowpan_frags_ns_sysctl_register(net);
}

static void __net_exit lowpan_frags_exit_net(struct net *net)
{
	lowpan_frags_ns_sysctl_unregister(net);
	inet_frags_exit_net(&net->ieee802154_lowpan.frags, &lowpan_frags);
}

static struct pernet_operations lowpan_frags_ops = {
	.init = lowpan_frags_init_net,
	.exit = lowpan_frags_exit_net,
};

int __init lowpan_net_frag_init(void)
{
	int ret;

	ret = lowpan_frags_sysctl_register();
	if (ret)
		return ret;

	ret = register_pernet_subsys(&lowpan_frags_ops);
	if (ret)
		goto err_pernet;

	lowpan_frags.hashfn = lowpan_hashfn;
	lowpan_frags.constructor = lowpan_frag_init;
	lowpan_frags.destructor = NULL;
	lowpan_frags.skb_free = NULL;
	lowpan_frags.qsize = sizeof(struct frag_queue);
	lowpan_frags.match = lowpan_frag_match;
	lowpan_frags.frag_expire = lowpan_frag_expire;
	lowpan_frags.secret_interval = 10 * 60 * HZ;
	inet_frags_init(&lowpan_frags);

	return ret;
err_pernet:
	lowpan_frags_sysctl_unregister();
	return ret;
}

void lowpan_net_frag_exit(void)
{
	inet_frags_fini(&lowpan_frags);
	lowpan_frags_sysctl_unregister();
	unregister_pernet_subsys(&lowpan_frags_ops);
}
