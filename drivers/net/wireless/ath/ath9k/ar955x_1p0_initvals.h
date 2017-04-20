/*
 * Copyright (c) 2010-2011 Atheros Communications Inc.
 * Copyright (c) 2011-2012 Qualcomm Atheros Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef INITVALS_955X_1P0_H
#define INITVALS_955X_1P0_H

/* AR955X 1.0 */

#define ar955x_1p0_soc_postamble ar9300_2p2_soc_postamble

#define ar955x_1p0_common_rx_gain_table ar9300Common_rx_gain_table_2p2

#define ar955x_1p0_common_wo_xlna_rx_gain_table ar9300Common_wo_xlna_rx_gain_table_2p2

#define ar955x_1p0_baseband_core_txfir_coeff_japan_2484 ar9300_2p2_baseband_core_txfir_coeff_japan_2484

static const u32 ar955x_1p0_radio_postamble[][5] = {
	/* Addr      5G_HT20     5G_HT40     2G_HT40     2G_HT20   */
	{0x00016098, 0xd2dd5554, 0xd2dd5554, 0xd28b3330, 0xd28b3330},
	{0x0001609c, 0x0a566f3a, 0x0a566f3a, 0x0a566f3a, 0x0a566f3a},
	{0x000160ac, 0xa4647c00, 0xa4647c00, 0x24647c00, 0x24647c00},
	{0x000160b0, 0x01885f52, 0x01885f52, 0x01885f52, 0x01885f52},
	{0x00016104, 0xb7a00000, 0xb7a00000, 0xb7a00001, 0xb7a00001},
	{0x0001610c, 0xc0000000, 0xc0000000, 0xc0000000, 0xc0000000},
	{0x00016140, 0x10804008, 0x10804008, 0x10804008, 0x10804008},
	{0x00016504, 0xb7a00000, 0xb7a00000, 0xb7a00001, 0xb7a00001},
	{0x0001650c, 0xc0000000, 0xc0000000, 0xc0000000, 0xc0000000},
	{0x00016540, 0x10804008, 0x10804008, 0x10804008, 0x10804008},
	{0x00016904, 0xb7a00000, 0xb7a00000, 0xb7a00001, 0xb7a00001},
	{0x0001690c, 0xc0000000, 0xc0000000, 0xc0000000, 0xc0000000},
	{0x00016940, 0x10804008, 0x10804008, 0x10804008, 0x10804008},
};

static const u32 ar955x_1p0_baseband_postamble[][5] = {
	/* Addr      5G_HT20     5G_HT40     2G_HT40     2G_HT20   */
	{0x00009810, 0xd00a8005, 0xd00a8005, 0xd00a8011, 0xd00a8011},
	{0x00009820, 0x206a022e, 0x206a022e, 0x206a012e, 0x206a012e},
	{0x00009824, 0x5ac640d0, 0x5ac640d0, 0x5ac640d0, 0x5ac640d0},
	{0x00009828, 0x06903081, 0x06903081, 0x06903881, 0x06903881},
	{0x0000982c, 0x05eea6d4, 0x05eea6d4, 0x05eea6d4, 0x05eea6d4},
	{0x00009830, 0x0000059c, 0x0000059c, 0x0000119c, 0x0000119c},
	{0x00009c00, 0x000000c4, 0x000000c4, 0x000000c4, 0x000000c4},
	{0x00009e00, 0x0372111a, 0x0372111a, 0x037216a0, 0x037216a0},
	{0x00009e04, 0x001c2020, 0x001c2020, 0x001c2020, 0x001c2020},
	{0x00009e0c, 0x6c4000e2, 0x6d4000e2, 0x6d4000e2, 0x6c4000e2},
	{0x00009e10, 0x7ec88d2e, 0x7ec88d2e, 0x7ec84d2e, 0x7ec84d2e},
	{0x00009e14, 0x37b95d5e, 0x37b9605e, 0x3379605e, 0x33795d5e},
	{0x00009e18, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00009e1c, 0x0001cf9c, 0x0001cf9c, 0x00021f9c, 0x00021f9c},
	{0x00009e20, 0x000003b5, 0x000003b5, 0x000003A0, 0x000003A0},
	{0x00009e2c, 0x0000001c, 0x0000001c, 0x00000021, 0x00000021},
	{0x00009e3c, 0xcfa10820, 0xcfa10820, 0xcfa10822, 0xcfa10822},
	{0x00009e44, 0xfe321e27, 0xfe321e27, 0xfe291e27, 0xfe291e27},
	{0x00009e48, 0x5030201a, 0x5030201a, 0x50302012, 0x50302012},
	{0x00009fc8, 0x0003f000, 0x0003f000, 0x0001a000, 0x0001a000},
	{0x0000a204, 0x005c0ec0, 0x005c0ec4, 0x005c0ec4, 0x005c0ec0},
	{0x0000a208, 0x00000104, 0x00000104, 0x00000004, 0x00000004},
	{0x0000a22c, 0x07e26a2f, 0x07e26a2f, 0x01026a2f, 0x01026a2f},
	{0x0000a230, 0x0000400a, 0x00004014, 0x00004016, 0x0000400b},
	{0x0000a234, 0x00000fff, 0x10000fff, 0x10000fff, 0x00000fff},
	{0x0000a238, 0xffb01018, 0xffb01018, 0xffb01018, 0xffb01018},
	{0x0000a250, 0x00000000, 0x00000000, 0x00000210, 0x00000108},
	{0x0000a254, 0x000007d0, 0x00000fa0, 0x00001130, 0x00000898},
	{0x0000a258, 0x02020002, 0x02020002, 0x02020002, 0x02020002},
	{0x0000a25c, 0x01000e0e, 0x01000e0e, 0x01010e0e, 0x01010e0e},
	{0x0000a260, 0x0a021501, 0x0a021501, 0x3a021501, 0x3a021501},
	{0x0000a264, 0x00000e0e, 0x00000e0e, 0x01000e0e, 0x01000e0e},
	{0x0000a280, 0x00000007, 0x00000007, 0x0000000b, 0x0000000b},
	{0x0000a284, 0x00000000, 0x00000000, 0x00000010, 0x00000010},
	{0x0000a288, 0x00000110, 0x00000110, 0x00000110, 0x00000110},
	{0x0000a28c, 0x00022222, 0x00022222, 0x00022222, 0x00022222},
	{0x0000a2c4, 0x00158d18, 0x00158d18, 0x00158d18, 0x00158d18},
	{0x0000a2cc, 0x18c50033, 0x18c43433, 0x18c41033, 0x18c44c33},
	{0x0000a2d0, 0x00041982, 0x00041982, 0x00041982, 0x00041982},
	{0x0000a2d8, 0x7999a83b, 0x7999a83b, 0x7999a83b, 0x7999a83b},
	{0x0000a358, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a830, 0x0000019c, 0x0000019c, 0x0000019c, 0x0000019c},
	{0x0000ae04, 0x001c0000, 0x001c0000, 0x001c0000, 0x001c0000},
	{0x0000ae18, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000ae1c, 0x0000019c, 0x0000019c, 0x0000019c, 0x0000019c},
	{0x0000ae20, 0x000001b5, 0x000001b5, 0x000001A0, 0x000001A0},
	{0x0000b284, 0x00000000, 0x00000000, 0x00000010, 0x00000010},
	{0x0000b830, 0x0000019c, 0x0000019c, 0x0000019c, 0x0000019c},
	{0x0000be04, 0x001c0000, 0x001c0000, 0x001c0000, 0x001c0000},
	{0x0000be18, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000be1c, 0x0000019c, 0x0000019c, 0x0000019c, 0x0000019c},
	{0x0000be20, 0x000001b5, 0x000001b5, 0x000001A0, 0x000001A0},
	{0x0000c284, 0x00000000, 0x00000000, 0x00000010, 0x00000010},
};

static const u32 ar955x_1p0_radio_core[][2] = {
	/* Addr      allmodes  */
	{0x00016000, 0x36db6db6},
	{0x00016004, 0x6db6db40},
	{0x00016008, 0x73f00000},
	{0x0001600c, 0x00000000},
	{0x00016040, 0x7f80fff8},
	{0x0001604c, 0x76d005b5},
	{0x00016050, 0x557cf031},
	{0x00016054, 0x13449440},
	{0x00016058, 0x0c51c92c},
	{0x0001605c, 0x3db7fffc},
	{0x00016060, 0xfffffffc},
	{0x00016064, 0x000f0278},
	{0x00016068, 0x6db6db6c},
	{0x0001606c, 0x6db60000},
	{0x00016080, 0x00080000},
	{0x00016084, 0x0e48048c},
	{0x00016088, 0x14214514},
	{0x0001608c, 0x119f101e},
	{0x00016090, 0x24926490},
	{0x00016094, 0x00000000},
	{0x000160a0, 0x0a108ffe},
	{0x000160a4, 0x812fc370},
	{0x000160a8, 0x423c8100},
	{0x000160b4, 0x92480080},
	{0x000160c0, 0x006db6d0},
	{0x000160c4, 0x6db6db60},
	{0x000160c8, 0x6db6db6c},
	{0x000160cc, 0x01e6c000},
	{0x00016100, 0x11999601},
	{0x00016108, 0x00080010},
	{0x00016144, 0x02084080},
	{0x00016148, 0x00008040},
	{0x00016280, 0x01800804},
	{0x00016284, 0x00038dc5},
	{0x00016288, 0x00000000},
	{0x0001628c, 0x00000040},
	{0x00016380, 0x00000000},
	{0x00016384, 0x00000000},
	{0x00016388, 0x00400705},
	{0x0001638c, 0x00800700},
	{0x00016390, 0x00800700},
	{0x00016394, 0x00000000},
	{0x00016398, 0x00000000},
	{0x0001639c, 0x00000000},
	{0x000163a0, 0x00000001},
	{0x000163a4, 0x00000001},
	{0x000163a8, 0x00000000},
	{0x000163ac, 0x00000000},
	{0x000163b0, 0x00000000},
	{0x000163b4, 0x00000000},
	{0x000163b8, 0x00000000},
	{0x000163bc, 0x00000000},
	{0x000163c0, 0x000000a0},
	{0x000163c4, 0x000c0000},
	{0x000163c8, 0x14021402},
	{0x000163cc, 0x00001402},
	{0x000163d0, 0x00000000},
	{0x000163d4, 0x00000000},
	{0x00016400, 0x36db6db6},
	{0x00016404, 0x6db6db40},
	{0x00016408, 0x73f00000},
	{0x0001640c, 0x00000000},
	{0x00016440, 0x7f80fff8},
	{0x0001644c, 0x76d005b5},
	{0x00016450, 0x557cf031},
	{0x00016454, 0x13449440},
	{0x00016458, 0x0c51c92c},
	{0x0001645c, 0x3db7fffc},
	{0x00016460, 0xfffffffc},
	{0x00016464, 0x000f0278},
	{0x00016468, 0x6db6db6c},
	{0x0001646c, 0x6db60000},
	{0x00016500, 0x11999601},
	{0x00016508, 0x00080010},
	{0x00016544, 0x02084080},
	{0x00016548, 0x00008040},
	{0x00016780, 0x00000000},
	{0x00016784, 0x00000000},
	{0x00016788, 0x00400705},
	{0x0001678c, 0x00800700},
	{0x00016790, 0x00800700},
	{0x00016794, 0x00000000},
	{0x00016798, 0x00000000},
	{0x0001679c, 0x00000000},
	{0x000167a0, 0x00000001},
	{0x000167a4, 0x00000001},
	{0x000167a8, 0x00000000},
	{0x000167ac, 0x00000000},
	{0x000167b0, 0x00000000},
	{0x000167b4, 0x00000000},
	{0x000167b8, 0x00000000},
	{0x000167bc, 0x00000000},
	{0x000167c0, 0x000000a0},
	{0x000167c4, 0x000c0000},
	{0x000167c8, 0x14021402},
	{0x000167cc, 0x00001402},
	{0x000167d0, 0x00000000},
	{0x000167d4, 0x00000000},
	{0x00016800, 0x36db6db6},
	{0x00016804, 0x6db6db40},
	{0x00016808, 0x73f00000},
	{0x0001680c, 0x00000000},
	{0x00016840, 0x7f80fff8},
	{0x0001684c, 0x76d005b5},
	{0x00016850, 0x557cf031},
	{0x00016854, 0x13449440},
	{0x00016858, 0x0c51c92c},
	{0x0001685c, 0x3db7fffc},
	{0x00016860, 0xfffffffc},
	{0x00016864, 0x000f0278},
	{0x00016868, 0x6db6db6c},
	{0x0001686c, 0x6db60000},
	{0x00016900, 0x11999601},
	{0x00016908, 0x00080010},
	{0x00016944, 0x02084080},
	{0x00016948, 0x00008040},
	{0x00016b80, 0x00000000},
	{0x00016b84, 0x00000000},
	{0x00016b88, 0x00400705},
	{0x00016b8c, 0x00800700},
	{0x00016b90, 0x00800700},
	{0x00016b94, 0x00000000},
	{0x00016b98, 0x00000000},
	{0x00016b9c, 0x00000000},
	{0x00016ba0, 0x00000001},
	{0x00016ba4, 0x00000001},
	{0x00016ba8, 0x00000000},
	{0x00016bac, 0x00000000},
	{0x00016bb0, 0x00000000},
	{0x00016bb4, 0x00000000},
	{0x00016bb8, 0x00000000},
	{0x00016bbc, 0x00000000},
	{0x00016bc0, 0x000000a0},
	{0x00016bc4, 0x000c0000},
	{0x00016bc8, 0x14021402},
	{0x00016bcc, 0x00001402},
	{0x00016bd0, 0x00000000},
	{0x00016bd4, 0x00000000},
};

static const u32 ar955x_1p0_modes_xpa_tx_gain_table[][9] = {
	/* Addr      5G_HT20_L   5G_HT40_L   5G_HT20_M   5G_HT40_M   5G_HT20_H   5G_HT40_H   2G_HT40     2G_HT20  */
	{0x0000a2dc, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xfffd5aaa, 0xfffd5aaa},
	{0x0000a2e0, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffe9ccc, 0xfffe9ccc},
	{0x0000a2e4, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffffe0f0, 0xffffe0f0},
	{0x0000a2e8, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xfffcff00, 0xfffcff00},
	{0x0000a410, 0x000050de, 0x000050de, 0x000050de, 0x000050de, 0x000050de, 0x000050de, 0x000050da, 0x000050da},
	{0x0000a500, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000000},
	{0x0000a504, 0x04000005, 0x04000005, 0x04000005, 0x04000005, 0x04000005, 0x04000005, 0x04000002, 0x04000002},
	{0x0000a508, 0x08000009, 0x08000009, 0x08000009, 0x08000009, 0x08000009, 0x08000009, 0x08000004, 0x08000004},
	{0x0000a50c, 0x0c00000b, 0x0c00000b, 0x0c00000b, 0x0c00000b, 0x0c00000b, 0x0c00000b, 0x0c000006, 0x0c000006},
	{0x0000a510, 0x1000000d, 0x1000000d, 0x1000000d, 0x1000000d, 0x1000000d, 0x1000000d, 0x0f00000a, 0x0f00000a},
	{0x0000a514, 0x14000011, 0x14000011, 0x14000011, 0x14000011, 0x14000011, 0x14000011, 0x1300000c, 0x1300000c},
	{0x0000a518, 0x1700002b, 0x1700002b, 0x1700002b, 0x1700002b, 0x1600002b, 0x1600002b, 0x1700000e, 0x1700000e},
	{0x0000a51c, 0x1b00002d, 0x1b00002d, 0x1b00002d, 0x1b00002d, 0x1a00002d, 0x1a00002d, 0x1b000064, 0x1b000064},
	{0x0000a520, 0x20000031, 0x20000031, 0x1f000031, 0x1f000031, 0x1e000031, 0x1e000031, 0x1f000242, 0x1f000242},
	{0x0000a524, 0x24000051, 0x24000051, 0x23000051, 0x23000051, 0x23000051, 0x23000051, 0x23000229, 0x23000229},
	{0x0000a528, 0x27000071, 0x27000071, 0x27000071, 0x27000071, 0x26000071, 0x26000071, 0x270002a2, 0x270002a2},
	{0x0000a52c, 0x2b000092, 0x2b000092, 0x2b000092, 0x2b000092, 0x2b000092, 0x2b000092, 0x2c001203, 0x2c001203},
	{0x0000a530, 0x3000028c, 0x3000028c, 0x2f00028c, 0x2f00028c, 0x2e00028c, 0x2e00028c, 0x30001803, 0x30001803},
	{0x0000a534, 0x34000290, 0x34000290, 0x33000290, 0x33000290, 0x32000290, 0x32000290, 0x33000881, 0x33000881},
	{0x0000a538, 0x37000292, 0x37000292, 0x36000292, 0x36000292, 0x35000292, 0x35000292, 0x38001809, 0x38001809},
	{0x0000a53c, 0x3b02028d, 0x3b02028d, 0x3a02028d, 0x3a02028d, 0x3902028d, 0x3902028d, 0x3a000814, 0x3a000814},
	{0x0000a540, 0x3f020291, 0x3f020291, 0x3e020291, 0x3e020291, 0x3d020291, 0x3d020291, 0x3f001a0c, 0x3f001a0c},
	{0x0000a544, 0x44020490, 0x44020490, 0x43020490, 0x43020490, 0x42020490, 0x42020490, 0x43001a0e, 0x43001a0e},
	{0x0000a548, 0x48020492, 0x48020492, 0x47020492, 0x47020492, 0x46020492, 0x46020492, 0x46001812, 0x46001812},
	{0x0000a54c, 0x4c020692, 0x4c020692, 0x4b020692, 0x4b020692, 0x4a020692, 0x4a020692, 0x49001884, 0x49001884},
	{0x0000a550, 0x50020892, 0x50020892, 0x4f020892, 0x4f020892, 0x4e020892, 0x4e020892, 0x4d001e84, 0x4d001e84},
	{0x0000a554, 0x53040891, 0x53040891, 0x53040891, 0x53040891, 0x52040891, 0x52040891, 0x50001e69, 0x50001e69},
	{0x0000a558, 0x58040893, 0x58040893, 0x57040893, 0x57040893, 0x56040893, 0x56040893, 0x550006f4, 0x550006f4},
	{0x0000a55c, 0x5c0408b4, 0x5c0408b4, 0x5a0408b4, 0x5a0408b4, 0x5a0408b4, 0x5a0408b4, 0x59000ad3, 0x59000ad3},
	{0x0000a560, 0x610408b6, 0x610408b6, 0x5e0408b6, 0x5e0408b6, 0x5e0408b6, 0x5e0408b6, 0x5e000ad5, 0x5e000ad5},
	{0x0000a564, 0x670408f6, 0x670408f6, 0x620408f6, 0x620408f6, 0x620408f6, 0x620408f6, 0x61001ced, 0x61001ced},
	{0x0000a568, 0x6a040cf6, 0x6a040cf6, 0x66040cf6, 0x66040cf6, 0x66040cf6, 0x66040cf6, 0x660018d4, 0x660018d4},
	{0x0000a56c, 0x6d040d76, 0x6d040d76, 0x6a040d76, 0x6a040d76, 0x6a040d76, 0x6a040d76, 0x660018d4, 0x660018d4},
	{0x0000a570, 0x70060db6, 0x70060db6, 0x6e060db6, 0x6e060db6, 0x6e060db6, 0x6e060db6, 0x660018d4, 0x660018d4},
	{0x0000a574, 0x730a0df6, 0x730a0df6, 0x720a0df6, 0x720a0df6, 0x720a0df6, 0x720a0df6, 0x660018d4, 0x660018d4},
	{0x0000a578, 0x770a13f6, 0x770a13f6, 0x760a13f6, 0x760a13f6, 0x760a13f6, 0x760a13f6, 0x660018d4, 0x660018d4},
	{0x0000a57c, 0x770a13f6, 0x770a13f6, 0x760a13f6, 0x760a13f6, 0x760a13f6, 0x760a13f6, 0x660018d4, 0x660018d4},
	{0x0000a600, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a604, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a608, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a60c, 0x02c04b01, 0x02c04b01, 0x02c04b01, 0x02c04b01, 0x02c04b01, 0x02c04b01, 0x03804000, 0x03804000},
	{0x0000a610, 0x04008b01, 0x04008b01, 0x04008b01, 0x04008b01, 0x03c08b01, 0x03c08b01, 0x0300ca02, 0x0300ca02},
	{0x0000a614, 0x05811403, 0x05811403, 0x05411303, 0x05411303, 0x05411303, 0x05411303, 0x00000e04, 0x00000e04},
	{0x0000a618, 0x05811604, 0x05811604, 0x05411504, 0x05411504, 0x05411504, 0x05411504, 0x03014000, 0x03014000},
	{0x0000a61c, 0x05811604, 0x05811604, 0x05411504, 0x05411504, 0x05411504, 0x05411504, 0x00000000, 0x00000000},
	{0x0000a620, 0x05811604, 0x05811604, 0x05411504, 0x05411504, 0x05411504, 0x05411504, 0x00000000, 0x00000000},
	{0x0000a624, 0x05811604, 0x05811604, 0x05411504, 0x05411504, 0x05411504, 0x05411504, 0x03014000, 0x03014000},
	{0x0000a628, 0x05811604, 0x05811604, 0x05411504, 0x05411504, 0x05411504, 0x05411504, 0x03804c05, 0x03804c05},
	{0x0000a62c, 0x06815604, 0x06815604, 0x06415504, 0x06415504, 0x06015504, 0x06015504, 0x0701de06, 0x0701de06},
	{0x0000a630, 0x07819a05, 0x07819a05, 0x07419905, 0x07419905, 0x07019805, 0x07019805, 0x07819c07, 0x07819c07},
	{0x0000a634, 0x07819e06, 0x07819e06, 0x07419d06, 0x07419d06, 0x07019c06, 0x07019c06, 0x0701dc07, 0x0701dc07},
	{0x0000a638, 0x07819e06, 0x07819e06, 0x07419d06, 0x07419d06, 0x07019c06, 0x07019c06, 0x0701dc07, 0x0701dc07},
	{0x0000a63c, 0x07819e06, 0x07819e06, 0x07419d06, 0x07419d06, 0x07019c06, 0x07019c06, 0x0701dc07, 0x0701dc07},
	{0x0000b2dc, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xfffd5aaa, 0xfffd5aaa},
	{0x0000b2e0, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffe9ccc, 0xfffe9ccc},
	{0x0000b2e4, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffffe0f0, 0xffffe0f0},
	{0x0000b2e8, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xfffcff00, 0xfffcff00},
	{0x0000c2dc, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xffff6aaa, 0xfffd5aaa, 0xfffd5aaa},
	{0x0000c2e0, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffdcccc, 0xfffe9ccc, 0xfffe9ccc},
	{0x0000c2e4, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffe3b0f0, 0xffffe0f0, 0xffffe0f0},
	{0x0000c2e8, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xfffcff00, 0xfffcff00},
	{0x00016044, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x010002d4, 0x010002d4},
	{0x00016048, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401},
	{0x00016280, 0x01801e84, 0x01801e84, 0x01801e84, 0x01801e84, 0x01801e84, 0x01801e84, 0x01808e84, 0x01808e84},
	{0x00016444, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x010002d4, 0x010002d4},
	{0x00016448, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401},
	{0x00016844, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x010002d4, 0x010002d4},
	{0x00016848, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401},
};

static const u32 ar955x_1p0_mac_core[][2] = {
	/* Addr      allmodes  */
	{0x00000008, 0x00000000},
	{0x00000030, 0x00020085},
	{0x00000034, 0x00000005},
	{0x00000040, 0x00000000},
	{0x00000044, 0x00000000},
	{0x00000048, 0x00000008},
	{0x0000004c, 0x00000010},
	{0x00000050, 0x00000000},
	{0x00001040, 0x002ffc0f},
	{0x00001044, 0x002ffc0f},
	{0x00001048, 0x002ffc0f},
	{0x0000104c, 0x002ffc0f},
	{0x00001050, 0x002ffc0f},
	{0x00001054, 0x002ffc0f},
	{0x00001058, 0x002ffc0f},
	{0x0000105c, 0x002ffc0f},
	{0x00001060, 0x002ffc0f},
	{0x00001064, 0x002ffc0f},
	{0x000010f0, 0x00000100},
	{0x00001270, 0x00000000},
	{0x000012b0, 0x00000000},
	{0x000012f0, 0x00000000},
	{0x0000143c, 0x00000000},
	{0x0000147c, 0x00000000},
	{0x00008000, 0x00000000},
	{0x00008004, 0x00000000},
	{0x00008008, 0x00000000},
	{0x0000800c, 0x00000000},
	{0x00008018, 0x00000000},
	{0x00008020, 0x00000000},
	{0x00008038, 0x00000000},
	{0x0000803c, 0x00000000},
	{0x00008040, 0x00000000},
	{0x00008044, 0x00000000},
	{0x00008048, 0x00000000},
	{0x0000804c, 0xffffffff},
	{0x00008054, 0x00000000},
	{0x00008058, 0x00000000},
	{0x0000805c, 0x000fc78f},
	{0x00008060, 0x0000000f},
	{0x00008064, 0x00000000},
	{0x00008070, 0x00000310},
	{0x00008074, 0x00000020},
	{0x00008078, 0x00000000},
	{0x0000809c, 0x0000000f},
	{0x000080a0, 0x00000000},
	{0x000080a4, 0x02ff0000},
	{0x000080a8, 0x0e070605},
	{0x000080ac, 0x0000000d},
	{0x000080b0, 0x00000000},
	{0x000080b4, 0x00000000},
	{0x000080b8, 0x00000000},
	{0x000080bc, 0x00000000},
	{0x000080c0, 0x2a800000},
	{0x000080c4, 0x06900168},
	{0x000080c8, 0x13881c22},
	{0x000080cc, 0x01f40000},
	{0x000080d0, 0x00252500},
	{0x000080d4, 0x00a00000},
	{0x000080d8, 0x00400000},
	{0x000080dc, 0x00000000},
	{0x000080e0, 0xffffffff},
	{0x000080e4, 0x0000ffff},
	{0x000080e8, 0x3f3f3f3f},
	{0x000080ec, 0x00000000},
	{0x000080f0, 0x00000000},
	{0x000080f4, 0x00000000},
	{0x000080fc, 0x00020000},
	{0x00008100, 0x00000000},
	{0x00008108, 0x00000052},
	{0x0000810c, 0x00000000},
	{0x00008110, 0x00000000},
	{0x00008114, 0x000007ff},
	{0x00008118, 0x000000aa},
	{0x0000811c, 0x00003210},
	{0x00008124, 0x00000000},
	{0x00008128, 0x00000000},
	{0x0000812c, 0x00000000},
	{0x00008130, 0x00000000},
	{0x00008134, 0x00000000},
	{0x00008138, 0x00000000},
	{0x0000813c, 0x0000ffff},
	{0x00008140, 0x000000fe},
	{0x00008144, 0xffffffff},
	{0x00008168, 0x00000000},
	{0x0000816c, 0x00000000},
	{0x000081c0, 0x00000000},
	{0x000081c4, 0x33332210},
	{0x000081ec, 0x00000000},
	{0x000081f0, 0x00000000},
	{0x000081f4, 0x00000000},
	{0x000081f8, 0x00000000},
	{0x000081fc, 0x00000000},
	{0x00008240, 0x00100000},
	{0x00008244, 0x0010f400},
	{0x00008248, 0x00000800},
	{0x0000824c, 0x0001e800},
	{0x00008250, 0x00000000},
	{0x00008254, 0x00000000},
	{0x00008258, 0x00000000},
	{0x0000825c, 0x40000000},
	{0x00008260, 0x00080922},
	{0x00008264, 0x9d400010},
	{0x00008268, 0xffffffff},
	{0x0000826c, 0x0000ffff},
	{0x00008270, 0x00000000},
	{0x00008274, 0x40000000},
	{0x00008278, 0x003e4180},
	{0x0000827c, 0x00000004},
	{0x00008284, 0x0000002c},
	{0x00008288, 0x0000002c},
	{0x0000828c, 0x000000ff},
	{0x00008294, 0x00000000},
	{0x00008298, 0x00000000},
	{0x0000829c, 0x00000000},
	{0x00008300, 0x00001d40},
	{0x00008314, 0x00000000},
	{0x0000831c, 0x0000010d},
	{0x00008328, 0x00000000},
	{0x0000832c, 0x0000001f},
	{0x00008330, 0x00000302},
	{0x00008334, 0x00000700},
	{0x00008338, 0xffff0000},
	{0x0000833c, 0x02400000},
	{0x00008340, 0x000107ff},
	{0x00008344, 0xaa48107b},
	{0x00008348, 0x008f0000},
	{0x0000835c, 0x00000000},
	{0x00008360, 0xffffffff},
	{0x00008364, 0xffffffff},
	{0x00008368, 0x00000000},
	{0x00008370, 0x00000000},
	{0x00008374, 0x000000ff},
	{0x00008378, 0x00000000},
	{0x0000837c, 0x00000000},
	{0x00008380, 0xffffffff},
	{0x00008384, 0xffffffff},
	{0x00008390, 0xffffffff},
	{0x00008394, 0xffffffff},
	{0x00008398, 0x00000000},
	{0x0000839c, 0x00000000},
	{0x000083a0, 0x00000000},
	{0x000083a4, 0x0000fa14},
	{0x000083a8, 0x000f0c00},
	{0x000083ac, 0x33332210},
	{0x000083b0, 0x33332210},
	{0x000083b4, 0x33332210},
	{0x000083b8, 0x33332210},
	{0x000083bc, 0x00000000},
	{0x000083c0, 0x00000000},
	{0x000083c4, 0x00000000},
	{0x000083c8, 0x00000000},
	{0x000083cc, 0x00000200},
	{0x000083d0, 0x8c7901ff},
};

static const u32 ar955x_1p0_baseband_core[][2] = {
	/* Addr      allmodes  */
	{0x00009800, 0xafe68e30},
	{0x00009804, 0xfd14e000},
	{0x00009808, 0x9c0a9f6b},
	{0x0000980c, 0x04900000},
	{0x00009814, 0x0280c00a},
	{0x00009818, 0x00000000},
	{0x0000981c, 0x00020028},
	{0x00009834, 0x6400a190},
	{0x00009838, 0x0108ecff},
	{0x0000983c, 0x14000600},
	{0x00009880, 0x201fff00},
	{0x00009884, 0x00001042},
	{0x000098a4, 0x00200400},
	{0x000098b0, 0x32840bbe},
	{0x000098bc, 0x00000002},
	{0x000098d0, 0x004b6a8e},
	{0x000098d4, 0x00000820},
	{0x000098dc, 0x00000000},
	{0x000098f0, 0x00000000},
	{0x000098f4, 0x00000000},
	{0x00009c04, 0xff55ff55},
	{0x00009c08, 0x0320ff55},
	{0x00009c0c, 0x00000000},
	{0x00009c10, 0x00000000},
	{0x00009c14, 0x00046384},
	{0x00009c18, 0x05b6b440},
	{0x00009c1c, 0x00b6b440},
	{0x00009d00, 0xc080a333},
	{0x00009d04, 0x40206c10},
	{0x00009d08, 0x009c4060},
	{0x00009d0c, 0x9883800a},
	{0x00009d10, 0x01834061},
	{0x00009d14, 0x00c0040b},
	{0x00009d18, 0x00000000},
	{0x00009e08, 0x0038230c},
	{0x00009e24, 0x990bb515},
	{0x00009e28, 0x0c6f0000},
	{0x00009e30, 0x06336f77},
	{0x00009e34, 0x6af6532f},
	{0x00009e38, 0x0cc80c00},
	{0x00009e40, 0x0d261820},
	{0x00009e4c, 0x00001004},
	{0x00009e50, 0x00ff03f1},
	{0x00009fc0, 0x813e4788},
	{0x00009fc4, 0x0001efb5},
	{0x00009fcc, 0x40000014},
	{0x00009fd0, 0x01193b93},
	{0x0000a20c, 0x00000000},
	{0x0000a220, 0x00000000},
	{0x0000a224, 0x00000000},
	{0x0000a228, 0x10002310},
	{0x0000a23c, 0x00000000},
	{0x0000a244, 0x0c000000},
	{0x0000a248, 0x00000140},
	{0x0000a2a0, 0x00000007},
	{0x0000a2c0, 0x00000007},
	{0x0000a2c8, 0x00000000},
	{0x0000a2d4, 0x00000000},
	{0x0000a2ec, 0x00000000},
	{0x0000a2f0, 0x00000000},
	{0x0000a2f4, 0x00000000},
	{0x0000a2f8, 0x00000000},
	{0x0000a344, 0x00000000},
	{0x0000a34c, 0x00000000},
	{0x0000a350, 0x0000a000},
	{0x0000a364, 0x00000000},
	{0x0000a370, 0x00000000},
	{0x0000a390, 0x00000001},
	{0x0000a394, 0x00000444},
	{0x0000a398, 0x1f020503},
	{0x0000a39c, 0x29180c03},
	{0x0000a3a0, 0x9a8b6844},
	{0x0000a3a4, 0x00000000},
	{0x0000a3a8, 0xaaaaaaaa},
	{0x0000a3ac, 0x3c466478},
	{0x0000a3c0, 0x20202020},
	{0x0000a3c4, 0x22222220},
	{0x0000a3c8, 0x20200020},
	{0x0000a3cc, 0x20202020},
	{0x0000a3d0, 0x20202020},
	{0x0000a3d4, 0x20202020},
	{0x0000a3d8, 0x20202020},
	{0x0000a3dc, 0x20202020},
	{0x0000a3e0, 0x20202020},
	{0x0000a3e4, 0x20202020},
	{0x0000a3e8, 0x20202020},
	{0x0000a3ec, 0x20202020},
	{0x0000a3f0, 0x00000000},
	{0x0000a3f4, 0x00000000},
	{0x0000a3f8, 0x0c9bd380},
	{0x0000a3fc, 0x000f0f01},
	{0x0000a400, 0x8fa91f01},
	{0x0000a404, 0x00000000},
	{0x0000a408, 0x0e79e5c6},
	{0x0000a40c, 0x00820820},
	{0x0000a414, 0x1ce739ce},
	{0x0000a418, 0x2d001dce},
	{0x0000a41c, 0x1ce739ce},
	{0x0000a420, 0x000001ce},
	{0x0000a424, 0x1ce739ce},
	{0x0000a428, 0x000001ce},
	{0x0000a42c, 0x1ce739ce},
	{0x0000a430, 0x1ce739ce},
	{0x0000a434, 0x00000000},
	{0x0000a438, 0x00001801},
	{0x0000a43c, 0x00100000},
	{0x0000a444, 0x00000000},
	{0x0000a448, 0x05000080},
	{0x0000a44c, 0x00000001},
	{0x0000a450, 0x00010000},
	{0x0000a458, 0x00000000},
	{0x0000a644, 0xbfad9d74},
	{0x0000a648, 0x0048060a},
	{0x0000a64c, 0x00003c37},
	{0x0000a670, 0x03020100},
	{0x0000a674, 0x09080504},
	{0x0000a678, 0x0d0c0b0a},
	{0x0000a67c, 0x13121110},
	{0x0000a680, 0x31301514},
	{0x0000a684, 0x35343332},
	{0x0000a688, 0x00000036},
	{0x0000a690, 0x00000838},
	{0x0000a7cc, 0x00000000},
	{0x0000a7d0, 0x00000000},
	{0x0000a7d4, 0x00000004},
	{0x0000a7dc, 0x00000000},
	{0x0000a8d0, 0x004b6a8e},
	{0x0000a8d4, 0x00000820},
	{0x0000a8dc, 0x00000000},
	{0x0000a8f0, 0x00000000},
	{0x0000a8f4, 0x00000000},
	{0x0000b2d0, 0x00000080},
	{0x0000b2d4, 0x00000000},
	{0x0000b2ec, 0x00000000},
	{0x0000b2f0, 0x00000000},
	{0x0000b2f4, 0x00000000},
	{0x0000b2f8, 0x00000000},
	{0x0000b408, 0x0e79e5c0},
	{0x0000b40c, 0x00820820},
	{0x0000b420, 0x00000000},
	{0x0000b8d0, 0x004b6a8e},
	{0x0000b8d4, 0x00000820},
	{0x0000b8dc, 0x00000000},
	{0x0000b8f0, 0x00000000},
	{0x0000b8f4, 0x00000000},
	{0x0000c2d0, 0x00000080},
	{0x0000c2d4, 0x00000000},
	{0x0000c2ec, 0x00000000},
	{0x0000c2f0, 0x00000000},
	{0x0000c2f4, 0x00000000},
	{0x0000c2f8, 0x00000000},
	{0x0000c408, 0x0e79e5c0},
	{0x0000c40c, 0x00820820},
	{0x0000c420, 0x00000000},
};

static const u32 ar955x_1p0_soc_preamble[][2] = {
	/* Addr      allmodes  */
	{0x00007000, 0x00000000},
	{0x00007004, 0x00000000},
	{0x00007008, 0x00000000},
	{0x0000700c, 0x00000000},
	{0x0000701c, 0x00000000},
	{0x00007020, 0x00000000},
	{0x00007024, 0x00000000},
	{0x00007028, 0x00000000},
	{0x0000702c, 0x00000000},
	{0x00007030, 0x00000000},
	{0x00007034, 0x00000002},
	{0x00007038, 0x000004c2},
	{0x00007048, 0x00000000},
};

static const u32 ar955x_1p0_common_wo_xlna_rx_gain_bounds[][5] = {
	/* Addr      5G_HT20     5G_HT40     2G_HT40     2G_HT20   */
	{0x00009e44, 0xfe321e27, 0xfe321e27, 0xfe291e27, 0xfe291e27},
	{0x00009e48, 0x5030201a, 0x5030201a, 0x50302012, 0x50302012},
};

static const u32 ar955x_1p0_mac_postamble[][5] = {
	/* Addr      5G_HT20     5G_HT40     2G_HT40     2G_HT20   */
	{0x00001030, 0x00000230, 0x00000460, 0x000002c0, 0x00000160},
	{0x00001070, 0x00000168, 0x000002d0, 0x00000318, 0x0000018c},
	{0x000010b0, 0x00000e60, 0x00001cc0, 0x00007c70, 0x00003e38},
	{0x00008014, 0x03e803e8, 0x07d007d0, 0x10801600, 0x08400b00},
	{0x0000801c, 0x128d8027, 0x128d804f, 0x12e00057, 0x12e0002b},
	{0x00008120, 0x08f04800, 0x08f04800, 0x08f04810, 0x08f04810},
	{0x000081d0, 0x00003210, 0x00003210, 0x0000320a, 0x0000320a},
	{0x00008318, 0x00003e80, 0x00007d00, 0x00006880, 0x00003440},
};

static const u32 ar955x_1p0_common_rx_gain_bounds[][5] = {
	/* Addr      5G_HT20     5G_HT40     2G_HT40     2G_HT20   */
	{0x00009e44, 0xfe321e27, 0xfe321e27, 0xfe291e27, 0xfe291e27},
	{0x00009e48, 0x5030201a, 0x5030201a, 0x50302018, 0x50302018},
};

static const u32 ar955x_1p0_modes_no_xpa_tx_gain_table[][9] = {
	/* Addr      5G_HT20_L   5G_HT40_L   5G_HT20_M   5G_HT40_M   5G_HT20_H   5G_HT40_H   2G_HT40     2G_HT20  */
	{0x0000a2dc, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0xfffe5aaa, 0xfffe5aaa},
	{0x0000a2e0, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0xfffe9ccc, 0xfffe9ccc},
	{0x0000a2e4, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0xffffe0f0, 0xffffe0f0},
	{0x0000a2e8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffef00, 0xffffef00},
	{0x0000a410, 0x000050d8, 0x000050d8, 0x000050d8, 0x000050d8, 0x000050d8, 0x000050d8, 0x000050d7, 0x000050d7},
	{0x0000a500, 0x00002220, 0x00002220, 0x00002220, 0x00002220, 0x00002220, 0x00002220, 0x00000000, 0x00000000},
	{0x0000a504, 0x04002222, 0x04002222, 0x04002222, 0x04002222, 0x04002222, 0x04002222, 0x04000002, 0x04000002},
	{0x0000a508, 0x09002421, 0x09002421, 0x09002421, 0x09002421, 0x09002421, 0x09002421, 0x08000004, 0x08000004},
	{0x0000a50c, 0x0d002621, 0x0d002621, 0x0d002621, 0x0d002621, 0x0d002621, 0x0d002621, 0x0b000006, 0x0b000006},
	{0x0000a510, 0x13004620, 0x13004620, 0x13004620, 0x13004620, 0x13004620, 0x13004620, 0x0f00000a, 0x0f00000a},
	{0x0000a514, 0x19004a20, 0x19004a20, 0x19004a20, 0x19004a20, 0x19004a20, 0x19004a20, 0x1300000c, 0x1300000c},
	{0x0000a518, 0x1d004e20, 0x1d004e20, 0x1d004e20, 0x1d004e20, 0x1d004e20, 0x1d004e20, 0x1700000e, 0x1700000e},
	{0x0000a51c, 0x21005420, 0x21005420, 0x21005420, 0x21005420, 0x21005420, 0x21005420, 0x1b000012, 0x1b000012},
	{0x0000a520, 0x26005e20, 0x26005e20, 0x26005e20, 0x26005e20, 0x26005e20, 0x26005e20, 0x1f00004a, 0x1f00004a},
	{0x0000a524, 0x2b005e40, 0x2b005e40, 0x2b005e40, 0x2b005e40, 0x2b005e40, 0x2b005e40, 0x23000244, 0x23000244},
	{0x0000a528, 0x2f005e42, 0x2f005e42, 0x2f005e42, 0x2f005e42, 0x2f005e42, 0x2f005e42, 0x2700022b, 0x2700022b},
	{0x0000a52c, 0x33005e44, 0x33005e44, 0x33005e44, 0x33005e44, 0x33005e44, 0x33005e44, 0x2b000625, 0x2b000625},
	{0x0000a530, 0x38005e65, 0x38005e65, 0x38005e65, 0x38005e65, 0x38005e65, 0x38005e65, 0x2f001006, 0x2f001006},
	{0x0000a534, 0x3c005e69, 0x3c005e69, 0x3c005e69, 0x3c005e69, 0x3c005e69, 0x3c005e69, 0x330008a0, 0x330008a0},
	{0x0000a538, 0x40005e6b, 0x40005e6b, 0x40005e6b, 0x40005e6b, 0x40005e6b, 0x40005e6b, 0x37000a2a, 0x37000a2a},
	{0x0000a53c, 0x44005e6d, 0x44005e6d, 0x44005e6d, 0x44005e6d, 0x44005e6d, 0x44005e6d, 0x3b001c23, 0x3b001c23},
	{0x0000a540, 0x49005e72, 0x49005e72, 0x49005e72, 0x49005e72, 0x49005e72, 0x49005e72, 0x3f0014a0, 0x3f0014a0},
	{0x0000a544, 0x4e005eb2, 0x4e005eb2, 0x4e005eb2, 0x4e005eb2, 0x4e005eb2, 0x4e005eb2, 0x43001882, 0x43001882},
	{0x0000a548, 0x53005f12, 0x53005f12, 0x53005f12, 0x53005f12, 0x53005f12, 0x53005f12, 0x47001ca2, 0x47001ca2},
	{0x0000a54c, 0x59025eb2, 0x59025eb2, 0x59025eb2, 0x59025eb2, 0x59025eb2, 0x59025eb2, 0x4b001ec3, 0x4b001ec3},
	{0x0000a550, 0x5e025f12, 0x5e025f12, 0x5e025f12, 0x5e025f12, 0x5e025f12, 0x5e025f12, 0x4f00148c, 0x4f00148c},
	{0x0000a554, 0x61027f12, 0x61027f12, 0x61027f12, 0x61027f12, 0x61027f12, 0x61027f12, 0x53001c6e, 0x53001c6e},
	{0x0000a558, 0x6702bf12, 0x6702bf12, 0x6702bf12, 0x6702bf12, 0x6702bf12, 0x6702bf12, 0x57001c92, 0x57001c92},
	{0x0000a55c, 0x6b02bf14, 0x6b02bf14, 0x6b02bf14, 0x6b02bf14, 0x6b02bf14, 0x6b02bf14, 0x5c001af6, 0x5c001af6},
	{0x0000a560, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a564, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a568, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a56c, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a570, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a574, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a578, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a57c, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x6f02bf16, 0x5c001af6, 0x5c001af6},
	{0x0000a600, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a604, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a608, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a60c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000a610, 0x00804000, 0x00804000, 0x00804000, 0x00804000, 0x00804000, 0x00804000, 0x04005001, 0x04005001},
	{0x0000a614, 0x00804201, 0x00804201, 0x00804201, 0x00804201, 0x00804201, 0x00804201, 0x03808e02, 0x03808e02},
	{0x0000a618, 0x0280c802, 0x0280c802, 0x0280c802, 0x0280c802, 0x0280c802, 0x0280c802, 0x0300c000, 0x0300c000},
	{0x0000a61c, 0x0280ca03, 0x0280ca03, 0x0280ca03, 0x0280ca03, 0x0280ca03, 0x0280ca03, 0x03808e02, 0x03808e02},
	{0x0000a620, 0x04c15104, 0x04c15104, 0x04c15104, 0x04c15104, 0x04c15104, 0x04c15104, 0x03410c03, 0x03410c03},
	{0x0000a624, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04014c03, 0x04014c03},
	{0x0000a628, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x05818d04, 0x05818d04},
	{0x0000a62c, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x0801cd04, 0x0801cd04},
	{0x0000a630, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x0801e007, 0x0801e007},
	{0x0000a634, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x0801e007, 0x0801e007},
	{0x0000a638, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x0801e007, 0x0801e007},
	{0x0000a63c, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x04c15305, 0x0801e007, 0x0801e007},
	{0x0000b2dc, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0xfffe5aaa, 0xfffe5aaa},
	{0x0000b2e0, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0xfffe9ccc, 0xfffe9ccc},
	{0x0000b2e4, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0xffffe0f0, 0xffffe0f0},
	{0x0000b2e8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffef00, 0xffffef00},
	{0x0000c2dc, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0x01feee00, 0xfffe5aaa, 0xfffe5aaa},
	{0x0000c2e0, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0x0000f000, 0xfffe9ccc, 0xfffe9ccc},
	{0x0000c2e4, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0x01ff0000, 0xffffe0f0, 0xffffe0f0},
	{0x0000c2e8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffef00, 0xffffef00},
	{0x00016044, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x054922d4, 0x054922d4},
	{0x00016048, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401},
	{0x00016444, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x054922d4, 0x054922d4},
	{0x00016448, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401},
	{0x00016844, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x056db2d4, 0x054922d4, 0x054922d4},
	{0x00016848, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401, 0x66482401},
};

static const u32 ar955x_1p0_modes_fast_clock[][3] = {
	/* Addr      5G_HT20     5G_HT40   */
	{0x00001030, 0x00000268, 0x000004d0},
	{0x00001070, 0x0000018c, 0x00000318},
	{0x000010b0, 0x00000fd0, 0x00001fa0},
	{0x00008014, 0x044c044c, 0x08980898},
	{0x0000801c, 0x148ec02b, 0x148ec057},
	{0x00008318, 0x000044c0, 0x00008980},
	{0x00009e00, 0x0372131c, 0x0372131c},
	{0x0000a230, 0x0000400b, 0x00004016},
	{0x0000a254, 0x00000898, 0x00001130},
};

#endif /* INITVALS_955X_1P0_H */
