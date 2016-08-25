#include "niQueue.h"

void niQueue_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  niQueue__qt_3_data.randomize(&__rand_seed);
  niQueue__qt_2_data.randomize(&__rand_seed);
  niQueue__qt_1_data.randomize(&__rand_seed);
  niQueue__qt_0_data.randomize(&__rand_seed);
  niQueue__tx_dout_data.randomize(&__rand_seed);
  niQueue__qt_3_valid.randomize(&__rand_seed);
  niQueue__qt_2_valid.randomize(&__rand_seed);
  niQueue__qtHead.randomize(&__rand_seed);
  niQueue__qt_1_valid.randomize(&__rand_seed);
  niQueue__qtTail.randomize(&__rand_seed);
  niQueue__qt_0_valid.randomize(&__rand_seed);
  niQueue__tx_dout_valid.randomize(&__rand_seed);
  niQueue__reg_dir_data_dst.randomize(&__rand_seed);
  niQueue__reg_tx_dst.randomize(&__rand_seed);
  niQueue__qtPhitCount.randomize(&__rand_seed);
  niQueue__reg_slotCount.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int niQueue_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (!reset.to_bool()) print( std::cerr );
  mod_t::dump( reset );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void niQueue_t::print ( FILE* f ) {
}
void niQueue_t::print ( std::ostream& s ) {
}


void niQueue_t::dump_init ( FILE* f ) {
  fputs("$timescale 1ps $end\n", f);
  fputs("$scope module niQueue $end\n", f);
  fputs("$var wire 1 \x21 clk $end\n", f);
  fputs("$var wire 1 \x22 reset $end\n", f);
  fputs("$var wire 1 \x23 io_ipNI_io_ip_rtw $end\n", f);
  fputs("$var wire 1 \x24 qt_3_valid $end\n", f);
  fputs("$var wire 1 \x25 qt_2_valid $end\n", f);
  fputs("$var wire 1 \x26 qt_1_valid $end\n", f);
  fputs("$var wire 1 \x27 qt_0_valid $end\n", f);
  fputs("$var wire 1 \x28 tx_dout_valid $end\n", f);
  fputs("$var wire 1 \x29 io_r_lc_dout_valid $end\n", f);
  fputs("$var wire 1 \x2a io_ipNI_io_ip_ack $end\n", f);
  fputs("$var wire 1 \x2b io_ipNI_io_ip_qtBusy $end\n", f);
  fputs("$var wire 1 \x2c io_dir_read $end\n", f);
  fputs("$var wire 1 \x2d io_ipNI_io_router_tx $end\n", f);
  fputs("$var wire 1 \x2e valid $end\n", f);
  fputs("$var wire 2 \x2f qtHead $end\n", f);
  fputs("$var wire 2 \x30 qtTail $end\n", f);
  fputs("$var wire 3 \x31 qtPhitCount $end\n", f);
  fputs("$var wire 4 \x32 io_dir_rdData_dst $end\n", f);
  fputs("$var wire 4 \x33 reg_dir_data_dst $end\n", f);
  fputs("$var wire 4 \x34 io_ipNI_io_ip_addr $end\n", f);
  fputs("$var wire 4 \x35 reg_tx_dst $end\n", f);
  fputs("$var wire 4 \x36 io_dir_rdData_src $end\n", f);
  fputs("$var wire 19 \x37 reg_slotCount $end\n", f);
  fputs("$var wire 20 \x38 io_dir_rdAddr $end\n", f);
  fputs("$var wire 32 \x39 io_ipNI_io_ip_din $end\n", f);
  fputs("$var wire 32 \x3a qt_3_data $end\n", f);
  fputs("$var wire 32 \x3b qt_2_data $end\n", f);
  fputs("$var wire 32 \x3c qt_1_data $end\n", f);
  fputs("$var wire 32 \x3d qt_0_data $end\n", f);
  fputs("$var wire 32 \x3e tx_dout_data $end\n", f);
  fputs("$var wire 32 \x3f io_r_lc_dout_data $end\n", f);
  fputs("$var wire 32 \x40 io_ipNI_io_ip_dout $end\n", f);
  fputs("$var wire 32 \x41 data $end\n", f);
  fputs("$upscope $end\n", f);
  fputs("$enddefinitions $end\n", f);
  fputs("$dumpvars\n", f);
  fputs("$end\n", f);
  fputs("#0\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 1;
    dat_dump<1>(f, clk, 0x21);
  }
  dat_t<1> reset = LIT<1>(1);
  dat_dump<1>(f, reset, 0x22);
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_rtw, 0x23);
  niQueue__io_ipNI_io_ip_rtw__prev = niQueue__io_ipNI_io_ip_rtw;
  dat_dump<1>(f, niQueue__qt_3_valid, 0x24);
  niQueue__qt_3_valid__prev = niQueue__qt_3_valid;
  dat_dump<1>(f, niQueue__qt_2_valid, 0x25);
  niQueue__qt_2_valid__prev = niQueue__qt_2_valid;
  dat_dump<1>(f, niQueue__qt_1_valid, 0x26);
  niQueue__qt_1_valid__prev = niQueue__qt_1_valid;
  dat_dump<1>(f, niQueue__qt_0_valid, 0x27);
  niQueue__qt_0_valid__prev = niQueue__qt_0_valid;
  dat_dump<1>(f, niQueue__tx_dout_valid, 0x28);
  niQueue__tx_dout_valid__prev = niQueue__tx_dout_valid;
  dat_dump<1>(f, niQueue__io_r_lc_dout_valid, 0x29);
  niQueue__io_r_lc_dout_valid__prev = niQueue__io_r_lc_dout_valid;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_ack, 0x2a);
  niQueue__io_ipNI_io_ip_ack__prev = niQueue__io_ipNI_io_ip_ack;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_qtBusy, 0x2b);
  niQueue__io_ipNI_io_ip_qtBusy__prev = niQueue__io_ipNI_io_ip_qtBusy;
  dat_dump<1>(f, niQueue__io_dir_read, 0x2c);
  niQueue__io_dir_read__prev = niQueue__io_dir_read;
  dat_dump<1>(f, niQueue__io_ipNI_io_router_tx, 0x2d);
  niQueue__io_ipNI_io_router_tx__prev = niQueue__io_ipNI_io_router_tx;
  dat_dump<1>(f, niQueue__io_r_lc_din__valid, 0x2e);
  niQueue__io_r_lc_din__valid__prev = niQueue__io_r_lc_din__valid;
  dat_dump<1>(f, niQueue__qtHead, 0x2f);
  niQueue__qtHead__prev = niQueue__qtHead;
  dat_dump<1>(f, niQueue__qtTail, 0x30);
  niQueue__qtTail__prev = niQueue__qtTail;
  dat_dump<1>(f, niQueue__qtPhitCount, 0x31);
  niQueue__qtPhitCount__prev = niQueue__qtPhitCount;
  dat_dump<1>(f, niQueue__io_dir_rdData_dst, 0x32);
  niQueue__io_dir_rdData_dst__prev = niQueue__io_dir_rdData_dst;
  dat_dump<1>(f, niQueue__reg_dir_data_dst, 0x33);
  niQueue__reg_dir_data_dst__prev = niQueue__reg_dir_data_dst;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_addr, 0x34);
  niQueue__io_ipNI_io_ip_addr__prev = niQueue__io_ipNI_io_ip_addr;
  dat_dump<1>(f, niQueue__reg_tx_dst, 0x35);
  niQueue__reg_tx_dst__prev = niQueue__reg_tx_dst;
  dat_dump<1>(f, niQueue__io_dir_rdData_src, 0x36);
  niQueue__io_dir_rdData_src__prev = niQueue__io_dir_rdData_src;
  dat_dump<1>(f, niQueue__reg_slotCount, 0x37);
  niQueue__reg_slotCount__prev = niQueue__reg_slotCount;
  dat_dump<1>(f, niQueue__io_dir_rdAddr, 0x38);
  niQueue__io_dir_rdAddr__prev = niQueue__io_dir_rdAddr;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_din, 0x39);
  niQueue__io_ipNI_io_ip_din__prev = niQueue__io_ipNI_io_ip_din;
  dat_dump<1>(f, niQueue__qt_3_data, 0x3a);
  niQueue__qt_3_data__prev = niQueue__qt_3_data;
  dat_dump<1>(f, niQueue__qt_2_data, 0x3b);
  niQueue__qt_2_data__prev = niQueue__qt_2_data;
  dat_dump<1>(f, niQueue__qt_1_data, 0x3c);
  niQueue__qt_1_data__prev = niQueue__qt_1_data;
  dat_dump<1>(f, niQueue__qt_0_data, 0x3d);
  niQueue__qt_0_data__prev = niQueue__qt_0_data;
  dat_dump<1>(f, niQueue__tx_dout_data, 0x3e);
  niQueue__tx_dout_data__prev = niQueue__tx_dout_data;
  dat_dump<1>(f, niQueue__io_r_lc_dout_data, 0x3f);
  niQueue__io_r_lc_dout_data__prev = niQueue__io_r_lc_dout_data;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_dout, 0x40);
  niQueue__io_ipNI_io_ip_dout__prev = niQueue__io_ipNI_io_ip_dout;
  dat_dump<1>(f, niQueue__io_r_lc_din__data, 0x41);
  niQueue__io_r_lc_din__data__prev = niQueue__io_r_lc_din__data;
  fputs("#1\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 0;
    dat_dump<1>(f, clk, 0x21);
  }
}


void niQueue_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
  if (t == 0L) return dump_init(f);
  fprintf(f, "#%lu\n", t << 1);
  if (clk.cnt == 0)  goto L0;
K0:  if (reset != reset__prev)  goto L1;
K1:  if (niQueue__io_ipNI_io_ip_rtw != niQueue__io_ipNI_io_ip_rtw__prev)  goto L2;
K2:  if (niQueue__qt_3_valid != niQueue__qt_3_valid__prev)  goto L3;
K3:  if (niQueue__qt_2_valid != niQueue__qt_2_valid__prev)  goto L4;
K4:  if (niQueue__qt_1_valid != niQueue__qt_1_valid__prev)  goto L5;
K5:  if (niQueue__qt_0_valid != niQueue__qt_0_valid__prev)  goto L6;
K6:  if (niQueue__tx_dout_valid != niQueue__tx_dout_valid__prev)  goto L7;
K7:  if (niQueue__io_r_lc_dout_valid != niQueue__io_r_lc_dout_valid__prev)  goto L8;
K8:  if (niQueue__io_ipNI_io_ip_ack != niQueue__io_ipNI_io_ip_ack__prev)  goto L9;
K9:  if (niQueue__io_ipNI_io_ip_qtBusy != niQueue__io_ipNI_io_ip_qtBusy__prev)  goto L10;
K10:  if (niQueue__io_dir_read != niQueue__io_dir_read__prev)  goto L11;
K11:  if (niQueue__io_ipNI_io_router_tx != niQueue__io_ipNI_io_router_tx__prev)  goto L12;
K12:  if (niQueue__io_r_lc_din__valid != niQueue__io_r_lc_din__valid__prev)  goto L13;
K13:  if (niQueue__qtHead != niQueue__qtHead__prev)  goto L14;
K14:  if (niQueue__qtTail != niQueue__qtTail__prev)  goto L15;
K15:  if (niQueue__qtPhitCount != niQueue__qtPhitCount__prev)  goto L16;
K16:  if (niQueue__io_dir_rdData_dst != niQueue__io_dir_rdData_dst__prev)  goto L17;
K17:  if (niQueue__reg_dir_data_dst != niQueue__reg_dir_data_dst__prev)  goto L18;
K18:  if (niQueue__io_ipNI_io_ip_addr != niQueue__io_ipNI_io_ip_addr__prev)  goto L19;
K19:  if (niQueue__reg_tx_dst != niQueue__reg_tx_dst__prev)  goto L20;
K20:  if (niQueue__io_dir_rdData_src != niQueue__io_dir_rdData_src__prev)  goto L21;
K21:  if (niQueue__reg_slotCount != niQueue__reg_slotCount__prev)  goto L22;
K22:  if (niQueue__io_dir_rdAddr != niQueue__io_dir_rdAddr__prev)  goto L23;
K23:  if (niQueue__io_ipNI_io_ip_din != niQueue__io_ipNI_io_ip_din__prev)  goto L24;
K24:  if (niQueue__qt_3_data != niQueue__qt_3_data__prev)  goto L25;
K25:  if (niQueue__qt_2_data != niQueue__qt_2_data__prev)  goto L26;
K26:  if (niQueue__qt_1_data != niQueue__qt_1_data__prev)  goto L27;
K27:  if (niQueue__qt_0_data != niQueue__qt_0_data__prev)  goto L28;
K28:  if (niQueue__tx_dout_data != niQueue__tx_dout_data__prev)  goto L29;
K29:  if (niQueue__io_r_lc_dout_data != niQueue__io_r_lc_dout_data__prev)  goto L30;
K30:  if (niQueue__io_ipNI_io_ip_dout != niQueue__io_ipNI_io_ip_dout__prev)  goto L31;
K31:  if (niQueue__io_r_lc_din__data != niQueue__io_r_lc_din__data__prev)  goto L32;
K32:  fprintf(f, "#%lu\n", (t << 1) + 1);
  if (clk.cnt == 0)  goto Z0;
C0:  return;
L0:
  clk.values[0] = 1;
  dat_dump<1>(f, clk, 0x21);
  goto K0;
L1:
  reset__prev = reset;
  dat_dump<1>(f, reset, 0x22);
  goto K1;
L2:
  niQueue__io_ipNI_io_ip_rtw__prev = niQueue__io_ipNI_io_ip_rtw;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_rtw, 0x23);
  goto K2;
L3:
  niQueue__qt_3_valid__prev = niQueue__qt_3_valid;
  dat_dump<1>(f, niQueue__qt_3_valid, 0x24);
  goto K3;
L4:
  niQueue__qt_2_valid__prev = niQueue__qt_2_valid;
  dat_dump<1>(f, niQueue__qt_2_valid, 0x25);
  goto K4;
L5:
  niQueue__qt_1_valid__prev = niQueue__qt_1_valid;
  dat_dump<1>(f, niQueue__qt_1_valid, 0x26);
  goto K5;
L6:
  niQueue__qt_0_valid__prev = niQueue__qt_0_valid;
  dat_dump<1>(f, niQueue__qt_0_valid, 0x27);
  goto K6;
L7:
  niQueue__tx_dout_valid__prev = niQueue__tx_dout_valid;
  dat_dump<1>(f, niQueue__tx_dout_valid, 0x28);
  goto K7;
L8:
  niQueue__io_r_lc_dout_valid__prev = niQueue__io_r_lc_dout_valid;
  dat_dump<1>(f, niQueue__io_r_lc_dout_valid, 0x29);
  goto K8;
L9:
  niQueue__io_ipNI_io_ip_ack__prev = niQueue__io_ipNI_io_ip_ack;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_ack, 0x2a);
  goto K9;
L10:
  niQueue__io_ipNI_io_ip_qtBusy__prev = niQueue__io_ipNI_io_ip_qtBusy;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_qtBusy, 0x2b);
  goto K10;
L11:
  niQueue__io_dir_read__prev = niQueue__io_dir_read;
  dat_dump<1>(f, niQueue__io_dir_read, 0x2c);
  goto K11;
L12:
  niQueue__io_ipNI_io_router_tx__prev = niQueue__io_ipNI_io_router_tx;
  dat_dump<1>(f, niQueue__io_ipNI_io_router_tx, 0x2d);
  goto K12;
L13:
  niQueue__io_r_lc_din__valid__prev = niQueue__io_r_lc_din__valid;
  dat_dump<1>(f, niQueue__io_r_lc_din__valid, 0x2e);
  goto K13;
L14:
  niQueue__qtHead__prev = niQueue__qtHead;
  dat_dump<1>(f, niQueue__qtHead, 0x2f);
  goto K14;
L15:
  niQueue__qtTail__prev = niQueue__qtTail;
  dat_dump<1>(f, niQueue__qtTail, 0x30);
  goto K15;
L16:
  niQueue__qtPhitCount__prev = niQueue__qtPhitCount;
  dat_dump<1>(f, niQueue__qtPhitCount, 0x31);
  goto K16;
L17:
  niQueue__io_dir_rdData_dst__prev = niQueue__io_dir_rdData_dst;
  dat_dump<1>(f, niQueue__io_dir_rdData_dst, 0x32);
  goto K17;
L18:
  niQueue__reg_dir_data_dst__prev = niQueue__reg_dir_data_dst;
  dat_dump<1>(f, niQueue__reg_dir_data_dst, 0x33);
  goto K18;
L19:
  niQueue__io_ipNI_io_ip_addr__prev = niQueue__io_ipNI_io_ip_addr;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_addr, 0x34);
  goto K19;
L20:
  niQueue__reg_tx_dst__prev = niQueue__reg_tx_dst;
  dat_dump<1>(f, niQueue__reg_tx_dst, 0x35);
  goto K20;
L21:
  niQueue__io_dir_rdData_src__prev = niQueue__io_dir_rdData_src;
  dat_dump<1>(f, niQueue__io_dir_rdData_src, 0x36);
  goto K21;
L22:
  niQueue__reg_slotCount__prev = niQueue__reg_slotCount;
  dat_dump<1>(f, niQueue__reg_slotCount, 0x37);
  goto K22;
L23:
  niQueue__io_dir_rdAddr__prev = niQueue__io_dir_rdAddr;
  dat_dump<1>(f, niQueue__io_dir_rdAddr, 0x38);
  goto K23;
L24:
  niQueue__io_ipNI_io_ip_din__prev = niQueue__io_ipNI_io_ip_din;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_din, 0x39);
  goto K24;
L25:
  niQueue__qt_3_data__prev = niQueue__qt_3_data;
  dat_dump<1>(f, niQueue__qt_3_data, 0x3a);
  goto K25;
L26:
  niQueue__qt_2_data__prev = niQueue__qt_2_data;
  dat_dump<1>(f, niQueue__qt_2_data, 0x3b);
  goto K26;
L27:
  niQueue__qt_1_data__prev = niQueue__qt_1_data;
  dat_dump<1>(f, niQueue__qt_1_data, 0x3c);
  goto K27;
L28:
  niQueue__qt_0_data__prev = niQueue__qt_0_data;
  dat_dump<1>(f, niQueue__qt_0_data, 0x3d);
  goto K28;
L29:
  niQueue__tx_dout_data__prev = niQueue__tx_dout_data;
  dat_dump<1>(f, niQueue__tx_dout_data, 0x3e);
  goto K29;
L30:
  niQueue__io_r_lc_dout_data__prev = niQueue__io_r_lc_dout_data;
  dat_dump<1>(f, niQueue__io_r_lc_dout_data, 0x3f);
  goto K30;
L31:
  niQueue__io_ipNI_io_ip_dout__prev = niQueue__io_ipNI_io_ip_dout;
  dat_dump<1>(f, niQueue__io_ipNI_io_ip_dout, 0x40);
  goto K31;
L32:
  niQueue__io_r_lc_din__data__prev = niQueue__io_r_lc_din__data;
  dat_dump<1>(f, niQueue__io_r_lc_din__data, 0x41);
  goto K32;
Z0:
  clk.values[0] = 0;
  dat_dump<1>(f, clk, 0x21);
  goto C0;
}




void niQueue_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  val_t T0;
  T0 = 0x1L << niQueue__qtTail.values[0];
  T0 = T0 & 0xfL;
  val_t T1;
  T1 = (T0 >> 3) & 1;
  val_t T2;
  T2 = niQueue__qtPhitCount.values[0] == 0x4L;
  val_t T3;
  { T3 = T2 ^ 0x1L;}
  val_t T4;
  { T4 = niQueue__io_ipNI_io_ip_rtw.values[0] & T3;}
  val_t T5;
  { T5 = T4 & T1;}
  val_t T6;
  { T6 = TERNARY_1(T5, niQueue__io_ipNI_io_ip_din.values[0], niQueue__qt_3_data.values[0]);}
  { T7.values[0] = TERNARY(reset.values[0], 0x0L, T6);}
  val_t T8;
  T8 = (T0 >> 2) & 1;
  val_t T9;
  { T9 = T4 & T8;}
  val_t T10;
  { T10 = TERNARY_1(T9, niQueue__io_ipNI_io_ip_din.values[0], niQueue__qt_2_data.values[0]);}
  { T11.values[0] = TERNARY(reset.values[0], 0x0L, T10);}
  val_t T12;
  T12 = (T0 >> 1) & 1;
  val_t T13;
  { T13 = T4 & T12;}
  val_t T14;
  { T14 = TERNARY_1(T13, niQueue__io_ipNI_io_ip_din.values[0], niQueue__qt_1_data.values[0]);}
  { T15.values[0] = TERNARY(reset.values[0], 0x0L, T14);}
  val_t T16;
  T16 = (T0 >> 0) & 1;
  val_t T17;
  { T17 = T4 & T16;}
  val_t T18;
  { T18 = TERNARY_1(T17, niQueue__io_ipNI_io_ip_din.values[0], niQueue__qt_0_data.values[0]);}
  { T19.values[0] = TERNARY(reset.values[0], 0x0L, T18);}
  val_t T20;
  T20 = (niQueue__qtHead.values[0] >> 0) & 1;
  val_t T21;
  { T21 = TERNARY_1(T20, niQueue__qt_1_data.values[0], niQueue__qt_0_data.values[0]);}
  val_t T22;
  T22 = (niQueue__qtHead.values[0] >> 0) & 1;
  val_t T23;
  { T23 = TERNARY_1(T22, niQueue__qt_3_data.values[0], niQueue__qt_2_data.values[0]);}
  val_t T24;
  T24 = (niQueue__qtHead.values[0] >> 1) & 1;
  val_t T25;
  { T25 = TERNARY_1(T24, T23, T21);}
  val_t T26;
  T26 = niQueue__qtPhitCount.values[0] == 0x0L;
  val_t T27;
  { T27 = T26 ^ 0x1L;}
  val_t T28;
  T28 = niQueue__reg_dir_data_dst.values[0] == niQueue__reg_tx_dst.values[0];
  val_t T29;
  { T29 = T28 & T27;}
  val_t T30;
  { T30 = TERNARY_1(T29, T25, niQueue__tx_dout_data.values[0]);}
  { T31.values[0] = TERNARY(reset.values[0], 0x0L, T30);}
  { niQueue__io_r_lc_dout_data.values[0] = niQueue__tx_dout_data.values[0];}
  val_t T32;
  { T32 = T4 & T1;}
  val_t T33;
  { T33 = TERNARY(T32, 0x1L, niQueue__qt_3_valid.values[0]);}
  { T34.values[0] = TERNARY(reset.values[0], 0x0L, T33);}
  val_t T35;
  { T35 = T4 & T8;}
  val_t T36;
  { T36 = TERNARY(T35, 0x1L, niQueue__qt_2_valid.values[0]);}
  { T37.values[0] = TERNARY(reset.values[0], 0x0L, T36);}
  val_t T38;
  { T38 = niQueue__qtHead.values[0]+0x1L;}
  T38 = T38 & 0x3L;
  val_t T39;
  { T39 = niQueue__qtHead.values[0] | 0x0L << 2;}
  val_t T40;
  T40 = T39 == 0x4L;
  val_t T41;
  { T41 = TERNARY(T40, 0x0L, T38);}
  val_t T42;
  { T42 = TERNARY_1(T29, T41, niQueue__qtHead.values[0]);}
  { T43.values[0] = TERNARY(reset.values[0], 0x0L, T42);}
  val_t T44;
  { T44 = T4 & T12;}
  val_t T45;
  { T45 = TERNARY(T44, 0x1L, niQueue__qt_1_valid.values[0]);}
  { T46.values[0] = TERNARY(reset.values[0], 0x0L, T45);}
  val_t T47;
  { T47 = niQueue__qtTail.values[0]+0x1L;}
  T47 = T47 & 0x3L;
  val_t T48;
  { T48 = niQueue__qtTail.values[0] | 0x0L << 2;}
  val_t T49;
  T49 = T48 == 0x4L;
  val_t T50;
  { T50 = TERNARY(T49, 0x0L, T47);}
  val_t T51;
  { T51 = TERNARY_1(T4, T50, niQueue__qtTail.values[0]);}
  { T52.values[0] = TERNARY(reset.values[0], 0x0L, T51);}
  val_t T53;
  { T53 = T4 & T16;}
  val_t T54;
  { T54 = TERNARY(T53, 0x1L, niQueue__qt_0_valid.values[0]);}
  { T55.values[0] = TERNARY(reset.values[0], 0x0L, T54);}
  val_t T56;
  T56 = (niQueue__qtHead.values[0] >> 0) & 1;
  val_t T57;
  { T57 = TERNARY_1(T56, niQueue__qt_1_valid.values[0], niQueue__qt_0_valid.values[0]);}
  val_t T58;
  T58 = (niQueue__qtHead.values[0] >> 0) & 1;
  val_t T59;
  { T59 = TERNARY_1(T58, niQueue__qt_3_valid.values[0], niQueue__qt_2_valid.values[0]);}
  val_t T60;
  T60 = (niQueue__qtHead.values[0] >> 1) & 1;
  val_t T61;
  { T61 = TERNARY_1(T60, T59, T57);}
  val_t T62;
  { T62 = TERNARY_1(T29, T61, niQueue__tx_dout_valid.values[0]);}
  { T63.values[0] = TERNARY(reset.values[0], 0x0L, T62);}
  { niQueue__io_r_lc_dout_valid.values[0] = niQueue__tx_dout_valid.values[0];}
  { val_t __r = this->__rand_val(); niQueue__io_ipNI_io_ip_ack.values[0] = __r;}
  niQueue__io_ipNI_io_ip_ack.values[0] = niQueue__io_ipNI_io_ip_ack.values[0] & 0x1L;
  { T64.values[0] = TERNARY(reset.values[0], 0x0L, niQueue__io_dir_rdData_dst.values[0]);}
  { T65.values[0] = TERNARY(reset.values[0], 0x0L, niQueue__io_ipNI_io_ip_addr.values[0]);}
  val_t T66;
  { T66 = niQueue__qtPhitCount.values[0]+0x1L;}
  T66 = T66 & 0x7L;
  val_t T67;
  { T67 = T29 ^ 0x1L;}
  val_t T68;
  { T68 = T4 & T67;}
  val_t T69;
  { T69 = TERNARY_1(T68, T66, niQueue__qtPhitCount.values[0]);}
  val_t T70;
  { T70 = niQueue__qtPhitCount.values[0]-0x1L;}
  T70 = T70 & 0x7L;
  val_t T71;
  { T71 = T4 ^ 0x1L;}
  val_t T72;
  { T72 = T71 & T29;}
  val_t T73;
  { T73 = T68 ^ 0x1L;}
  val_t T74;
  { T74 = T73 & T72;}
  val_t T75;
  { T75 = TERNARY_1(T74, T70, T69);}
  { T76.values[0] = TERNARY(reset.values[0], 0x0L, T75);}
  { niQueue__io_ipNI_io_ip_qtBusy.values[0] = T2;}
  { val_t __r = this->__rand_val(); niQueue__io_ipNI_io_ip_dout.values[0] = __r;}
  niQueue__io_ipNI_io_ip_dout.values[0] = niQueue__io_ipNI_io_ip_dout.values[0] & 0xffffffffL;
  val_t T77;
  { T77 = niQueue__reg_slotCount.values[0]+0x1L;}
  T77 = T77 & 0x7ffffL;
  { T78.values[0] = TERNARY(reset.values[0], 0x0L, T77);}
  val_t T79;
  { T79 = niQueue__reg_slotCount.values[0] | 0x0L << 19;}
  { niQueue__io_dir_rdAddr.values[0] = T79;}
  { niQueue__io_dir_read.values[0] = 0x1L;}
}


void niQueue_t::clock_hi ( dat_t<1> reset ) {
  dat_t<32> niQueue__qt_3_data__shadow = T7;
  dat_t<32> niQueue__qt_2_data__shadow = T11;
  dat_t<32> niQueue__qt_1_data__shadow = T15;
  dat_t<32> niQueue__qt_0_data__shadow = T19;
  dat_t<32> niQueue__tx_dout_data__shadow = T31;
  dat_t<1> niQueue__qt_3_valid__shadow = T34;
  dat_t<1> niQueue__qt_2_valid__shadow = T37;
  dat_t<2> niQueue__qtHead__shadow = T43;
  dat_t<1> niQueue__qt_1_valid__shadow = T46;
  dat_t<2> niQueue__qtTail__shadow = T52;
  dat_t<1> niQueue__qt_0_valid__shadow = T55;
  dat_t<1> niQueue__tx_dout_valid__shadow = T63;
  dat_t<4> niQueue__reg_dir_data_dst__shadow = T64;
  dat_t<4> niQueue__reg_tx_dst__shadow = T65;
  dat_t<3> niQueue__qtPhitCount__shadow = T76;
  dat_t<19> niQueue__reg_slotCount__shadow = T78;
  niQueue__qt_3_data = T7;
  niQueue__qt_2_data = T11;
  niQueue__qt_1_data = T15;
  niQueue__qt_0_data = T19;
  niQueue__tx_dout_data = T31;
  niQueue__qt_3_valid = T34;
  niQueue__qt_2_valid = T37;
  niQueue__qtHead = T43;
  niQueue__qt_1_valid = T46;
  niQueue__qtTail = T52;
  niQueue__qt_0_valid = T55;
  niQueue__tx_dout_valid = T63;
  niQueue__reg_dir_data_dst = T64;
  niQueue__reg_tx_dst = T65;
  niQueue__qtPhitCount = T76;
  niQueue__reg_slotCount = T78;
}


void niQueue_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  niQueue_t* mod = dynamic_cast<niQueue_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<32>(&mod->niQueue__io_r_lc_din__data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->niQueue__io_r_lc_din__valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->niQueue__io_ipNI_io_ip_din));
  sim_data.inputs.push_back(new dat_api<1>(&mod->niQueue__io_ipNI_io_router_tx));
  sim_data.inputs.push_back(new dat_api<1>(&mod->niQueue__io_ipNI_io_ip_rtw));
  sim_data.inputs.push_back(new dat_api<4>(&mod->niQueue__io_ipNI_io_ip_addr));
  sim_data.inputs.push_back(new dat_api<4>(&mod->niQueue__io_dir_rdData_src));
  sim_data.inputs.push_back(new dat_api<4>(&mod->niQueue__io_dir_rdData_dst));
  sim_data.outputs.push_back(new dat_api<32>(&mod->niQueue__io_r_lc_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->niQueue__io_r_lc_dout_valid));
  sim_data.outputs.push_back(new dat_api<1>(&mod->niQueue__io_ipNI_io_ip_ack));
  sim_data.outputs.push_back(new dat_api<1>(&mod->niQueue__io_ipNI_io_ip_qtBusy));
  sim_data.outputs.push_back(new dat_api<32>(&mod->niQueue__io_ipNI_io_ip_dout));
  sim_data.outputs.push_back(new dat_api<20>(&mod->niQueue__io_dir_rdAddr));
  sim_data.outputs.push_back(new dat_api<1>(&mod->niQueue__io_dir_read));
  sim_data.signals.push_back(new dat_api<32>(&mod->niQueue__qt_3_data));
  sim_data.signal_map["niQueue.qt_3_data"] = 0;
  sim_data.signals.push_back(new dat_api<32>(&mod->niQueue__qt_2_data));
  sim_data.signal_map["niQueue.qt_2_data"] = 1;
  sim_data.signals.push_back(new dat_api<32>(&mod->niQueue__qt_1_data));
  sim_data.signal_map["niQueue.qt_1_data"] = 2;
  sim_data.signals.push_back(new dat_api<32>(&mod->niQueue__qt_0_data));
  sim_data.signal_map["niQueue.qt_0_data"] = 3;
  sim_data.signals.push_back(new dat_api<32>(&mod->niQueue__tx_dout_data));
  sim_data.signal_map["niQueue.tx_dout_data"] = 4;
  sim_data.signals.push_back(new dat_api<1>(&mod->niQueue__qt_3_valid));
  sim_data.signal_map["niQueue.qt_3_valid"] = 5;
  sim_data.signals.push_back(new dat_api<1>(&mod->niQueue__qt_2_valid));
  sim_data.signal_map["niQueue.qt_2_valid"] = 6;
  sim_data.signals.push_back(new dat_api<2>(&mod->niQueue__qtHead));
  sim_data.signal_map["niQueue.qtHead"] = 7;
  sim_data.signals.push_back(new dat_api<1>(&mod->niQueue__qt_1_valid));
  sim_data.signal_map["niQueue.qt_1_valid"] = 8;
  sim_data.signals.push_back(new dat_api<2>(&mod->niQueue__qtTail));
  sim_data.signal_map["niQueue.qtTail"] = 9;
  sim_data.signals.push_back(new dat_api<1>(&mod->niQueue__qt_0_valid));
  sim_data.signal_map["niQueue.qt_0_valid"] = 10;
  sim_data.signals.push_back(new dat_api<1>(&mod->niQueue__tx_dout_valid));
  sim_data.signal_map["niQueue.tx_dout_valid"] = 11;
  sim_data.signals.push_back(new dat_api<4>(&mod->niQueue__reg_dir_data_dst));
  sim_data.signal_map["niQueue.reg_dir_data_dst"] = 12;
  sim_data.signals.push_back(new dat_api<4>(&mod->niQueue__reg_tx_dst));
  sim_data.signal_map["niQueue.reg_tx_dst"] = 13;
  sim_data.signals.push_back(new dat_api<3>(&mod->niQueue__qtPhitCount));
  sim_data.signal_map["niQueue.qtPhitCount"] = 14;
  sim_data.signals.push_back(new dat_api<19>(&mod->niQueue__reg_slotCount));
  sim_data.signal_map["niQueue.reg_slotCount"] = 15;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
