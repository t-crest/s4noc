#include "NiBox.h"

void NiBox_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  NiBox_control_ni__qt_3_data.randomize(&__rand_seed);
  NiBox_control_ni__qt_2_data.randomize(&__rand_seed);
  NiBox_control_ni__qt_1_data.randomize(&__rand_seed);
  NiBox_control_ni__qt_0_data.randomize(&__rand_seed);
  NiBox_control_ni__tx_dout_data.randomize(&__rand_seed);
  NiBox_control_ni__qt_3_valid.randomize(&__rand_seed);
  NiBox_control_ni__qt_2_valid.randomize(&__rand_seed);
  NiBox_control_ni__qtHead.randomize(&__rand_seed);
  NiBox_control_ni__qt_1_valid.randomize(&__rand_seed);
  NiBox_control_ni__qtTail.randomize(&__rand_seed);
  NiBox_control_ni__qt_0_valid.randomize(&__rand_seed);
  NiBox_control_ni__tx_dout_valid.randomize(&__rand_seed);
  NiBox_control_ni__reg_dir_data_dst.randomize(&__rand_seed);
  NiBox_control_ni__reg_tx_dst.randomize(&__rand_seed);
  NiBox_control_ni__qtPhitCount.randomize(&__rand_seed);
  NiBox_control_ni__reg_slotCount.randomize(&__rand_seed);
  NiBox_schedule_ni__rdAddrReg.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int NiBox_t::clock ( dat_t<1> reset ) {
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


void NiBox_t::print ( FILE* f ) {
}
void NiBox_t::print ( std::ostream& s ) {
}


void NiBox_t::dump_init ( FILE* f ) {
  fputs("$timescale 1ps $end\n", f);
  fputs("$scope module NiBox $end\n", f);
  fputs("$var wire 1 \x21 clk $end\n", f);
  fputs("$var wire 1 \x22 reset $end\n", f);
  fputs("$var wire 1 \x23 io_core_io_ip_rtw $end\n", f);
  fputs("$var wire 1 \x2e io_core_io_ip_ack $end\n", f);
  fputs("$var wire 1 \x30 io_core_io_ip_qtBusy $end\n", f);
  fputs("$var wire 1 \x32 io_output1_valid $end\n", f);
  fputs("$var wire 1 \x33 io_core_io_router_tx $end\n", f);
  fputs("$var wire 4 \x3a io_core_io_ip_addr $end\n", f);
  fputs("$var wire 32 \x41 io_core_io_ip_din $end\n", f);
  fputs("$var wire 32 \x49 io_core_io_ip_dout $end\n", f);
  fputs("$var wire 32 \x4b io_output1_data $end\n", f);
  fputs("$scope module schedule_ni $end\n", f);
  fputs("$var wire 1 \x2d io_dir_read $end\n", f);
  fputs("$var wire 4 \x37 io_dir_rdData_dst $end\n", f);
  fputs("$var wire 20 \x3f io_dir_rdAddr $end\n", f);
  fputs("$var wire 20 \x40 rdAddrReg $end\n", f);
  fputs("$upscope $end\n", f);
  fputs("$scope module control_ni $end\n", f);
  fputs("$var wire 1 \x24 io_ipNI_io_ip_rtw $end\n", f);
  fputs("$var wire 1 \x25 reset $end\n", f);
  fputs("$var wire 1 \x26 qt_3_valid $end\n", f);
  fputs("$var wire 1 \x27 qt_2_valid $end\n", f);
  fputs("$var wire 1 \x28 qt_1_valid $end\n", f);
  fputs("$var wire 1 \x29 qt_0_valid $end\n", f);
  fputs("$var wire 1 \x2a tx_dout_valid $end\n", f);
  fputs("$var wire 1 \x2b io_ipNI_io_ip_ack $end\n", f);
  fputs("$var wire 1 \x2c io_dir_read $end\n", f);
  fputs("$var wire 1 \x2f io_ipNI_io_ip_qtBusy $end\n", f);
  fputs("$var wire 1 \x31 io_r_lc_dout_valid $end\n", f);
  fputs("$var wire 2 \x34 qtHead $end\n", f);
  fputs("$var wire 2 \x35 qtTail $end\n", f);
  fputs("$var wire 3 \x36 qtPhitCount $end\n", f);
  fputs("$var wire 4 \x38 io_dir_rdData_dst $end\n", f);
  fputs("$var wire 4 \x39 reg_dir_data_dst $end\n", f);
  fputs("$var wire 4 \x3b io_ipNI_io_ip_addr $end\n", f);
  fputs("$var wire 4 \x3c reg_tx_dst $end\n", f);
  fputs("$var wire 19 \x3d reg_slotCount $end\n", f);
  fputs("$var wire 20 \x3e io_dir_rdAddr $end\n", f);
  fputs("$var wire 32 \x42 io_ipNI_io_ip_din $end\n", f);
  fputs("$var wire 32 \x43 qt_3_data $end\n", f);
  fputs("$var wire 32 \x44 qt_2_data $end\n", f);
  fputs("$var wire 32 \x45 qt_1_data $end\n", f);
  fputs("$var wire 32 \x46 qt_0_data $end\n", f);
  fputs("$var wire 32 \x47 tx_dout_data $end\n", f);
  fputs("$var wire 32 \x48 io_ipNI_io_ip_dout $end\n", f);
  fputs("$var wire 32 \x4a io_r_lc_dout_data $end\n", f);
  fputs("$upscope $end\n", f);
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
  dat_dump<1>(f, NiBox__io_core_io_ip_rtw, 0x23);
  NiBox__io_core_io_ip_rtw__prev = NiBox__io_core_io_ip_rtw;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_rtw, 0x24);
  NiBox_control_ni__io_ipNI_io_ip_rtw__prev = NiBox_control_ni__io_ipNI_io_ip_rtw;
  dat_dump<1>(f, NiBox_control_ni__reset, 0x25);
  NiBox_control_ni__reset__prev = NiBox_control_ni__reset;
  dat_dump<1>(f, NiBox_control_ni__qt_3_valid, 0x26);
  NiBox_control_ni__qt_3_valid__prev = NiBox_control_ni__qt_3_valid;
  dat_dump<1>(f, NiBox_control_ni__qt_2_valid, 0x27);
  NiBox_control_ni__qt_2_valid__prev = NiBox_control_ni__qt_2_valid;
  dat_dump<1>(f, NiBox_control_ni__qt_1_valid, 0x28);
  NiBox_control_ni__qt_1_valid__prev = NiBox_control_ni__qt_1_valid;
  dat_dump<1>(f, NiBox_control_ni__qt_0_valid, 0x29);
  NiBox_control_ni__qt_0_valid__prev = NiBox_control_ni__qt_0_valid;
  dat_dump<1>(f, NiBox_control_ni__tx_dout_valid, 0x2a);
  NiBox_control_ni__tx_dout_valid__prev = NiBox_control_ni__tx_dout_valid;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_ack, 0x2b);
  NiBox_control_ni__io_ipNI_io_ip_ack__prev = NiBox_control_ni__io_ipNI_io_ip_ack;
  dat_dump<1>(f, NiBox_control_ni__io_dir_read, 0x2c);
  NiBox_control_ni__io_dir_read__prev = NiBox_control_ni__io_dir_read;
  dat_dump<1>(f, NiBox_schedule_ni__io_dir_read, 0x2d);
  NiBox_schedule_ni__io_dir_read__prev = NiBox_schedule_ni__io_dir_read;
  dat_dump<1>(f, NiBox__io_core_io_ip_ack, 0x2e);
  NiBox__io_core_io_ip_ack__prev = NiBox__io_core_io_ip_ack;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_qtBusy, 0x2f);
  NiBox_control_ni__io_ipNI_io_ip_qtBusy__prev = NiBox_control_ni__io_ipNI_io_ip_qtBusy;
  dat_dump<1>(f, NiBox__io_core_io_ip_qtBusy, 0x30);
  NiBox__io_core_io_ip_qtBusy__prev = NiBox__io_core_io_ip_qtBusy;
  dat_dump<1>(f, NiBox_control_ni__io_r_lc_dout_valid, 0x31);
  NiBox_control_ni__io_r_lc_dout_valid__prev = NiBox_control_ni__io_r_lc_dout_valid;
  dat_dump<1>(f, NiBox__io_output1_valid, 0x32);
  NiBox__io_output1_valid__prev = NiBox__io_output1_valid;
  dat_dump<1>(f, NiBox__io_core_io_router_tx, 0x33);
  NiBox__io_core_io_router_tx__prev = NiBox__io_core_io_router_tx;
  dat_dump<1>(f, NiBox_control_ni__qtHead, 0x34);
  NiBox_control_ni__qtHead__prev = NiBox_control_ni__qtHead;
  dat_dump<1>(f, NiBox_control_ni__qtTail, 0x35);
  NiBox_control_ni__qtTail__prev = NiBox_control_ni__qtTail;
  dat_dump<1>(f, NiBox_control_ni__qtPhitCount, 0x36);
  NiBox_control_ni__qtPhitCount__prev = NiBox_control_ni__qtPhitCount;
  dat_dump<1>(f, NiBox_schedule_ni__io_dir_rdData_dst, 0x37);
  NiBox_schedule_ni__io_dir_rdData_dst__prev = NiBox_schedule_ni__io_dir_rdData_dst;
  dat_dump<1>(f, NiBox_control_ni__io_dir_rdData_dst, 0x38);
  NiBox_control_ni__io_dir_rdData_dst__prev = NiBox_control_ni__io_dir_rdData_dst;
  dat_dump<1>(f, NiBox_control_ni__reg_dir_data_dst, 0x39);
  NiBox_control_ni__reg_dir_data_dst__prev = NiBox_control_ni__reg_dir_data_dst;
  dat_dump<1>(f, NiBox__io_core_io_ip_addr, 0x3a);
  NiBox__io_core_io_ip_addr__prev = NiBox__io_core_io_ip_addr;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_addr, 0x3b);
  NiBox_control_ni__io_ipNI_io_ip_addr__prev = NiBox_control_ni__io_ipNI_io_ip_addr;
  dat_dump<1>(f, NiBox_control_ni__reg_tx_dst, 0x3c);
  NiBox_control_ni__reg_tx_dst__prev = NiBox_control_ni__reg_tx_dst;
  dat_dump<1>(f, NiBox_control_ni__reg_slotCount, 0x3d);
  NiBox_control_ni__reg_slotCount__prev = NiBox_control_ni__reg_slotCount;
  dat_dump<1>(f, NiBox_control_ni__io_dir_rdAddr, 0x3e);
  NiBox_control_ni__io_dir_rdAddr__prev = NiBox_control_ni__io_dir_rdAddr;
  dat_dump<1>(f, NiBox_schedule_ni__io_dir_rdAddr, 0x3f);
  NiBox_schedule_ni__io_dir_rdAddr__prev = NiBox_schedule_ni__io_dir_rdAddr;
  dat_dump<1>(f, NiBox_schedule_ni__rdAddrReg, 0x40);
  NiBox_schedule_ni__rdAddrReg__prev = NiBox_schedule_ni__rdAddrReg;
  dat_dump<1>(f, NiBox__io_core_io_ip_din, 0x41);
  NiBox__io_core_io_ip_din__prev = NiBox__io_core_io_ip_din;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_din, 0x42);
  NiBox_control_ni__io_ipNI_io_ip_din__prev = NiBox_control_ni__io_ipNI_io_ip_din;
  dat_dump<1>(f, NiBox_control_ni__qt_3_data, 0x43);
  NiBox_control_ni__qt_3_data__prev = NiBox_control_ni__qt_3_data;
  dat_dump<1>(f, NiBox_control_ni__qt_2_data, 0x44);
  NiBox_control_ni__qt_2_data__prev = NiBox_control_ni__qt_2_data;
  dat_dump<1>(f, NiBox_control_ni__qt_1_data, 0x45);
  NiBox_control_ni__qt_1_data__prev = NiBox_control_ni__qt_1_data;
  dat_dump<1>(f, NiBox_control_ni__qt_0_data, 0x46);
  NiBox_control_ni__qt_0_data__prev = NiBox_control_ni__qt_0_data;
  dat_dump<1>(f, NiBox_control_ni__tx_dout_data, 0x47);
  NiBox_control_ni__tx_dout_data__prev = NiBox_control_ni__tx_dout_data;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_dout, 0x48);
  NiBox_control_ni__io_ipNI_io_ip_dout__prev = NiBox_control_ni__io_ipNI_io_ip_dout;
  dat_dump<1>(f, NiBox__io_core_io_ip_dout, 0x49);
  NiBox__io_core_io_ip_dout__prev = NiBox__io_core_io_ip_dout;
  dat_dump<1>(f, NiBox_control_ni__io_r_lc_dout_data, 0x4a);
  NiBox_control_ni__io_r_lc_dout_data__prev = NiBox_control_ni__io_r_lc_dout_data;
  dat_dump<1>(f, NiBox__io_output1_data, 0x4b);
  NiBox__io_output1_data__prev = NiBox__io_output1_data;
  fputs("#1\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 0;
    dat_dump<1>(f, clk, 0x21);
  }
}


void NiBox_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
  if (t == 0L) return dump_init(f);
  fprintf(f, "#%lu\n", t << 1);
  if (clk.cnt == 0)  goto L0;
K0:  if (reset != reset__prev)  goto L1;
K1:  if (NiBox__io_core_io_ip_rtw != NiBox__io_core_io_ip_rtw__prev)  goto L2;
K2:  if (NiBox_control_ni__io_ipNI_io_ip_rtw != NiBox_control_ni__io_ipNI_io_ip_rtw__prev)  goto L3;
K3:  if (NiBox_control_ni__reset != NiBox_control_ni__reset__prev)  goto L4;
K4:  if (NiBox_control_ni__qt_3_valid != NiBox_control_ni__qt_3_valid__prev)  goto L5;
K5:  if (NiBox_control_ni__qt_2_valid != NiBox_control_ni__qt_2_valid__prev)  goto L6;
K6:  if (NiBox_control_ni__qt_1_valid != NiBox_control_ni__qt_1_valid__prev)  goto L7;
K7:  if (NiBox_control_ni__qt_0_valid != NiBox_control_ni__qt_0_valid__prev)  goto L8;
K8:  if (NiBox_control_ni__tx_dout_valid != NiBox_control_ni__tx_dout_valid__prev)  goto L9;
K9:  if (NiBox_control_ni__io_ipNI_io_ip_ack != NiBox_control_ni__io_ipNI_io_ip_ack__prev)  goto L10;
K10:  if (NiBox_control_ni__io_dir_read != NiBox_control_ni__io_dir_read__prev)  goto L11;
K11:  if (NiBox_schedule_ni__io_dir_read != NiBox_schedule_ni__io_dir_read__prev)  goto L12;
K12:  if (NiBox__io_core_io_ip_ack != NiBox__io_core_io_ip_ack__prev)  goto L13;
K13:  if (NiBox_control_ni__io_ipNI_io_ip_qtBusy != NiBox_control_ni__io_ipNI_io_ip_qtBusy__prev)  goto L14;
K14:  if (NiBox__io_core_io_ip_qtBusy != NiBox__io_core_io_ip_qtBusy__prev)  goto L15;
K15:  if (NiBox_control_ni__io_r_lc_dout_valid != NiBox_control_ni__io_r_lc_dout_valid__prev)  goto L16;
K16:  if (NiBox__io_output1_valid != NiBox__io_output1_valid__prev)  goto L17;
K17:  if (NiBox__io_core_io_router_tx != NiBox__io_core_io_router_tx__prev)  goto L18;
K18:  if (NiBox_control_ni__qtHead != NiBox_control_ni__qtHead__prev)  goto L19;
K19:  if (NiBox_control_ni__qtTail != NiBox_control_ni__qtTail__prev)  goto L20;
K20:  if (NiBox_control_ni__qtPhitCount != NiBox_control_ni__qtPhitCount__prev)  goto L21;
K21:  if (NiBox_schedule_ni__io_dir_rdData_dst != NiBox_schedule_ni__io_dir_rdData_dst__prev)  goto L22;
K22:  if (NiBox_control_ni__io_dir_rdData_dst != NiBox_control_ni__io_dir_rdData_dst__prev)  goto L23;
K23:  if (NiBox_control_ni__reg_dir_data_dst != NiBox_control_ni__reg_dir_data_dst__prev)  goto L24;
K24:  if (NiBox__io_core_io_ip_addr != NiBox__io_core_io_ip_addr__prev)  goto L25;
K25:  if (NiBox_control_ni__io_ipNI_io_ip_addr != NiBox_control_ni__io_ipNI_io_ip_addr__prev)  goto L26;
K26:  if (NiBox_control_ni__reg_tx_dst != NiBox_control_ni__reg_tx_dst__prev)  goto L27;
K27:  if (NiBox_control_ni__reg_slotCount != NiBox_control_ni__reg_slotCount__prev)  goto L28;
K28:  if (NiBox_control_ni__io_dir_rdAddr != NiBox_control_ni__io_dir_rdAddr__prev)  goto L29;
K29:  if (NiBox_schedule_ni__io_dir_rdAddr != NiBox_schedule_ni__io_dir_rdAddr__prev)  goto L30;
K30:  if (NiBox_schedule_ni__rdAddrReg != NiBox_schedule_ni__rdAddrReg__prev)  goto L31;
K31:  if (NiBox__io_core_io_ip_din != NiBox__io_core_io_ip_din__prev)  goto L32;
K32:  if (NiBox_control_ni__io_ipNI_io_ip_din != NiBox_control_ni__io_ipNI_io_ip_din__prev)  goto L33;
K33:  if (NiBox_control_ni__qt_3_data != NiBox_control_ni__qt_3_data__prev)  goto L34;
K34:  if (NiBox_control_ni__qt_2_data != NiBox_control_ni__qt_2_data__prev)  goto L35;
K35:  if (NiBox_control_ni__qt_1_data != NiBox_control_ni__qt_1_data__prev)  goto L36;
K36:  if (NiBox_control_ni__qt_0_data != NiBox_control_ni__qt_0_data__prev)  goto L37;
K37:  if (NiBox_control_ni__tx_dout_data != NiBox_control_ni__tx_dout_data__prev)  goto L38;
K38:  if (NiBox_control_ni__io_ipNI_io_ip_dout != NiBox_control_ni__io_ipNI_io_ip_dout__prev)  goto L39;
K39:  if (NiBox__io_core_io_ip_dout != NiBox__io_core_io_ip_dout__prev)  goto L40;
K40:  if (NiBox_control_ni__io_r_lc_dout_data != NiBox_control_ni__io_r_lc_dout_data__prev)  goto L41;
K41:  if (NiBox__io_output1_data != NiBox__io_output1_data__prev)  goto L42;
K42:  fprintf(f, "#%lu\n", (t << 1) + 1);
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
  NiBox__io_core_io_ip_rtw__prev = NiBox__io_core_io_ip_rtw;
  dat_dump<1>(f, NiBox__io_core_io_ip_rtw, 0x23);
  goto K2;
L3:
  NiBox_control_ni__io_ipNI_io_ip_rtw__prev = NiBox_control_ni__io_ipNI_io_ip_rtw;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_rtw, 0x24);
  goto K3;
L4:
  NiBox_control_ni__reset__prev = NiBox_control_ni__reset;
  dat_dump<1>(f, NiBox_control_ni__reset, 0x25);
  goto K4;
L5:
  NiBox_control_ni__qt_3_valid__prev = NiBox_control_ni__qt_3_valid;
  dat_dump<1>(f, NiBox_control_ni__qt_3_valid, 0x26);
  goto K5;
L6:
  NiBox_control_ni__qt_2_valid__prev = NiBox_control_ni__qt_2_valid;
  dat_dump<1>(f, NiBox_control_ni__qt_2_valid, 0x27);
  goto K6;
L7:
  NiBox_control_ni__qt_1_valid__prev = NiBox_control_ni__qt_1_valid;
  dat_dump<1>(f, NiBox_control_ni__qt_1_valid, 0x28);
  goto K7;
L8:
  NiBox_control_ni__qt_0_valid__prev = NiBox_control_ni__qt_0_valid;
  dat_dump<1>(f, NiBox_control_ni__qt_0_valid, 0x29);
  goto K8;
L9:
  NiBox_control_ni__tx_dout_valid__prev = NiBox_control_ni__tx_dout_valid;
  dat_dump<1>(f, NiBox_control_ni__tx_dout_valid, 0x2a);
  goto K9;
L10:
  NiBox_control_ni__io_ipNI_io_ip_ack__prev = NiBox_control_ni__io_ipNI_io_ip_ack;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_ack, 0x2b);
  goto K10;
L11:
  NiBox_control_ni__io_dir_read__prev = NiBox_control_ni__io_dir_read;
  dat_dump<1>(f, NiBox_control_ni__io_dir_read, 0x2c);
  goto K11;
L12:
  NiBox_schedule_ni__io_dir_read__prev = NiBox_schedule_ni__io_dir_read;
  dat_dump<1>(f, NiBox_schedule_ni__io_dir_read, 0x2d);
  goto K12;
L13:
  NiBox__io_core_io_ip_ack__prev = NiBox__io_core_io_ip_ack;
  dat_dump<1>(f, NiBox__io_core_io_ip_ack, 0x2e);
  goto K13;
L14:
  NiBox_control_ni__io_ipNI_io_ip_qtBusy__prev = NiBox_control_ni__io_ipNI_io_ip_qtBusy;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_qtBusy, 0x2f);
  goto K14;
L15:
  NiBox__io_core_io_ip_qtBusy__prev = NiBox__io_core_io_ip_qtBusy;
  dat_dump<1>(f, NiBox__io_core_io_ip_qtBusy, 0x30);
  goto K15;
L16:
  NiBox_control_ni__io_r_lc_dout_valid__prev = NiBox_control_ni__io_r_lc_dout_valid;
  dat_dump<1>(f, NiBox_control_ni__io_r_lc_dout_valid, 0x31);
  goto K16;
L17:
  NiBox__io_output1_valid__prev = NiBox__io_output1_valid;
  dat_dump<1>(f, NiBox__io_output1_valid, 0x32);
  goto K17;
L18:
  NiBox__io_core_io_router_tx__prev = NiBox__io_core_io_router_tx;
  dat_dump<1>(f, NiBox__io_core_io_router_tx, 0x33);
  goto K18;
L19:
  NiBox_control_ni__qtHead__prev = NiBox_control_ni__qtHead;
  dat_dump<1>(f, NiBox_control_ni__qtHead, 0x34);
  goto K19;
L20:
  NiBox_control_ni__qtTail__prev = NiBox_control_ni__qtTail;
  dat_dump<1>(f, NiBox_control_ni__qtTail, 0x35);
  goto K20;
L21:
  NiBox_control_ni__qtPhitCount__prev = NiBox_control_ni__qtPhitCount;
  dat_dump<1>(f, NiBox_control_ni__qtPhitCount, 0x36);
  goto K21;
L22:
  NiBox_schedule_ni__io_dir_rdData_dst__prev = NiBox_schedule_ni__io_dir_rdData_dst;
  dat_dump<1>(f, NiBox_schedule_ni__io_dir_rdData_dst, 0x37);
  goto K22;
L23:
  NiBox_control_ni__io_dir_rdData_dst__prev = NiBox_control_ni__io_dir_rdData_dst;
  dat_dump<1>(f, NiBox_control_ni__io_dir_rdData_dst, 0x38);
  goto K23;
L24:
  NiBox_control_ni__reg_dir_data_dst__prev = NiBox_control_ni__reg_dir_data_dst;
  dat_dump<1>(f, NiBox_control_ni__reg_dir_data_dst, 0x39);
  goto K24;
L25:
  NiBox__io_core_io_ip_addr__prev = NiBox__io_core_io_ip_addr;
  dat_dump<1>(f, NiBox__io_core_io_ip_addr, 0x3a);
  goto K25;
L26:
  NiBox_control_ni__io_ipNI_io_ip_addr__prev = NiBox_control_ni__io_ipNI_io_ip_addr;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_addr, 0x3b);
  goto K26;
L27:
  NiBox_control_ni__reg_tx_dst__prev = NiBox_control_ni__reg_tx_dst;
  dat_dump<1>(f, NiBox_control_ni__reg_tx_dst, 0x3c);
  goto K27;
L28:
  NiBox_control_ni__reg_slotCount__prev = NiBox_control_ni__reg_slotCount;
  dat_dump<1>(f, NiBox_control_ni__reg_slotCount, 0x3d);
  goto K28;
L29:
  NiBox_control_ni__io_dir_rdAddr__prev = NiBox_control_ni__io_dir_rdAddr;
  dat_dump<1>(f, NiBox_control_ni__io_dir_rdAddr, 0x3e);
  goto K29;
L30:
  NiBox_schedule_ni__io_dir_rdAddr__prev = NiBox_schedule_ni__io_dir_rdAddr;
  dat_dump<1>(f, NiBox_schedule_ni__io_dir_rdAddr, 0x3f);
  goto K30;
L31:
  NiBox_schedule_ni__rdAddrReg__prev = NiBox_schedule_ni__rdAddrReg;
  dat_dump<1>(f, NiBox_schedule_ni__rdAddrReg, 0x40);
  goto K31;
L32:
  NiBox__io_core_io_ip_din__prev = NiBox__io_core_io_ip_din;
  dat_dump<1>(f, NiBox__io_core_io_ip_din, 0x41);
  goto K32;
L33:
  NiBox_control_ni__io_ipNI_io_ip_din__prev = NiBox_control_ni__io_ipNI_io_ip_din;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_din, 0x42);
  goto K33;
L34:
  NiBox_control_ni__qt_3_data__prev = NiBox_control_ni__qt_3_data;
  dat_dump<1>(f, NiBox_control_ni__qt_3_data, 0x43);
  goto K34;
L35:
  NiBox_control_ni__qt_2_data__prev = NiBox_control_ni__qt_2_data;
  dat_dump<1>(f, NiBox_control_ni__qt_2_data, 0x44);
  goto K35;
L36:
  NiBox_control_ni__qt_1_data__prev = NiBox_control_ni__qt_1_data;
  dat_dump<1>(f, NiBox_control_ni__qt_1_data, 0x45);
  goto K36;
L37:
  NiBox_control_ni__qt_0_data__prev = NiBox_control_ni__qt_0_data;
  dat_dump<1>(f, NiBox_control_ni__qt_0_data, 0x46);
  goto K37;
L38:
  NiBox_control_ni__tx_dout_data__prev = NiBox_control_ni__tx_dout_data;
  dat_dump<1>(f, NiBox_control_ni__tx_dout_data, 0x47);
  goto K38;
L39:
  NiBox_control_ni__io_ipNI_io_ip_dout__prev = NiBox_control_ni__io_ipNI_io_ip_dout;
  dat_dump<1>(f, NiBox_control_ni__io_ipNI_io_ip_dout, 0x48);
  goto K39;
L40:
  NiBox__io_core_io_ip_dout__prev = NiBox__io_core_io_ip_dout;
  dat_dump<1>(f, NiBox__io_core_io_ip_dout, 0x49);
  goto K40;
L41:
  NiBox_control_ni__io_r_lc_dout_data__prev = NiBox_control_ni__io_r_lc_dout_data;
  dat_dump<1>(f, NiBox_control_ni__io_r_lc_dout_data, 0x4a);
  goto K41;
L42:
  NiBox__io_output1_data__prev = NiBox__io_output1_data;
  dat_dump<1>(f, NiBox__io_output1_data, 0x4b);
  goto K42;
Z0:
  clk.values[0] = 0;
  dat_dump<1>(f, clk, 0x21);
  goto C0;
}




void NiBox_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  { NiBox_control_ni__io_ipNI_io_ip_din.values[0] = NiBox__io_core_io_ip_din.values[0];}
  val_t T0;
  T0 = 0x1L << NiBox_control_ni__qtTail.values[0];
  T0 = T0 & 0xfL;
  val_t T1;
  T1 = (T0 >> 3) & 1;
  val_t T2;
  T2 = NiBox_control_ni__qtPhitCount.values[0] == 0x4L;
  val_t T3;
  { T3 = T2 ^ 0x1L;}
  { NiBox_control_ni__io_ipNI_io_ip_rtw.values[0] = NiBox__io_core_io_ip_rtw.values[0];}
  val_t T4;
  { T4 = NiBox_control_ni__io_ipNI_io_ip_rtw.values[0] & T3;}
  val_t T5;
  { T5 = T4 & T1;}
  val_t T6;
  { T6 = TERNARY_1(T5, NiBox_control_ni__io_ipNI_io_ip_din.values[0], NiBox_control_ni__qt_3_data.values[0]);}
  { NiBox_control_ni__reset.values[0] = reset.values[0];}
  { T7.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T6);}
  val_t T8;
  T8 = (T0 >> 2) & 1;
  val_t T9;
  { T9 = T4 & T8;}
  val_t T10;
  { T10 = TERNARY_1(T9, NiBox_control_ni__io_ipNI_io_ip_din.values[0], NiBox_control_ni__qt_2_data.values[0]);}
  { T11.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T10);}
  val_t T12;
  T12 = (T0 >> 1) & 1;
  val_t T13;
  { T13 = T4 & T12;}
  val_t T14;
  { T14 = TERNARY_1(T13, NiBox_control_ni__io_ipNI_io_ip_din.values[0], NiBox_control_ni__qt_1_data.values[0]);}
  { T15.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T14);}
  val_t T16;
  T16 = (T0 >> 0) & 1;
  val_t T17;
  { T17 = T4 & T16;}
  val_t T18;
  { T18 = TERNARY_1(T17, NiBox_control_ni__io_ipNI_io_ip_din.values[0], NiBox_control_ni__qt_0_data.values[0]);}
  { T19.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T18);}
  val_t T20;
  T20 = (NiBox_control_ni__qtHead.values[0] >> 0) & 1;
  val_t T21;
  { T21 = TERNARY_1(T20, NiBox_control_ni__qt_1_data.values[0], NiBox_control_ni__qt_0_data.values[0]);}
  val_t T22;
  T22 = (NiBox_control_ni__qtHead.values[0] >> 0) & 1;
  val_t T23;
  { T23 = TERNARY_1(T22, NiBox_control_ni__qt_3_data.values[0], NiBox_control_ni__qt_2_data.values[0]);}
  val_t T24;
  T24 = (NiBox_control_ni__qtHead.values[0] >> 1) & 1;
  val_t T25;
  { T25 = TERNARY_1(T24, T23, T21);}
  val_t T26;
  T26 = NiBox_control_ni__qtPhitCount.values[0] == 0x0L;
  val_t T27;
  { T27 = T26 ^ 0x1L;}
  val_t T28;
  T28 = NiBox_control_ni__reg_dir_data_dst.values[0] == NiBox_control_ni__reg_tx_dst.values[0];
  val_t T29;
  { T29 = T28 & T27;}
  val_t T30;
  { T30 = TERNARY_1(T29, T25, NiBox_control_ni__tx_dout_data.values[0]);}
  { T31.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T30);}
  val_t T32;
  { T32 = T4 & T1;}
  val_t T33;
  { T33 = TERNARY(T32, 0x1L, NiBox_control_ni__qt_3_valid.values[0]);}
  { T34.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T33);}
  val_t T35;
  { T35 = T4 & T8;}
  val_t T36;
  { T36 = TERNARY(T35, 0x1L, NiBox_control_ni__qt_2_valid.values[0]);}
  { T37.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T36);}
  val_t T38;
  { T38 = NiBox_control_ni__qtHead.values[0]+0x1L;}
  T38 = T38 & 0x3L;
  val_t T39;
  { T39 = NiBox_control_ni__qtHead.values[0] | 0x0L << 2;}
  val_t T40;
  T40 = T39 == 0x4L;
  val_t T41;
  { T41 = TERNARY(T40, 0x0L, T38);}
  val_t T42;
  { T42 = TERNARY_1(T29, T41, NiBox_control_ni__qtHead.values[0]);}
  { T43.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T42);}
  val_t T44;
  { T44 = T4 & T12;}
  val_t T45;
  { T45 = TERNARY(T44, 0x1L, NiBox_control_ni__qt_1_valid.values[0]);}
  { T46.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T45);}
  val_t T47;
  { T47 = NiBox_control_ni__qtTail.values[0]+0x1L;}
  T47 = T47 & 0x3L;
  val_t T48;
  { T48 = NiBox_control_ni__qtTail.values[0] | 0x0L << 2;}
  val_t T49;
  T49 = T48 == 0x4L;
  val_t T50;
  { T50 = TERNARY(T49, 0x0L, T47);}
  val_t T51;
  { T51 = TERNARY_1(T4, T50, NiBox_control_ni__qtTail.values[0]);}
  { T52.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T51);}
  val_t T53;
  { T53 = T4 & T16;}
  val_t T54;
  { T54 = TERNARY(T53, 0x1L, NiBox_control_ni__qt_0_valid.values[0]);}
  { T55.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T54);}
  val_t T56;
  T56 = (NiBox_control_ni__qtHead.values[0] >> 0) & 1;
  val_t T57;
  { T57 = TERNARY_1(T56, NiBox_control_ni__qt_1_valid.values[0], NiBox_control_ni__qt_0_valid.values[0]);}
  val_t T58;
  T58 = (NiBox_control_ni__qtHead.values[0] >> 0) & 1;
  val_t T59;
  { T59 = TERNARY_1(T58, NiBox_control_ni__qt_3_valid.values[0], NiBox_control_ni__qt_2_valid.values[0]);}
  val_t T60;
  T60 = (NiBox_control_ni__qtHead.values[0] >> 1) & 1;
  val_t T61;
  { T61 = TERNARY_1(T60, T59, T57);}
  val_t T62;
  { T62 = TERNARY_1(T29, T61, NiBox_control_ni__tx_dout_valid.values[0]);}
  { T63.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T62);}
  { val_t __r = this->__rand_val(); NiBox_control_ni__io_ipNI_io_ip_ack.values[0] = __r;}
  NiBox_control_ni__io_ipNI_io_ip_ack.values[0] = NiBox_control_ni__io_ipNI_io_ip_ack.values[0] & 0x1L;
  { NiBox_control_ni__io_dir_read.values[0] = 0x1L;}
  { NiBox_schedule_ni__io_dir_read.values[0] = NiBox_control_ni__io_dir_read.values[0];}
  val_t T64;
  T64 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T65;
  T65 = 0x0L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T66;
  { T66 = T65 & T64;}
  val_t T67;
  { T67 = TERNARY(T66, 0x0L, 0x0L);}
  val_t T68;
  T68 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T69;
  T69 = 0x1L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T70;
  { T70 = T69 & T68;}
  val_t T71;
  { T71 = TERNARY(T70, 0xeL, T67);}
  val_t T72;
  T72 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T73;
  T73 = 0x2L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T74;
  { T74 = T73 & T72;}
  val_t T75;
  { T75 = TERNARY(T74, 0x9L, T71);}
  val_t T76;
  T76 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T77;
  T77 = 0x3L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T78;
  { T78 = T77 & T76;}
  val_t T79;
  { T79 = TERNARY(T78, 0xbL, T75);}
  val_t T80;
  T80 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T81;
  T81 = 0x4L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T82;
  { T82 = T81 & T80;}
  val_t T83;
  { T83 = TERNARY(T82, 0x0L, T79);}
  val_t T84;
  T84 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T85;
  T85 = 0x5L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T86;
  { T86 = T85 & T84;}
  val_t T87;
  { T87 = TERNARY(T86, 0x6L, T83);}
  val_t T88;
  T88 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T89;
  T89 = 0x6L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T90;
  { T90 = T89 & T88;}
  val_t T91;
  { T91 = TERNARY(T90, 0xcL, T87);}
  val_t T92;
  T92 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T93;
  T93 = 0x7L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T94;
  { T94 = T93 & T92;}
  val_t T95;
  { T95 = TERNARY(T94, 0xdL, T91);}
  val_t T96;
  T96 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T97;
  T97 = 0x8L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T98;
  { T98 = T97 & T96;}
  val_t T99;
  { T99 = TERNARY(T98, 0xfL, T95);}
  val_t T100;
  T100 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T101;
  T101 = 0x9L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T102;
  { T102 = T101 & T100;}
  val_t T103;
  { T103 = TERNARY(T102, 0x8L, T99);}
  val_t T104;
  T104 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T105;
  T105 = 0xaL == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T106;
  { T106 = T105 & T104;}
  val_t T107;
  { T107 = TERNARY(T106, 0x2L, T103);}
  val_t T108;
  T108 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T109;
  T109 = 0xbL == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T110;
  { T110 = T109 & T108;}
  val_t T111;
  { T111 = TERNARY(T110, 0x7L, T107);}
  val_t T112;
  T112 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T113;
  T113 = 0xcL == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T114;
  { T114 = T113 & T112;}
  val_t T115;
  { T115 = TERNARY(T114, 0x0L, T111);}
  val_t T116;
  T116 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T117;
  T117 = 0xdL == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T118;
  { T118 = T117 & T116;}
  val_t T119;
  { T119 = TERNARY(T118, 0x1L, T115);}
  val_t T120;
  T120 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T121;
  T121 = 0xeL == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T122;
  { T122 = T121 & T120;}
  val_t T123;
  { T123 = TERNARY(T122, 0x4L, T119);}
  val_t T124;
  T124 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T125;
  T125 = 0xfL == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T126;
  { T126 = T125 & T124;}
  val_t T127;
  { T127 = TERNARY(T126, 0x3L, T123);}
  val_t T128;
  T128 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T129;
  T129 = 0x10L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T130;
  { T130 = T129 & T128;}
  val_t T131;
  { T131 = TERNARY(T130, 0x0L, T127);}
  val_t T132;
  T132 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T133;
  T133 = 0x11L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T134;
  { T134 = T133 & T132;}
  val_t T135;
  { T135 = TERNARY(T134, 0xaL, T131);}
  val_t T136;
  T136 = NiBox_schedule_ni__io_dir_read.values[0] == 0x1L;
  val_t T137;
  T137 = 0x12L == NiBox_schedule_ni__rdAddrReg.values[0];
  val_t T138;
  { T138 = T137 & T136;}
  val_t T139;
  { T139 = TERNARY(T138, 0x5L, T135);}
  { NiBox_schedule_ni__io_dir_rdData_dst.values[0] = T139;}
  { NiBox_control_ni__io_dir_rdData_dst.values[0] = NiBox_schedule_ni__io_dir_rdData_dst.values[0];}
  { T140.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, NiBox_control_ni__io_dir_rdData_dst.values[0]);}
  { NiBox_control_ni__io_ipNI_io_ip_addr.values[0] = NiBox__io_core_io_ip_addr.values[0];}
  { T141.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, NiBox_control_ni__io_ipNI_io_ip_addr.values[0]);}
  val_t T142;
  { T142 = NiBox_control_ni__qtPhitCount.values[0]+0x1L;}
  T142 = T142 & 0x7L;
  val_t T143;
  { T143 = T29 ^ 0x1L;}
  val_t T144;
  { T144 = T4 & T143;}
  val_t T145;
  { T145 = TERNARY_1(T144, T142, NiBox_control_ni__qtPhitCount.values[0]);}
  val_t T146;
  { T146 = NiBox_control_ni__qtPhitCount.values[0]-0x1L;}
  T146 = T146 & 0x7L;
  val_t T147;
  { T147 = T4 ^ 0x1L;}
  val_t T148;
  { T148 = T147 & T29;}
  val_t T149;
  { T149 = T144 ^ 0x1L;}
  val_t T150;
  { T150 = T149 & T148;}
  val_t T151;
  { T151 = TERNARY_1(T150, T146, T145);}
  { T152.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T151);}
  { val_t __r = this->__rand_val(); NiBox_control_ni__io_ipNI_io_ip_dout.values[0] = __r;}
  NiBox_control_ni__io_ipNI_io_ip_dout.values[0] = NiBox_control_ni__io_ipNI_io_ip_dout.values[0] & 0xffffffffL;
  val_t T153;
  { T153 = NiBox_control_ni__reg_slotCount.values[0]+0x1L;}
  T153 = T153 & 0x7ffffL;
  { T154.values[0] = TERNARY(NiBox_control_ni__reset.values[0], 0x0L, T153);}
  val_t T155;
  { T155 = NiBox_control_ni__reg_slotCount.values[0] | 0x0L << 19;}
  { NiBox_control_ni__io_dir_rdAddr.values[0] = T155;}
  { NiBox_schedule_ni__io_dir_rdAddr.values[0] = NiBox_control_ni__io_dir_rdAddr.values[0];}
  { val_t __r = this->__rand_val(); NiBox__io_core_io_ip_ack.values[0] = __r;}
  NiBox__io_core_io_ip_ack.values[0] = NiBox__io_core_io_ip_ack.values[0] & 0x1L;
  { NiBox_control_ni__io_ipNI_io_ip_qtBusy.values[0] = T2;}
  { NiBox__io_core_io_ip_qtBusy.values[0] = NiBox_control_ni__io_ipNI_io_ip_qtBusy.values[0];}
  { val_t __r = this->__rand_val(); NiBox__io_core_io_ip_dout.values[0] = __r;}
  NiBox__io_core_io_ip_dout.values[0] = NiBox__io_core_io_ip_dout.values[0] & 0xffffffffL;
  { NiBox_control_ni__io_r_lc_dout_data.values[0] = NiBox_control_ni__tx_dout_data.values[0];}
  { NiBox__io_output1_data.values[0] = NiBox_control_ni__io_r_lc_dout_data.values[0];}
  { NiBox_control_ni__io_r_lc_dout_valid.values[0] = NiBox_control_ni__tx_dout_valid.values[0];}
  { NiBox__io_output1_valid.values[0] = NiBox_control_ni__io_r_lc_dout_valid.values[0];}
}


void NiBox_t::clock_hi ( dat_t<1> reset ) {
  dat_t<32> NiBox_control_ni__qt_3_data__shadow = T7;
  dat_t<32> NiBox_control_ni__qt_2_data__shadow = T11;
  dat_t<32> NiBox_control_ni__qt_1_data__shadow = T15;
  dat_t<32> NiBox_control_ni__qt_0_data__shadow = T19;
  dat_t<32> NiBox_control_ni__tx_dout_data__shadow = T31;
  dat_t<1> NiBox_control_ni__qt_3_valid__shadow = T34;
  dat_t<1> NiBox_control_ni__qt_2_valid__shadow = T37;
  dat_t<2> NiBox_control_ni__qtHead__shadow = T43;
  dat_t<1> NiBox_control_ni__qt_1_valid__shadow = T46;
  dat_t<2> NiBox_control_ni__qtTail__shadow = T52;
  dat_t<1> NiBox_control_ni__qt_0_valid__shadow = T55;
  dat_t<1> NiBox_control_ni__tx_dout_valid__shadow = T63;
  dat_t<4> NiBox_control_ni__reg_dir_data_dst__shadow = T140;
  dat_t<4> NiBox_control_ni__reg_tx_dst__shadow = T141;
  dat_t<3> NiBox_control_ni__qtPhitCount__shadow = T152;
  dat_t<19> NiBox_control_ni__reg_slotCount__shadow = T154;
  dat_t<20> NiBox_schedule_ni__rdAddrReg__shadow = NiBox_schedule_ni__io_dir_rdAddr;
  NiBox_control_ni__qt_3_data = T7;
  NiBox_control_ni__qt_2_data = T11;
  NiBox_control_ni__qt_1_data = T15;
  NiBox_control_ni__qt_0_data = T19;
  NiBox_control_ni__tx_dout_data = T31;
  NiBox_control_ni__qt_3_valid = T34;
  NiBox_control_ni__qt_2_valid = T37;
  NiBox_control_ni__qtHead = T43;
  NiBox_control_ni__qt_1_valid = T46;
  NiBox_control_ni__qtTail = T52;
  NiBox_control_ni__qt_0_valid = T55;
  NiBox_control_ni__tx_dout_valid = T63;
  NiBox_control_ni__reg_dir_data_dst = T140;
  NiBox_control_ni__reg_tx_dst = T141;
  NiBox_control_ni__qtPhitCount = T152;
  NiBox_control_ni__reg_slotCount = T154;
  NiBox_schedule_ni__rdAddrReg = NiBox_schedule_ni__io_dir_rdAddr;
}


void NiBox_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  NiBox_t* mod = dynamic_cast<NiBox_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<32>(&mod->NiBox__io_core_io_ip_din));
  sim_data.inputs.push_back(new dat_api<1>(&mod->NiBox__io_core_io_router_tx));
  sim_data.inputs.push_back(new dat_api<1>(&mod->NiBox__io_core_io_ip_rtw));
  sim_data.inputs.push_back(new dat_api<4>(&mod->NiBox__io_core_io_ip_addr));
  sim_data.outputs.push_back(new dat_api<1>(&mod->NiBox__io_core_io_ip_ack));
  sim_data.outputs.push_back(new dat_api<1>(&mod->NiBox__io_core_io_ip_qtBusy));
  sim_data.outputs.push_back(new dat_api<32>(&mod->NiBox__io_core_io_ip_dout));
  sim_data.outputs.push_back(new dat_api<32>(&mod->NiBox__io_output1_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->NiBox__io_output1_valid));
  sim_data.signals.push_back(new dat_api<32>(&mod->NiBox_control_ni__io_ipNI_io_ip_din));
  sim_data.signal_map["NiBox.control_ni.io_ipNI_io_ip_din"] = 0;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__io_ipNI_io_ip_rtw));
  sim_data.signal_map["NiBox.control_ni.io_ipNI_io_ip_rtw"] = 1;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__reset));
  sim_data.signal_map["NiBox.control_ni.reset"] = 2;
  sim_data.signals.push_back(new dat_api<32>(&mod->NiBox_control_ni__qt_3_data));
  sim_data.signal_map["NiBox.control_ni.qt_3_data"] = 3;
  sim_data.signals.push_back(new dat_api<32>(&mod->NiBox_control_ni__qt_2_data));
  sim_data.signal_map["NiBox.control_ni.qt_2_data"] = 4;
  sim_data.signals.push_back(new dat_api<32>(&mod->NiBox_control_ni__qt_1_data));
  sim_data.signal_map["NiBox.control_ni.qt_1_data"] = 5;
  sim_data.signals.push_back(new dat_api<32>(&mod->NiBox_control_ni__qt_0_data));
  sim_data.signal_map["NiBox.control_ni.qt_0_data"] = 6;
  sim_data.signals.push_back(new dat_api<32>(&mod->NiBox_control_ni__tx_dout_data));
  sim_data.signal_map["NiBox.control_ni.tx_dout_data"] = 7;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__qt_3_valid));
  sim_data.signal_map["NiBox.control_ni.qt_3_valid"] = 8;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__qt_2_valid));
  sim_data.signal_map["NiBox.control_ni.qt_2_valid"] = 9;
  sim_data.signals.push_back(new dat_api<2>(&mod->NiBox_control_ni__qtHead));
  sim_data.signal_map["NiBox.control_ni.qtHead"] = 10;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__qt_1_valid));
  sim_data.signal_map["NiBox.control_ni.qt_1_valid"] = 11;
  sim_data.signals.push_back(new dat_api<2>(&mod->NiBox_control_ni__qtTail));
  sim_data.signal_map["NiBox.control_ni.qtTail"] = 12;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__qt_0_valid));
  sim_data.signal_map["NiBox.control_ni.qt_0_valid"] = 13;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__tx_dout_valid));
  sim_data.signal_map["NiBox.control_ni.tx_dout_valid"] = 14;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__io_dir_read));
  sim_data.signal_map["NiBox.control_ni.io_dir_read"] = 15;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_schedule_ni__io_dir_read));
  sim_data.signal_map["NiBox.schedule_ni.io_dir_read"] = 16;
  sim_data.signals.push_back(new dat_api<4>(&mod->NiBox_schedule_ni__io_dir_rdData_dst));
  sim_data.signal_map["NiBox.schedule_ni.io_dir_rdData_dst"] = 17;
  sim_data.signals.push_back(new dat_api<4>(&mod->NiBox_control_ni__io_dir_rdData_dst));
  sim_data.signal_map["NiBox.control_ni.io_dir_rdData_dst"] = 18;
  sim_data.signals.push_back(new dat_api<4>(&mod->NiBox_control_ni__reg_dir_data_dst));
  sim_data.signal_map["NiBox.control_ni.reg_dir_data_dst"] = 19;
  sim_data.signals.push_back(new dat_api<4>(&mod->NiBox_control_ni__io_ipNI_io_ip_addr));
  sim_data.signal_map["NiBox.control_ni.io_ipNI_io_ip_addr"] = 20;
  sim_data.signals.push_back(new dat_api<4>(&mod->NiBox_control_ni__reg_tx_dst));
  sim_data.signal_map["NiBox.control_ni.reg_tx_dst"] = 21;
  sim_data.signals.push_back(new dat_api<3>(&mod->NiBox_control_ni__qtPhitCount));
  sim_data.signal_map["NiBox.control_ni.qtPhitCount"] = 22;
  sim_data.signals.push_back(new dat_api<19>(&mod->NiBox_control_ni__reg_slotCount));
  sim_data.signal_map["NiBox.control_ni.reg_slotCount"] = 23;
  sim_data.signals.push_back(new dat_api<20>(&mod->NiBox_control_ni__io_dir_rdAddr));
  sim_data.signal_map["NiBox.control_ni.io_dir_rdAddr"] = 24;
  sim_data.signals.push_back(new dat_api<20>(&mod->NiBox_schedule_ni__io_dir_rdAddr));
  sim_data.signal_map["NiBox.schedule_ni.io_dir_rdAddr"] = 25;
  sim_data.signals.push_back(new dat_api<20>(&mod->NiBox_schedule_ni__rdAddrReg));
  sim_data.signal_map["NiBox.schedule_ni.rdAddrReg"] = 26;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__io_ipNI_io_ip_qtBusy));
  sim_data.signal_map["NiBox.control_ni.io_ipNI_io_ip_qtBusy"] = 27;
  sim_data.signals.push_back(new dat_api<32>(&mod->NiBox_control_ni__io_r_lc_dout_data));
  sim_data.signal_map["NiBox.control_ni.io_r_lc_dout_data"] = 28;
  sim_data.signals.push_back(new dat_api<1>(&mod->NiBox_control_ni__io_r_lc_dout_valid));
  sim_data.signal_map["NiBox.control_ni.io_r_lc_dout_valid"] = 29;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
