#include "Main.h"

void Main_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  Main_route__reg_slotCount.randomize(&__rand_seed);
  Main_route__dout_local_data.randomize(&__rand_seed);
  Main_route__directions_local.randomize(&__rand_seed);
  Main_route__dout_local_valid.randomize(&__rand_seed);
  Main_route__dout_right_data.randomize(&__rand_seed);
  Main_route__directions_right.randomize(&__rand_seed);
  Main_route__dout_right_valid.randomize(&__rand_seed);
  Main_route__dout_left_data.randomize(&__rand_seed);
  Main_route__directions_left.randomize(&__rand_seed);
  Main_route__dout_left_valid.randomize(&__rand_seed);
  Main_route__dout_up_data.randomize(&__rand_seed);
  Main_route__directions_up.randomize(&__rand_seed);
  Main_route__dout_up_valid.randomize(&__rand_seed);
  Main_route__din_local_data.randomize(&__rand_seed);
  Main_route__din_left_data.randomize(&__rand_seed);
  Main_route__din_down_data.randomize(&__rand_seed);
  Main_route__din_right_data.randomize(&__rand_seed);
  Main_route__din_up_data.randomize(&__rand_seed);
  Main_route__dout_down_data.randomize(&__rand_seed);
  Main_route__din_local_valid.randomize(&__rand_seed);
  Main_route__din_left_valid.randomize(&__rand_seed);
  Main_route__din_down_valid.randomize(&__rand_seed);
  Main_route__din_right_valid.randomize(&__rand_seed);
  Main_route__directions_down.randomize(&__rand_seed);
  Main_route__din_up_valid.randomize(&__rand_seed);
  Main_route__dout_down_valid.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int Main_t::clock ( dat_t<1> reset ) {
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


void Main_t::print ( FILE* f ) {
}
void Main_t::print ( std::ostream& s ) {
}


void Main_t::dump_init ( FILE* f ) {
  fputs("$timescale 1ps $end\n", f);
  fputs("$scope module Main $end\n", f);
  fputs("$var wire 1 \x21 clk $end\n", f);
  fputs("$var wire 1 \x22 reset $end\n", f);
  fputs("$var wire 1 \x29 io_lc_din_valid $end\n", f);
  fputs("$var wire 1 \x2c io_le_din_valid $end\n", f);
  fputs("$var wire 1 \x2f io_dn_din_valid $end\n", f);
  fputs("$var wire 1 \x32 io_r_din_valid $end\n", f);
  fputs("$var wire 1 \x35 io_up_din_valid $end\n", f);
  fputs("$var wire 1 \x3a io_lc_dout_valid $end\n", f);
  fputs("$var wire 1 \x3c io_r_dout_valid $end\n", f);
  fputs("$var wire 1 \x3e io_le_dout_valid $end\n", f);
  fputs("$var wire 1 \x40 io_up_dout_valid $end\n", f);
  fputs("$var wire 1 \x42 io_dn_dout_valid $end\n", f);
  fputs("$var wire 32 \x5a io_lc_din_data $end\n", f);
  fputs("$var wire 32 \x5d io_le_din_data $end\n", f);
  fputs("$var wire 32 \x60 io_dn_din_data $end\n", f);
  fputs("$var wire 32 \x63 io_r_din_data $end\n", f);
  fputs("$var wire 32 \x66 io_up_din_data $end\n", f);
  fputs("$var wire 32 \x6b io_lc_dout_data $end\n", f);
  fputs("$var wire 32 \x6d io_r_dout_data $end\n", f);
  fputs("$var wire 32 \x6f io_le_dout_data $end\n", f);
  fputs("$var wire 32 \x71 io_up_dout_data $end\n", f);
  fputs("$var wire 32 \x73 io_dn_dout_data $end\n", f);
  fputs("$scope module schedule_table $end\n", f);
  fputs("$var wire 3 \x43 io_dir_rInfo_local $end\n", f);
  fputs("$var wire 3 \x46 io_dir_rInfo_right $end\n", f);
  fputs("$var wire 3 \x49 io_dir_rInfo_left $end\n", f);
  fputs("$var wire 3 \x4c io_dir_rInfo_up $end\n", f);
  fputs("$var wire 3 \x4f io_dir_rInfo_down $end\n", f);
  fputs("$var wire 16 \x53 io_dir_slotCounter $end\n", f);
  fputs("$upscope $end\n", f);
  fputs("$scope module route $end\n", f);
  fputs("$var wire 1 \x23 reset $end\n", f);
  fputs("$var wire 1 \x24 dout_local_valid $end\n", f);
  fputs("$var wire 1 \x25 io_ready $end\n", f);
  fputs("$var wire 1 \x26 dout_right_valid $end\n", f);
  fputs("$var wire 1 \x27 dout_left_valid $end\n", f);
  fputs("$var wire 1 \x28 dout_up_valid $end\n", f);
  fputs("$var wire 1 \x2a io_lc_din_valid $end\n", f);
  fputs("$var wire 1 \x2b din_local_valid $end\n", f);
  fputs("$var wire 1 \x2d io_le_din_valid $end\n", f);
  fputs("$var wire 1 \x2e din_left_valid $end\n", f);
  fputs("$var wire 1 \x30 io_dn_din_valid $end\n", f);
  fputs("$var wire 1 \x31 din_down_valid $end\n", f);
  fputs("$var wire 1 \x33 io_r_din_valid $end\n", f);
  fputs("$var wire 1 \x34 din_right_valid $end\n", f);
  fputs("$var wire 1 \x36 io_up_din_valid $end\n", f);
  fputs("$var wire 1 \x37 din_up_valid $end\n", f);
  fputs("$var wire 1 \x38 dout_down_valid $end\n", f);
  fputs("$var wire 1 \x39 io_lc_dout_valid $end\n", f);
  fputs("$var wire 1 \x3b io_r_dout_valid $end\n", f);
  fputs("$var wire 1 \x3d io_le_dout_valid $end\n", f);
  fputs("$var wire 1 \x3f io_up_dout_valid $end\n", f);
  fputs("$var wire 1 \x41 io_dn_dout_valid $end\n", f);
  fputs("$var wire 3 \x44 io_routeInfo_rInfo_local $end\n", f);
  fputs("$var wire 3 \x45 directions_local $end\n", f);
  fputs("$var wire 3 \x47 io_routeInfo_rInfo_right $end\n", f);
  fputs("$var wire 3 \x48 directions_right $end\n", f);
  fputs("$var wire 3 \x4a io_routeInfo_rInfo_left $end\n", f);
  fputs("$var wire 3 \x4b directions_left $end\n", f);
  fputs("$var wire 3 \x4d io_routeInfo_rInfo_up $end\n", f);
  fputs("$var wire 3 \x4e directions_up $end\n", f);
  fputs("$var wire 3 \x50 io_routeInfo_rInfo_down $end\n", f);
  fputs("$var wire 3 \x51 directions_down $end\n", f);
  fputs("$var wire 16 \x52 io_routeInfo_slotCounter $end\n", f);
  fputs("$var wire 19 \x54 reg_slotCount $end\n", f);
  fputs("$var wire 32 \x55 dout_local_data $end\n", f);
  fputs("$var wire 32 \x56 io_test $end\n", f);
  fputs("$var wire 32 \x57 dout_right_data $end\n", f);
  fputs("$var wire 32 \x58 dout_left_data $end\n", f);
  fputs("$var wire 32 \x59 dout_up_data $end\n", f);
  fputs("$var wire 32 \x5b io_lc_din_data $end\n", f);
  fputs("$var wire 32 \x5c din_local_data $end\n", f);
  fputs("$var wire 32 \x5e io_le_din_data $end\n", f);
  fputs("$var wire 32 \x5f din_left_data $end\n", f);
  fputs("$var wire 32 \x61 io_dn_din_data $end\n", f);
  fputs("$var wire 32 \x62 din_down_data $end\n", f);
  fputs("$var wire 32 \x64 io_r_din_data $end\n", f);
  fputs("$var wire 32 \x65 din_right_data $end\n", f);
  fputs("$var wire 32 \x67 io_up_din_data $end\n", f);
  fputs("$var wire 32 \x68 din_up_data $end\n", f);
  fputs("$var wire 32 \x69 dout_down_data $end\n", f);
  fputs("$var wire 32 \x6a io_lc_dout_data $end\n", f);
  fputs("$var wire 32 \x6c io_r_dout_data $end\n", f);
  fputs("$var wire 32 \x6e io_le_dout_data $end\n", f);
  fputs("$var wire 32 \x70 io_up_dout_data $end\n", f);
  fputs("$var wire 32 \x72 io_dn_dout_data $end\n", f);
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
  dat_dump<1>(f, Main_route__reset, 0x23);
  Main_route__reset__prev = Main_route__reset;
  dat_dump<1>(f, Main_route__dout_local_valid, 0x24);
  Main_route__dout_local_valid__prev = Main_route__dout_local_valid;
  dat_dump<1>(f, Main_route__io_ready, 0x25);
  Main_route__io_ready__prev = Main_route__io_ready;
  dat_dump<1>(f, Main_route__dout_right_valid, 0x26);
  Main_route__dout_right_valid__prev = Main_route__dout_right_valid;
  dat_dump<1>(f, Main_route__dout_left_valid, 0x27);
  Main_route__dout_left_valid__prev = Main_route__dout_left_valid;
  dat_dump<1>(f, Main_route__dout_up_valid, 0x28);
  Main_route__dout_up_valid__prev = Main_route__dout_up_valid;
  dat_dump<1>(f, Main__io_lc_din_valid, 0x29);
  Main__io_lc_din_valid__prev = Main__io_lc_din_valid;
  dat_dump<1>(f, Main_route__io_lc_din_valid, 0x2a);
  Main_route__io_lc_din_valid__prev = Main_route__io_lc_din_valid;
  dat_dump<1>(f, Main_route__din_local_valid, 0x2b);
  Main_route__din_local_valid__prev = Main_route__din_local_valid;
  dat_dump<1>(f, Main__io_le_din_valid, 0x2c);
  Main__io_le_din_valid__prev = Main__io_le_din_valid;
  dat_dump<1>(f, Main_route__io_le_din_valid, 0x2d);
  Main_route__io_le_din_valid__prev = Main_route__io_le_din_valid;
  dat_dump<1>(f, Main_route__din_left_valid, 0x2e);
  Main_route__din_left_valid__prev = Main_route__din_left_valid;
  dat_dump<1>(f, Main__io_dn_din_valid, 0x2f);
  Main__io_dn_din_valid__prev = Main__io_dn_din_valid;
  dat_dump<1>(f, Main_route__io_dn_din_valid, 0x30);
  Main_route__io_dn_din_valid__prev = Main_route__io_dn_din_valid;
  dat_dump<1>(f, Main_route__din_down_valid, 0x31);
  Main_route__din_down_valid__prev = Main_route__din_down_valid;
  dat_dump<1>(f, Main__io_r_din_valid, 0x32);
  Main__io_r_din_valid__prev = Main__io_r_din_valid;
  dat_dump<1>(f, Main_route__io_r_din_valid, 0x33);
  Main_route__io_r_din_valid__prev = Main_route__io_r_din_valid;
  dat_dump<1>(f, Main_route__din_right_valid, 0x34);
  Main_route__din_right_valid__prev = Main_route__din_right_valid;
  dat_dump<1>(f, Main__io_up_din_valid, 0x35);
  Main__io_up_din_valid__prev = Main__io_up_din_valid;
  dat_dump<1>(f, Main_route__io_up_din_valid, 0x36);
  Main_route__io_up_din_valid__prev = Main_route__io_up_din_valid;
  dat_dump<1>(f, Main_route__din_up_valid, 0x37);
  Main_route__din_up_valid__prev = Main_route__din_up_valid;
  dat_dump<1>(f, Main_route__dout_down_valid, 0x38);
  Main_route__dout_down_valid__prev = Main_route__dout_down_valid;
  dat_dump<1>(f, Main_route__io_lc_dout_valid, 0x39);
  Main_route__io_lc_dout_valid__prev = Main_route__io_lc_dout_valid;
  dat_dump<1>(f, Main__io_lc_dout_valid, 0x3a);
  Main__io_lc_dout_valid__prev = Main__io_lc_dout_valid;
  dat_dump<1>(f, Main_route__io_r_dout_valid, 0x3b);
  Main_route__io_r_dout_valid__prev = Main_route__io_r_dout_valid;
  dat_dump<1>(f, Main__io_r_dout_valid, 0x3c);
  Main__io_r_dout_valid__prev = Main__io_r_dout_valid;
  dat_dump<1>(f, Main_route__io_le_dout_valid, 0x3d);
  Main_route__io_le_dout_valid__prev = Main_route__io_le_dout_valid;
  dat_dump<1>(f, Main__io_le_dout_valid, 0x3e);
  Main__io_le_dout_valid__prev = Main__io_le_dout_valid;
  dat_dump<1>(f, Main_route__io_up_dout_valid, 0x3f);
  Main_route__io_up_dout_valid__prev = Main_route__io_up_dout_valid;
  dat_dump<1>(f, Main__io_up_dout_valid, 0x40);
  Main__io_up_dout_valid__prev = Main__io_up_dout_valid;
  dat_dump<1>(f, Main_route__io_dn_dout_valid, 0x41);
  Main_route__io_dn_dout_valid__prev = Main_route__io_dn_dout_valid;
  dat_dump<1>(f, Main__io_dn_dout_valid, 0x42);
  Main__io_dn_dout_valid__prev = Main__io_dn_dout_valid;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_local, 0x43);
  Main_schedule_table__io_dir_rInfo_local__prev = Main_schedule_table__io_dir_rInfo_local;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_local, 0x44);
  Main_route__io_routeInfo_rInfo_local__prev = Main_route__io_routeInfo_rInfo_local;
  dat_dump<1>(f, Main_route__directions_local, 0x45);
  Main_route__directions_local__prev = Main_route__directions_local;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_right, 0x46);
  Main_schedule_table__io_dir_rInfo_right__prev = Main_schedule_table__io_dir_rInfo_right;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_right, 0x47);
  Main_route__io_routeInfo_rInfo_right__prev = Main_route__io_routeInfo_rInfo_right;
  dat_dump<1>(f, Main_route__directions_right, 0x48);
  Main_route__directions_right__prev = Main_route__directions_right;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_left, 0x49);
  Main_schedule_table__io_dir_rInfo_left__prev = Main_schedule_table__io_dir_rInfo_left;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_left, 0x4a);
  Main_route__io_routeInfo_rInfo_left__prev = Main_route__io_routeInfo_rInfo_left;
  dat_dump<1>(f, Main_route__directions_left, 0x4b);
  Main_route__directions_left__prev = Main_route__directions_left;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_up, 0x4c);
  Main_schedule_table__io_dir_rInfo_up__prev = Main_schedule_table__io_dir_rInfo_up;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_up, 0x4d);
  Main_route__io_routeInfo_rInfo_up__prev = Main_route__io_routeInfo_rInfo_up;
  dat_dump<1>(f, Main_route__directions_up, 0x4e);
  Main_route__directions_up__prev = Main_route__directions_up;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_down, 0x4f);
  Main_schedule_table__io_dir_rInfo_down__prev = Main_schedule_table__io_dir_rInfo_down;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_down, 0x50);
  Main_route__io_routeInfo_rInfo_down__prev = Main_route__io_routeInfo_rInfo_down;
  dat_dump<1>(f, Main_route__directions_down, 0x51);
  Main_route__directions_down__prev = Main_route__directions_down;
  dat_dump<1>(f, Main_route__io_routeInfo_slotCounter, 0x52);
  Main_route__io_routeInfo_slotCounter__prev = Main_route__io_routeInfo_slotCounter;
  dat_dump<1>(f, Main_schedule_table__io_dir_slotCounter, 0x53);
  Main_schedule_table__io_dir_slotCounter__prev = Main_schedule_table__io_dir_slotCounter;
  dat_dump<1>(f, Main_route__reg_slotCount, 0x54);
  Main_route__reg_slotCount__prev = Main_route__reg_slotCount;
  dat_dump<1>(f, Main_route__dout_local_data, 0x55);
  Main_route__dout_local_data__prev = Main_route__dout_local_data;
  dat_dump<1>(f, Main_route__io_test, 0x56);
  Main_route__io_test__prev = Main_route__io_test;
  dat_dump<1>(f, Main_route__dout_right_data, 0x57);
  Main_route__dout_right_data__prev = Main_route__dout_right_data;
  dat_dump<1>(f, Main_route__dout_left_data, 0x58);
  Main_route__dout_left_data__prev = Main_route__dout_left_data;
  dat_dump<1>(f, Main_route__dout_up_data, 0x59);
  Main_route__dout_up_data__prev = Main_route__dout_up_data;
  dat_dump<1>(f, Main__io_lc_din_data, 0x5a);
  Main__io_lc_din_data__prev = Main__io_lc_din_data;
  dat_dump<1>(f, Main_route__io_lc_din_data, 0x5b);
  Main_route__io_lc_din_data__prev = Main_route__io_lc_din_data;
  dat_dump<1>(f, Main_route__din_local_data, 0x5c);
  Main_route__din_local_data__prev = Main_route__din_local_data;
  dat_dump<1>(f, Main__io_le_din_data, 0x5d);
  Main__io_le_din_data__prev = Main__io_le_din_data;
  dat_dump<1>(f, Main_route__io_le_din_data, 0x5e);
  Main_route__io_le_din_data__prev = Main_route__io_le_din_data;
  dat_dump<1>(f, Main_route__din_left_data, 0x5f);
  Main_route__din_left_data__prev = Main_route__din_left_data;
  dat_dump<1>(f, Main__io_dn_din_data, 0x60);
  Main__io_dn_din_data__prev = Main__io_dn_din_data;
  dat_dump<1>(f, Main_route__io_dn_din_data, 0x61);
  Main_route__io_dn_din_data__prev = Main_route__io_dn_din_data;
  dat_dump<1>(f, Main_route__din_down_data, 0x62);
  Main_route__din_down_data__prev = Main_route__din_down_data;
  dat_dump<1>(f, Main__io_r_din_data, 0x63);
  Main__io_r_din_data__prev = Main__io_r_din_data;
  dat_dump<1>(f, Main_route__io_r_din_data, 0x64);
  Main_route__io_r_din_data__prev = Main_route__io_r_din_data;
  dat_dump<1>(f, Main_route__din_right_data, 0x65);
  Main_route__din_right_data__prev = Main_route__din_right_data;
  dat_dump<1>(f, Main__io_up_din_data, 0x66);
  Main__io_up_din_data__prev = Main__io_up_din_data;
  dat_dump<1>(f, Main_route__io_up_din_data, 0x67);
  Main_route__io_up_din_data__prev = Main_route__io_up_din_data;
  dat_dump<1>(f, Main_route__din_up_data, 0x68);
  Main_route__din_up_data__prev = Main_route__din_up_data;
  dat_dump<1>(f, Main_route__dout_down_data, 0x69);
  Main_route__dout_down_data__prev = Main_route__dout_down_data;
  dat_dump<1>(f, Main_route__io_lc_dout_data, 0x6a);
  Main_route__io_lc_dout_data__prev = Main_route__io_lc_dout_data;
  dat_dump<1>(f, Main__io_lc_dout_data, 0x6b);
  Main__io_lc_dout_data__prev = Main__io_lc_dout_data;
  dat_dump<1>(f, Main_route__io_r_dout_data, 0x6c);
  Main_route__io_r_dout_data__prev = Main_route__io_r_dout_data;
  dat_dump<1>(f, Main__io_r_dout_data, 0x6d);
  Main__io_r_dout_data__prev = Main__io_r_dout_data;
  dat_dump<1>(f, Main_route__io_le_dout_data, 0x6e);
  Main_route__io_le_dout_data__prev = Main_route__io_le_dout_data;
  dat_dump<1>(f, Main__io_le_dout_data, 0x6f);
  Main__io_le_dout_data__prev = Main__io_le_dout_data;
  dat_dump<1>(f, Main_route__io_up_dout_data, 0x70);
  Main_route__io_up_dout_data__prev = Main_route__io_up_dout_data;
  dat_dump<1>(f, Main__io_up_dout_data, 0x71);
  Main__io_up_dout_data__prev = Main__io_up_dout_data;
  dat_dump<1>(f, Main_route__io_dn_dout_data, 0x72);
  Main_route__io_dn_dout_data__prev = Main_route__io_dn_dout_data;
  dat_dump<1>(f, Main__io_dn_dout_data, 0x73);
  Main__io_dn_dout_data__prev = Main__io_dn_dout_data;
  fputs("#1\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 0;
    dat_dump<1>(f, clk, 0x21);
  }
}


void Main_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
  if (t == 0L) return dump_init(f);
  fprintf(f, "#%lu\n", t << 1);
  if (clk.cnt == 0)  goto L0;
K0:  if (reset != reset__prev)  goto L1;
K1:  if (Main_route__reset != Main_route__reset__prev)  goto L2;
K2:  if (Main_route__dout_local_valid != Main_route__dout_local_valid__prev)  goto L3;
K3:  if (Main_route__io_ready != Main_route__io_ready__prev)  goto L4;
K4:  if (Main_route__dout_right_valid != Main_route__dout_right_valid__prev)  goto L5;
K5:  if (Main_route__dout_left_valid != Main_route__dout_left_valid__prev)  goto L6;
K6:  if (Main_route__dout_up_valid != Main_route__dout_up_valid__prev)  goto L7;
K7:  if (Main__io_lc_din_valid != Main__io_lc_din_valid__prev)  goto L8;
K8:  if (Main_route__io_lc_din_valid != Main_route__io_lc_din_valid__prev)  goto L9;
K9:  if (Main_route__din_local_valid != Main_route__din_local_valid__prev)  goto L10;
K10:  if (Main__io_le_din_valid != Main__io_le_din_valid__prev)  goto L11;
K11:  if (Main_route__io_le_din_valid != Main_route__io_le_din_valid__prev)  goto L12;
K12:  if (Main_route__din_left_valid != Main_route__din_left_valid__prev)  goto L13;
K13:  if (Main__io_dn_din_valid != Main__io_dn_din_valid__prev)  goto L14;
K14:  if (Main_route__io_dn_din_valid != Main_route__io_dn_din_valid__prev)  goto L15;
K15:  if (Main_route__din_down_valid != Main_route__din_down_valid__prev)  goto L16;
K16:  if (Main__io_r_din_valid != Main__io_r_din_valid__prev)  goto L17;
K17:  if (Main_route__io_r_din_valid != Main_route__io_r_din_valid__prev)  goto L18;
K18:  if (Main_route__din_right_valid != Main_route__din_right_valid__prev)  goto L19;
K19:  if (Main__io_up_din_valid != Main__io_up_din_valid__prev)  goto L20;
K20:  if (Main_route__io_up_din_valid != Main_route__io_up_din_valid__prev)  goto L21;
K21:  if (Main_route__din_up_valid != Main_route__din_up_valid__prev)  goto L22;
K22:  if (Main_route__dout_down_valid != Main_route__dout_down_valid__prev)  goto L23;
K23:  if (Main_route__io_lc_dout_valid != Main_route__io_lc_dout_valid__prev)  goto L24;
K24:  if (Main__io_lc_dout_valid != Main__io_lc_dout_valid__prev)  goto L25;
K25:  if (Main_route__io_r_dout_valid != Main_route__io_r_dout_valid__prev)  goto L26;
K26:  if (Main__io_r_dout_valid != Main__io_r_dout_valid__prev)  goto L27;
K27:  if (Main_route__io_le_dout_valid != Main_route__io_le_dout_valid__prev)  goto L28;
K28:  if (Main__io_le_dout_valid != Main__io_le_dout_valid__prev)  goto L29;
K29:  if (Main_route__io_up_dout_valid != Main_route__io_up_dout_valid__prev)  goto L30;
K30:  if (Main__io_up_dout_valid != Main__io_up_dout_valid__prev)  goto L31;
K31:  if (Main_route__io_dn_dout_valid != Main_route__io_dn_dout_valid__prev)  goto L32;
K32:  if (Main__io_dn_dout_valid != Main__io_dn_dout_valid__prev)  goto L33;
K33:  if (Main_schedule_table__io_dir_rInfo_local != Main_schedule_table__io_dir_rInfo_local__prev)  goto L34;
K34:  if (Main_route__io_routeInfo_rInfo_local != Main_route__io_routeInfo_rInfo_local__prev)  goto L35;
K35:  if (Main_route__directions_local != Main_route__directions_local__prev)  goto L36;
K36:  if (Main_schedule_table__io_dir_rInfo_right != Main_schedule_table__io_dir_rInfo_right__prev)  goto L37;
K37:  if (Main_route__io_routeInfo_rInfo_right != Main_route__io_routeInfo_rInfo_right__prev)  goto L38;
K38:  if (Main_route__directions_right != Main_route__directions_right__prev)  goto L39;
K39:  if (Main_schedule_table__io_dir_rInfo_left != Main_schedule_table__io_dir_rInfo_left__prev)  goto L40;
K40:  if (Main_route__io_routeInfo_rInfo_left != Main_route__io_routeInfo_rInfo_left__prev)  goto L41;
K41:  if (Main_route__directions_left != Main_route__directions_left__prev)  goto L42;
K42:  if (Main_schedule_table__io_dir_rInfo_up != Main_schedule_table__io_dir_rInfo_up__prev)  goto L43;
K43:  if (Main_route__io_routeInfo_rInfo_up != Main_route__io_routeInfo_rInfo_up__prev)  goto L44;
K44:  if (Main_route__directions_up != Main_route__directions_up__prev)  goto L45;
K45:  if (Main_schedule_table__io_dir_rInfo_down != Main_schedule_table__io_dir_rInfo_down__prev)  goto L46;
K46:  if (Main_route__io_routeInfo_rInfo_down != Main_route__io_routeInfo_rInfo_down__prev)  goto L47;
K47:  if (Main_route__directions_down != Main_route__directions_down__prev)  goto L48;
K48:  if (Main_route__io_routeInfo_slotCounter != Main_route__io_routeInfo_slotCounter__prev)  goto L49;
K49:  if (Main_schedule_table__io_dir_slotCounter != Main_schedule_table__io_dir_slotCounter__prev)  goto L50;
K50:  if (Main_route__reg_slotCount != Main_route__reg_slotCount__prev)  goto L51;
K51:  if (Main_route__dout_local_data != Main_route__dout_local_data__prev)  goto L52;
K52:  if (Main_route__io_test != Main_route__io_test__prev)  goto L53;
K53:  if (Main_route__dout_right_data != Main_route__dout_right_data__prev)  goto L54;
K54:  if (Main_route__dout_left_data != Main_route__dout_left_data__prev)  goto L55;
K55:  if (Main_route__dout_up_data != Main_route__dout_up_data__prev)  goto L56;
K56:  if (Main__io_lc_din_data != Main__io_lc_din_data__prev)  goto L57;
K57:  if (Main_route__io_lc_din_data != Main_route__io_lc_din_data__prev)  goto L58;
K58:  if (Main_route__din_local_data != Main_route__din_local_data__prev)  goto L59;
K59:  if (Main__io_le_din_data != Main__io_le_din_data__prev)  goto L60;
K60:  if (Main_route__io_le_din_data != Main_route__io_le_din_data__prev)  goto L61;
K61:  if (Main_route__din_left_data != Main_route__din_left_data__prev)  goto L62;
K62:  if (Main__io_dn_din_data != Main__io_dn_din_data__prev)  goto L63;
K63:  if (Main_route__io_dn_din_data != Main_route__io_dn_din_data__prev)  goto L64;
K64:  if (Main_route__din_down_data != Main_route__din_down_data__prev)  goto L65;
K65:  if (Main__io_r_din_data != Main__io_r_din_data__prev)  goto L66;
K66:  if (Main_route__io_r_din_data != Main_route__io_r_din_data__prev)  goto L67;
K67:  if (Main_route__din_right_data != Main_route__din_right_data__prev)  goto L68;
K68:  if (Main__io_up_din_data != Main__io_up_din_data__prev)  goto L69;
K69:  if (Main_route__io_up_din_data != Main_route__io_up_din_data__prev)  goto L70;
K70:  if (Main_route__din_up_data != Main_route__din_up_data__prev)  goto L71;
K71:  if (Main_route__dout_down_data != Main_route__dout_down_data__prev)  goto L72;
K72:  if (Main_route__io_lc_dout_data != Main_route__io_lc_dout_data__prev)  goto L73;
K73:  if (Main__io_lc_dout_data != Main__io_lc_dout_data__prev)  goto L74;
K74:  if (Main_route__io_r_dout_data != Main_route__io_r_dout_data__prev)  goto L75;
K75:  if (Main__io_r_dout_data != Main__io_r_dout_data__prev)  goto L76;
K76:  if (Main_route__io_le_dout_data != Main_route__io_le_dout_data__prev)  goto L77;
K77:  if (Main__io_le_dout_data != Main__io_le_dout_data__prev)  goto L78;
K78:  if (Main_route__io_up_dout_data != Main_route__io_up_dout_data__prev)  goto L79;
K79:  if (Main__io_up_dout_data != Main__io_up_dout_data__prev)  goto L80;
K80:  if (Main_route__io_dn_dout_data != Main_route__io_dn_dout_data__prev)  goto L81;
K81:  if (Main__io_dn_dout_data != Main__io_dn_dout_data__prev)  goto L82;
K82:  fprintf(f, "#%lu\n", (t << 1) + 1);
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
  Main_route__reset__prev = Main_route__reset;
  dat_dump<1>(f, Main_route__reset, 0x23);
  goto K2;
L3:
  Main_route__dout_local_valid__prev = Main_route__dout_local_valid;
  dat_dump<1>(f, Main_route__dout_local_valid, 0x24);
  goto K3;
L4:
  Main_route__io_ready__prev = Main_route__io_ready;
  dat_dump<1>(f, Main_route__io_ready, 0x25);
  goto K4;
L5:
  Main_route__dout_right_valid__prev = Main_route__dout_right_valid;
  dat_dump<1>(f, Main_route__dout_right_valid, 0x26);
  goto K5;
L6:
  Main_route__dout_left_valid__prev = Main_route__dout_left_valid;
  dat_dump<1>(f, Main_route__dout_left_valid, 0x27);
  goto K6;
L7:
  Main_route__dout_up_valid__prev = Main_route__dout_up_valid;
  dat_dump<1>(f, Main_route__dout_up_valid, 0x28);
  goto K7;
L8:
  Main__io_lc_din_valid__prev = Main__io_lc_din_valid;
  dat_dump<1>(f, Main__io_lc_din_valid, 0x29);
  goto K8;
L9:
  Main_route__io_lc_din_valid__prev = Main_route__io_lc_din_valid;
  dat_dump<1>(f, Main_route__io_lc_din_valid, 0x2a);
  goto K9;
L10:
  Main_route__din_local_valid__prev = Main_route__din_local_valid;
  dat_dump<1>(f, Main_route__din_local_valid, 0x2b);
  goto K10;
L11:
  Main__io_le_din_valid__prev = Main__io_le_din_valid;
  dat_dump<1>(f, Main__io_le_din_valid, 0x2c);
  goto K11;
L12:
  Main_route__io_le_din_valid__prev = Main_route__io_le_din_valid;
  dat_dump<1>(f, Main_route__io_le_din_valid, 0x2d);
  goto K12;
L13:
  Main_route__din_left_valid__prev = Main_route__din_left_valid;
  dat_dump<1>(f, Main_route__din_left_valid, 0x2e);
  goto K13;
L14:
  Main__io_dn_din_valid__prev = Main__io_dn_din_valid;
  dat_dump<1>(f, Main__io_dn_din_valid, 0x2f);
  goto K14;
L15:
  Main_route__io_dn_din_valid__prev = Main_route__io_dn_din_valid;
  dat_dump<1>(f, Main_route__io_dn_din_valid, 0x30);
  goto K15;
L16:
  Main_route__din_down_valid__prev = Main_route__din_down_valid;
  dat_dump<1>(f, Main_route__din_down_valid, 0x31);
  goto K16;
L17:
  Main__io_r_din_valid__prev = Main__io_r_din_valid;
  dat_dump<1>(f, Main__io_r_din_valid, 0x32);
  goto K17;
L18:
  Main_route__io_r_din_valid__prev = Main_route__io_r_din_valid;
  dat_dump<1>(f, Main_route__io_r_din_valid, 0x33);
  goto K18;
L19:
  Main_route__din_right_valid__prev = Main_route__din_right_valid;
  dat_dump<1>(f, Main_route__din_right_valid, 0x34);
  goto K19;
L20:
  Main__io_up_din_valid__prev = Main__io_up_din_valid;
  dat_dump<1>(f, Main__io_up_din_valid, 0x35);
  goto K20;
L21:
  Main_route__io_up_din_valid__prev = Main_route__io_up_din_valid;
  dat_dump<1>(f, Main_route__io_up_din_valid, 0x36);
  goto K21;
L22:
  Main_route__din_up_valid__prev = Main_route__din_up_valid;
  dat_dump<1>(f, Main_route__din_up_valid, 0x37);
  goto K22;
L23:
  Main_route__dout_down_valid__prev = Main_route__dout_down_valid;
  dat_dump<1>(f, Main_route__dout_down_valid, 0x38);
  goto K23;
L24:
  Main_route__io_lc_dout_valid__prev = Main_route__io_lc_dout_valid;
  dat_dump<1>(f, Main_route__io_lc_dout_valid, 0x39);
  goto K24;
L25:
  Main__io_lc_dout_valid__prev = Main__io_lc_dout_valid;
  dat_dump<1>(f, Main__io_lc_dout_valid, 0x3a);
  goto K25;
L26:
  Main_route__io_r_dout_valid__prev = Main_route__io_r_dout_valid;
  dat_dump<1>(f, Main_route__io_r_dout_valid, 0x3b);
  goto K26;
L27:
  Main__io_r_dout_valid__prev = Main__io_r_dout_valid;
  dat_dump<1>(f, Main__io_r_dout_valid, 0x3c);
  goto K27;
L28:
  Main_route__io_le_dout_valid__prev = Main_route__io_le_dout_valid;
  dat_dump<1>(f, Main_route__io_le_dout_valid, 0x3d);
  goto K28;
L29:
  Main__io_le_dout_valid__prev = Main__io_le_dout_valid;
  dat_dump<1>(f, Main__io_le_dout_valid, 0x3e);
  goto K29;
L30:
  Main_route__io_up_dout_valid__prev = Main_route__io_up_dout_valid;
  dat_dump<1>(f, Main_route__io_up_dout_valid, 0x3f);
  goto K30;
L31:
  Main__io_up_dout_valid__prev = Main__io_up_dout_valid;
  dat_dump<1>(f, Main__io_up_dout_valid, 0x40);
  goto K31;
L32:
  Main_route__io_dn_dout_valid__prev = Main_route__io_dn_dout_valid;
  dat_dump<1>(f, Main_route__io_dn_dout_valid, 0x41);
  goto K32;
L33:
  Main__io_dn_dout_valid__prev = Main__io_dn_dout_valid;
  dat_dump<1>(f, Main__io_dn_dout_valid, 0x42);
  goto K33;
L34:
  Main_schedule_table__io_dir_rInfo_local__prev = Main_schedule_table__io_dir_rInfo_local;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_local, 0x43);
  goto K34;
L35:
  Main_route__io_routeInfo_rInfo_local__prev = Main_route__io_routeInfo_rInfo_local;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_local, 0x44);
  goto K35;
L36:
  Main_route__directions_local__prev = Main_route__directions_local;
  dat_dump<1>(f, Main_route__directions_local, 0x45);
  goto K36;
L37:
  Main_schedule_table__io_dir_rInfo_right__prev = Main_schedule_table__io_dir_rInfo_right;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_right, 0x46);
  goto K37;
L38:
  Main_route__io_routeInfo_rInfo_right__prev = Main_route__io_routeInfo_rInfo_right;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_right, 0x47);
  goto K38;
L39:
  Main_route__directions_right__prev = Main_route__directions_right;
  dat_dump<1>(f, Main_route__directions_right, 0x48);
  goto K39;
L40:
  Main_schedule_table__io_dir_rInfo_left__prev = Main_schedule_table__io_dir_rInfo_left;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_left, 0x49);
  goto K40;
L41:
  Main_route__io_routeInfo_rInfo_left__prev = Main_route__io_routeInfo_rInfo_left;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_left, 0x4a);
  goto K41;
L42:
  Main_route__directions_left__prev = Main_route__directions_left;
  dat_dump<1>(f, Main_route__directions_left, 0x4b);
  goto K42;
L43:
  Main_schedule_table__io_dir_rInfo_up__prev = Main_schedule_table__io_dir_rInfo_up;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_up, 0x4c);
  goto K43;
L44:
  Main_route__io_routeInfo_rInfo_up__prev = Main_route__io_routeInfo_rInfo_up;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_up, 0x4d);
  goto K44;
L45:
  Main_route__directions_up__prev = Main_route__directions_up;
  dat_dump<1>(f, Main_route__directions_up, 0x4e);
  goto K45;
L46:
  Main_schedule_table__io_dir_rInfo_down__prev = Main_schedule_table__io_dir_rInfo_down;
  dat_dump<1>(f, Main_schedule_table__io_dir_rInfo_down, 0x4f);
  goto K46;
L47:
  Main_route__io_routeInfo_rInfo_down__prev = Main_route__io_routeInfo_rInfo_down;
  dat_dump<1>(f, Main_route__io_routeInfo_rInfo_down, 0x50);
  goto K47;
L48:
  Main_route__directions_down__prev = Main_route__directions_down;
  dat_dump<1>(f, Main_route__directions_down, 0x51);
  goto K48;
L49:
  Main_route__io_routeInfo_slotCounter__prev = Main_route__io_routeInfo_slotCounter;
  dat_dump<1>(f, Main_route__io_routeInfo_slotCounter, 0x52);
  goto K49;
L50:
  Main_schedule_table__io_dir_slotCounter__prev = Main_schedule_table__io_dir_slotCounter;
  dat_dump<1>(f, Main_schedule_table__io_dir_slotCounter, 0x53);
  goto K50;
L51:
  Main_route__reg_slotCount__prev = Main_route__reg_slotCount;
  dat_dump<1>(f, Main_route__reg_slotCount, 0x54);
  goto K51;
L52:
  Main_route__dout_local_data__prev = Main_route__dout_local_data;
  dat_dump<1>(f, Main_route__dout_local_data, 0x55);
  goto K52;
L53:
  Main_route__io_test__prev = Main_route__io_test;
  dat_dump<1>(f, Main_route__io_test, 0x56);
  goto K53;
L54:
  Main_route__dout_right_data__prev = Main_route__dout_right_data;
  dat_dump<1>(f, Main_route__dout_right_data, 0x57);
  goto K54;
L55:
  Main_route__dout_left_data__prev = Main_route__dout_left_data;
  dat_dump<1>(f, Main_route__dout_left_data, 0x58);
  goto K55;
L56:
  Main_route__dout_up_data__prev = Main_route__dout_up_data;
  dat_dump<1>(f, Main_route__dout_up_data, 0x59);
  goto K56;
L57:
  Main__io_lc_din_data__prev = Main__io_lc_din_data;
  dat_dump<1>(f, Main__io_lc_din_data, 0x5a);
  goto K57;
L58:
  Main_route__io_lc_din_data__prev = Main_route__io_lc_din_data;
  dat_dump<1>(f, Main_route__io_lc_din_data, 0x5b);
  goto K58;
L59:
  Main_route__din_local_data__prev = Main_route__din_local_data;
  dat_dump<1>(f, Main_route__din_local_data, 0x5c);
  goto K59;
L60:
  Main__io_le_din_data__prev = Main__io_le_din_data;
  dat_dump<1>(f, Main__io_le_din_data, 0x5d);
  goto K60;
L61:
  Main_route__io_le_din_data__prev = Main_route__io_le_din_data;
  dat_dump<1>(f, Main_route__io_le_din_data, 0x5e);
  goto K61;
L62:
  Main_route__din_left_data__prev = Main_route__din_left_data;
  dat_dump<1>(f, Main_route__din_left_data, 0x5f);
  goto K62;
L63:
  Main__io_dn_din_data__prev = Main__io_dn_din_data;
  dat_dump<1>(f, Main__io_dn_din_data, 0x60);
  goto K63;
L64:
  Main_route__io_dn_din_data__prev = Main_route__io_dn_din_data;
  dat_dump<1>(f, Main_route__io_dn_din_data, 0x61);
  goto K64;
L65:
  Main_route__din_down_data__prev = Main_route__din_down_data;
  dat_dump<1>(f, Main_route__din_down_data, 0x62);
  goto K65;
L66:
  Main__io_r_din_data__prev = Main__io_r_din_data;
  dat_dump<1>(f, Main__io_r_din_data, 0x63);
  goto K66;
L67:
  Main_route__io_r_din_data__prev = Main_route__io_r_din_data;
  dat_dump<1>(f, Main_route__io_r_din_data, 0x64);
  goto K67;
L68:
  Main_route__din_right_data__prev = Main_route__din_right_data;
  dat_dump<1>(f, Main_route__din_right_data, 0x65);
  goto K68;
L69:
  Main__io_up_din_data__prev = Main__io_up_din_data;
  dat_dump<1>(f, Main__io_up_din_data, 0x66);
  goto K69;
L70:
  Main_route__io_up_din_data__prev = Main_route__io_up_din_data;
  dat_dump<1>(f, Main_route__io_up_din_data, 0x67);
  goto K70;
L71:
  Main_route__din_up_data__prev = Main_route__din_up_data;
  dat_dump<1>(f, Main_route__din_up_data, 0x68);
  goto K71;
L72:
  Main_route__dout_down_data__prev = Main_route__dout_down_data;
  dat_dump<1>(f, Main_route__dout_down_data, 0x69);
  goto K72;
L73:
  Main_route__io_lc_dout_data__prev = Main_route__io_lc_dout_data;
  dat_dump<1>(f, Main_route__io_lc_dout_data, 0x6a);
  goto K73;
L74:
  Main__io_lc_dout_data__prev = Main__io_lc_dout_data;
  dat_dump<1>(f, Main__io_lc_dout_data, 0x6b);
  goto K74;
L75:
  Main_route__io_r_dout_data__prev = Main_route__io_r_dout_data;
  dat_dump<1>(f, Main_route__io_r_dout_data, 0x6c);
  goto K75;
L76:
  Main__io_r_dout_data__prev = Main__io_r_dout_data;
  dat_dump<1>(f, Main__io_r_dout_data, 0x6d);
  goto K76;
L77:
  Main_route__io_le_dout_data__prev = Main_route__io_le_dout_data;
  dat_dump<1>(f, Main_route__io_le_dout_data, 0x6e);
  goto K77;
L78:
  Main__io_le_dout_data__prev = Main__io_le_dout_data;
  dat_dump<1>(f, Main__io_le_dout_data, 0x6f);
  goto K78;
L79:
  Main_route__io_up_dout_data__prev = Main_route__io_up_dout_data;
  dat_dump<1>(f, Main_route__io_up_dout_data, 0x70);
  goto K79;
L80:
  Main__io_up_dout_data__prev = Main__io_up_dout_data;
  dat_dump<1>(f, Main__io_up_dout_data, 0x71);
  goto K80;
L81:
  Main_route__io_dn_dout_data__prev = Main_route__io_dn_dout_data;
  dat_dump<1>(f, Main_route__io_dn_dout_data, 0x72);
  goto K81;
L82:
  Main__io_dn_dout_data__prev = Main__io_dn_dout_data;
  dat_dump<1>(f, Main__io_dn_dout_data, 0x73);
  goto K82;
Z0:
  clk.values[0] = 0;
  dat_dump<1>(f, clk, 0x21);
  goto C0;
}




void Main_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  val_t T0;
  { T0 = Main_route__reg_slotCount.values[0]+0x1L;}
  T0 = T0 & 0x7ffffL;
  { Main_route__reset.values[0] = reset.values[0];}
  { T1.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T0);}
  val_t T2;
  T2 = 0x5L == Main_route__directions_local.values[0];
  val_t T3;
  { T3 = TERNARY_1(T2, Main_route__din_up_data.values[0], Main_route__dout_local_data.values[0]);}
  val_t T4;
  T4 = 0x4L == Main_route__directions_local.values[0];
  val_t T5;
  { T5 = TERNARY_1(T4, Main_route__din_right_data.values[0], T3);}
  val_t T6;
  T6 = 0x2L == Main_route__directions_local.values[0];
  val_t T7;
  { T7 = TERNARY_1(T6, Main_route__din_down_data.values[0], T5);}
  val_t T8;
  T8 = 0x3L == Main_route__directions_local.values[0];
  val_t T9;
  { T9 = TERNARY_1(T8, Main_route__din_left_data.values[0], T7);}
  val_t T10;
  T10 = 0x1L == Main_route__directions_local.values[0];
  val_t T11;
  { T11 = TERNARY_1(T10, Main_route__din_local_data.values[0], T9);}
  val_t T12;
  T12 = 0x0L == Main_route__directions_local.values[0];
  val_t T13;
  { T13 = TERNARY(T12, 0x0L, T11);}
  { T14.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T13);}
  val_t T15;
  { T15 = Main_route__reg_slotCount.values[0];}
  T15 = T15 & 0xffffL;
  { Main_route__io_routeInfo_slotCounter.values[0] = T15;}
  { Main_schedule_table__io_dir_slotCounter.values[0] = Main_route__io_routeInfo_slotCounter.values[0];}
  val_t T16;
  T16 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x0L;
  val_t T17;
  { T17 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T18;
  T18 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x1L;
  val_t T19;
  { T19 = T16 ^ 0x1L;}
  val_t T20;
  { T20 = T19 & T18;}
  val_t T21;
  { T21 = TERNARY(T20, 0x0L, T17);}
  val_t T22;
  T22 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x2L;
  val_t T23;
  { T23 = T16 | T18;}
  val_t T24;
  { T24 = T23 ^ 0x1L;}
  val_t T25;
  { T25 = T24 & T22;}
  val_t T26;
  { T26 = TERNARY(T25, 0x0L, T21);}
  val_t T27;
  T27 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x3L;
  val_t T28;
  { T28 = T23 | T22;}
  val_t T29;
  { T29 = T28 ^ 0x1L;}
  val_t T30;
  { T30 = T29 & T27;}
  val_t T31;
  { T31 = TERNARY(T30, 0x5L, T26);}
  val_t T32;
  T32 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x4L;
  val_t T33;
  { T33 = T28 | T27;}
  val_t T34;
  { T34 = T33 ^ 0x1L;}
  val_t T35;
  { T35 = T34 & T32;}
  val_t T36;
  { T36 = TERNARY(T35, 0x3L, T31);}
  val_t T37;
  T37 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x5L;
  val_t T38;
  { T38 = T33 | T32;}
  val_t T39;
  { T39 = T38 ^ 0x1L;}
  val_t T40;
  { T40 = T39 & T37;}
  val_t T41;
  { T41 = TERNARY(T40, 0x0L, T36);}
  val_t T42;
  T42 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x6L;
  val_t T43;
  { T43 = T38 | T37;}
  val_t T44;
  { T44 = T43 ^ 0x1L;}
  val_t T45;
  { T45 = T44 & T42;}
  val_t T46;
  { T46 = TERNARY(T45, 0x3L, T41);}
  val_t T47;
  T47 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x7L;
  val_t T48;
  { T48 = T43 | T42;}
  val_t T49;
  { T49 = T48 ^ 0x1L;}
  val_t T50;
  { T50 = T49 & T47;}
  val_t T51;
  { T51 = TERNARY(T50, 0x3L, T46);}
  val_t T52;
  T52 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x8L;
  val_t T53;
  { T53 = T48 | T47;}
  val_t T54;
  { T54 = T53 ^ 0x1L;}
  val_t T55;
  { T55 = T54 & T52;}
  val_t T56;
  { T56 = TERNARY(T55, 0x2L, T51);}
  val_t T57;
  T57 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x9L;
  val_t T58;
  { T58 = T53 | T52;}
  val_t T59;
  { T59 = T58 ^ 0x1L;}
  val_t T60;
  { T60 = T59 & T57;}
  val_t T61;
  { T61 = TERNARY(T60, 0x2L, T56);}
  val_t T62;
  T62 = Main_schedule_table__io_dir_slotCounter.values[0] == 0xaL;
  val_t T63;
  { T63 = T58 | T57;}
  val_t T64;
  { T64 = T63 ^ 0x1L;}
  val_t T65;
  { T65 = T64 & T62;}
  val_t T66;
  { T66 = TERNARY(T65, 0x5L, T61);}
  val_t T67;
  T67 = Main_schedule_table__io_dir_slotCounter.values[0] == 0xbL;
  val_t T68;
  { T68 = T63 | T62;}
  val_t T69;
  { T69 = T68 ^ 0x1L;}
  val_t T70;
  { T70 = T69 & T67;}
  val_t T71;
  { T71 = TERNARY(T70, 0x3L, T66);}
  val_t T72;
  T72 = Main_schedule_table__io_dir_slotCounter.values[0] == 0xcL;
  val_t T73;
  { T73 = T68 | T67;}
  val_t T74;
  { T74 = T73 ^ 0x1L;}
  val_t T75;
  { T75 = T74 & T72;}
  val_t T76;
  { T76 = TERNARY(T75, 0x4L, T71);}
  val_t T77;
  T77 = Main_schedule_table__io_dir_slotCounter.values[0] == 0xdL;
  val_t T78;
  { T78 = T73 | T72;}
  val_t T79;
  { T79 = T78 ^ 0x1L;}
  val_t T80;
  { T80 = T79 & T77;}
  val_t T81;
  { T81 = TERNARY(T80, 0x2L, T76);}
  val_t T82;
  T82 = Main_schedule_table__io_dir_slotCounter.values[0] == 0xeL;
  val_t T83;
  { T83 = T78 | T77;}
  val_t T84;
  { T84 = T83 ^ 0x1L;}
  val_t T85;
  { T85 = T84 & T82;}
  val_t T86;
  { T86 = TERNARY(T85, 0x3L, T81);}
  val_t T87;
  T87 = Main_schedule_table__io_dir_slotCounter.values[0] == 0xfL;
  val_t T88;
  { T88 = T83 | T82;}
  val_t T89;
  { T89 = T88 ^ 0x1L;}
  val_t T90;
  { T90 = T89 & T87;}
  val_t T91;
  { T91 = TERNARY(T90, 0x4L, T86);}
  val_t T92;
  T92 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x10L;
  val_t T93;
  { T93 = T88 | T87;}
  val_t T94;
  { T94 = T93 ^ 0x1L;}
  val_t T95;
  { T95 = T94 & T92;}
  val_t T96;
  { T96 = TERNARY(T95, 0x3L, T91);}
  val_t T97;
  T97 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x11L;
  val_t T98;
  { T98 = T93 | T92;}
  val_t T99;
  { T99 = T98 ^ 0x1L;}
  val_t T100;
  { T100 = T99 & T97;}
  val_t T101;
  { T101 = TERNARY(T100, 0x5L, T96);}
  val_t T102;
  T102 = Main_schedule_table__io_dir_slotCounter.values[0] == 0x12L;
  val_t T103;
  { T103 = T98 | T97;}
  val_t T104;
  { T104 = T103 ^ 0x1L;}
  val_t T105;
  { T105 = T104 & T102;}
  val_t T106;
  { T106 = TERNARY(T105, 0x4L, T101);}
  { Main_schedule_table__io_dir_rInfo_local.values[0] = T106;}
  { Main_route__io_routeInfo_rInfo_local.values[0] = Main_schedule_table__io_dir_rInfo_local.values[0];}
  { T107.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_routeInfo_rInfo_local.values[0]);}
  val_t T108;
  { T108 = TERNARY_1(T2, Main_route__din_up_valid.values[0], Main_route__dout_local_valid.values[0]);}
  val_t T109;
  { T109 = TERNARY_1(T4, Main_route__din_right_valid.values[0], T108);}
  val_t T110;
  { T110 = TERNARY_1(T6, Main_route__din_down_valid.values[0], T109);}
  val_t T111;
  { T111 = TERNARY_1(T8, Main_route__din_left_valid.values[0], T110);}
  val_t T112;
  { T112 = TERNARY_1(T10, Main_route__din_local_valid.values[0], T111);}
  val_t T113;
  { T113 = TERNARY(T12, 0x0L, T112);}
  { T114.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T113);}
  val_t T115;
  T115 = Main_route__directions_up.values[0] == 0x1L;
  val_t T116;
  { T116 = T115 | 0x0L << 1;}
  { Main_route__io_test.values[0] = T116;}
  { val_t __r = this->__rand_val(); Main_route__io_ready.values[0] = __r;}
  Main_route__io_ready.values[0] = Main_route__io_ready.values[0] & 0x1L;
  val_t T117;
  T117 = 0x5L == Main_route__directions_right.values[0];
  val_t T118;
  { T118 = TERNARY_1(T117, Main_route__din_up_data.values[0], Main_route__dout_right_data.values[0]);}
  val_t T119;
  T119 = 0x4L == Main_route__directions_right.values[0];
  val_t T120;
  { T120 = TERNARY_1(T119, Main_route__din_right_data.values[0], T118);}
  val_t T121;
  T121 = 0x2L == Main_route__directions_right.values[0];
  val_t T122;
  { T122 = TERNARY_1(T121, Main_route__din_down_data.values[0], T120);}
  val_t T123;
  T123 = 0x3L == Main_route__directions_right.values[0];
  val_t T124;
  { T124 = TERNARY_1(T123, Main_route__din_left_data.values[0], T122);}
  val_t T125;
  T125 = 0x1L == Main_route__directions_right.values[0];
  val_t T126;
  { T126 = TERNARY_1(T125, Main_route__din_local_data.values[0], T124);}
  val_t T127;
  T127 = 0x0L == Main_route__directions_right.values[0];
  val_t T128;
  { T128 = TERNARY(T127, 0x0L, T126);}
  { T129.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T128);}
  val_t T130;
  { T130 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T131;
  { T131 = TERNARY(T20, 0x1L, T130);}
  val_t T132;
  { T132 = TERNARY(T25, 0x2L, T131);}
  val_t T133;
  { T133 = TERNARY(T30, 0x3L, T132);}
  val_t T134;
  { T134 = TERNARY(T35, 0x2L, T133);}
  val_t T135;
  { T135 = TERNARY(T40, 0x3L, T134);}
  val_t T136;
  { T136 = TERNARY(T45, 0x2L, T135);}
  val_t T137;
  { T137 = TERNARY(T50, 0x1L, T136);}
  val_t T138;
  { T138 = TERNARY(T55, 0x3L, T137);}
  val_t T139;
  { T139 = TERNARY(T60, 0x0L, T138);}
  val_t T140;
  { T140 = TERNARY(T65, 0x2L, T139);}
  val_t T141;
  { T141 = TERNARY(T70, 0x0L, T140);}
  val_t T142;
  { T142 = TERNARY(T75, 0x1L, T141);}
  val_t T143;
  { T143 = TERNARY(T80, 0x3L, T142);}
  val_t T144;
  { T144 = TERNARY(T85, 0x0L, T143);}
  val_t T145;
  { T145 = TERNARY(T90, 0x1L, T144);}
  val_t T146;
  { T146 = TERNARY(T95, 0x0L, T145);}
  val_t T147;
  { T147 = TERNARY(T100, 0x0L, T146);}
  val_t T148;
  { T148 = TERNARY(T105, 0x0L, T147);}
  { Main_schedule_table__io_dir_rInfo_right.values[0] = T148;}
  { Main_route__io_routeInfo_rInfo_right.values[0] = Main_schedule_table__io_dir_rInfo_right.values[0];}
  { T149.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_routeInfo_rInfo_right.values[0]);}
  val_t T150;
  { T150 = TERNARY_1(T117, Main_route__din_up_valid.values[0], Main_route__dout_right_valid.values[0]);}
  val_t T151;
  { T151 = TERNARY_1(T119, Main_route__din_right_valid.values[0], T150);}
  val_t T152;
  { T152 = TERNARY_1(T121, Main_route__din_down_valid.values[0], T151);}
  val_t T153;
  { T153 = TERNARY_1(T123, Main_route__din_left_valid.values[0], T152);}
  val_t T154;
  { T154 = TERNARY_1(T125, Main_route__din_local_valid.values[0], T153);}
  val_t T155;
  { T155 = TERNARY(T127, 0x0L, T154);}
  { T156.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T155);}
  val_t T157;
  T157 = 0x5L == Main_route__directions_left.values[0];
  val_t T158;
  { T158 = TERNARY_1(T157, Main_route__din_up_data.values[0], Main_route__dout_left_data.values[0]);}
  val_t T159;
  T159 = 0x4L == Main_route__directions_left.values[0];
  val_t T160;
  { T160 = TERNARY_1(T159, Main_route__din_right_data.values[0], T158);}
  val_t T161;
  T161 = 0x2L == Main_route__directions_left.values[0];
  val_t T162;
  { T162 = TERNARY_1(T161, Main_route__din_down_data.values[0], T160);}
  val_t T163;
  T163 = 0x3L == Main_route__directions_left.values[0];
  val_t T164;
  { T164 = TERNARY_1(T163, Main_route__din_left_data.values[0], T162);}
  val_t T165;
  T165 = 0x1L == Main_route__directions_left.values[0];
  val_t T166;
  { T166 = TERNARY_1(T165, Main_route__din_local_data.values[0], T164);}
  val_t T167;
  T167 = 0x0L == Main_route__directions_left.values[0];
  val_t T168;
  { T168 = TERNARY(T167, 0x0L, T166);}
  { T169.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T168);}
  val_t T170;
  { T170 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T171;
  { T171 = TERNARY(T20, 0x0L, T170);}
  val_t T172;
  { T172 = TERNARY(T25, 0x0L, T171);}
  val_t T173;
  { T173 = TERNARY(T30, 0x0L, T172);}
  val_t T174;
  { T174 = TERNARY(T35, 0x0L, T173);}
  val_t T175;
  { T175 = TERNARY(T40, 0x1L, T174);}
  val_t T176;
  { T176 = TERNARY(T45, 0x0L, T175);}
  val_t T177;
  { T177 = TERNARY(T50, 0x0L, T176);}
  val_t T178;
  { T178 = TERNARY(T55, 0x0L, T177);}
  val_t T179;
  { T179 = TERNARY(T60, 0x0L, T178);}
  val_t T180;
  { T180 = TERNARY(T65, 0x0L, T179);}
  val_t T181;
  { T181 = TERNARY(T70, 0x2L, T180);}
  val_t T182;
  { T182 = TERNARY(T75, 0x0L, T181);}
  val_t T183;
  { T183 = TERNARY(T80, 0x0L, T182);}
  val_t T184;
  { T184 = TERNARY(T85, 0x5L, T183);}
  val_t T185;
  { T185 = TERNARY(T90, 0x0L, T184);}
  val_t T186;
  { T186 = TERNARY(T95, 0x0L, T185);}
  val_t T187;
  { T187 = TERNARY(T100, 0x1L, T186);}
  val_t T188;
  { T188 = TERNARY(T105, 0x0L, T187);}
  { Main_schedule_table__io_dir_rInfo_left.values[0] = T188;}
  { Main_route__io_routeInfo_rInfo_left.values[0] = Main_schedule_table__io_dir_rInfo_left.values[0];}
  { T189.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_routeInfo_rInfo_left.values[0]);}
  val_t T190;
  { T190 = TERNARY_1(T157, Main_route__din_up_valid.values[0], Main_route__dout_left_valid.values[0]);}
  val_t T191;
  { T191 = TERNARY_1(T159, Main_route__din_right_valid.values[0], T190);}
  val_t T192;
  { T192 = TERNARY_1(T161, Main_route__din_down_valid.values[0], T191);}
  val_t T193;
  { T193 = TERNARY_1(T163, Main_route__din_left_valid.values[0], T192);}
  val_t T194;
  { T194 = TERNARY_1(T165, Main_route__din_local_valid.values[0], T193);}
  val_t T195;
  { T195 = TERNARY(T167, 0x0L, T194);}
  { T196.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T195);}
  val_t T197;
  T197 = 0x5L == Main_route__directions_up.values[0];
  val_t T198;
  { T198 = TERNARY_1(T197, Main_route__din_up_data.values[0], Main_route__dout_up_data.values[0]);}
  val_t T199;
  T199 = 0x4L == Main_route__directions_up.values[0];
  val_t T200;
  { T200 = TERNARY_1(T199, Main_route__din_right_data.values[0], T198);}
  val_t T201;
  T201 = 0x2L == Main_route__directions_up.values[0];
  val_t T202;
  { T202 = TERNARY_1(T201, Main_route__din_down_data.values[0], T200);}
  val_t T203;
  T203 = 0x3L == Main_route__directions_up.values[0];
  val_t T204;
  { T204 = TERNARY_1(T203, Main_route__din_left_data.values[0], T202);}
  val_t T205;
  T205 = 0x1L == Main_route__directions_up.values[0];
  val_t T206;
  { T206 = TERNARY_1(T205, Main_route__din_local_data.values[0], T204);}
  val_t T207;
  T207 = 0x0L == Main_route__directions_up.values[0];
  val_t T208;
  { T208 = TERNARY(T207, 0x0L, T206);}
  { T209.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T208);}
  val_t T210;
  { T210 = TERNARY(T16, 0x1L, 0x0L);}
  val_t T211;
  { T211 = TERNARY(T20, 0x2L, T210);}
  val_t T212;
  { T212 = TERNARY(T25, 0x0L, T211);}
  val_t T213;
  { T213 = TERNARY(T30, 0x1L, T212);}
  val_t T214;
  { T214 = TERNARY(T35, 0x1L, T213);}
  val_t T215;
  { T215 = TERNARY(T40, 0x2L, T214);}
  val_t T216;
  { T216 = TERNARY(T45, 0x4L, T215);}
  val_t T217;
  { T217 = TERNARY(T50, 0x2L, T216);}
  val_t T218;
  { T218 = TERNARY(T55, 0x1L, T217);}
  val_t T219;
  { T219 = TERNARY(T60, 0x1L, T218);}
  val_t T220;
  { T220 = TERNARY(T65, 0x1L, T219);}
  val_t T221;
  { T221 = TERNARY(T70, 0x1L, T220);}
  val_t T222;
  { T222 = TERNARY(T75, 0x2L, T221);}
  val_t T223;
  { T223 = TERNARY(T80, 0x0L, T222);}
  val_t T224;
  { T224 = TERNARY(T85, 0x0L, T223);}
  val_t T225;
  { T225 = TERNARY(T90, 0x0L, T224);}
  val_t T226;
  { T226 = TERNARY(T95, 0x0L, T225);}
  val_t T227;
  { T227 = TERNARY(T100, 0x0L, T226);}
  val_t T228;
  { T228 = TERNARY(T105, 0x0L, T227);}
  { Main_schedule_table__io_dir_rInfo_up.values[0] = T228;}
  { Main_route__io_routeInfo_rInfo_up.values[0] = Main_schedule_table__io_dir_rInfo_up.values[0];}
  { T229.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_routeInfo_rInfo_up.values[0]);}
  val_t T230;
  { T230 = TERNARY_1(T197, Main_route__din_up_valid.values[0], Main_route__dout_up_valid.values[0]);}
  val_t T231;
  { T231 = TERNARY_1(T199, Main_route__din_right_valid.values[0], T230);}
  val_t T232;
  { T232 = TERNARY_1(T201, Main_route__din_down_valid.values[0], T231);}
  val_t T233;
  { T233 = TERNARY_1(T203, Main_route__din_left_valid.values[0], T232);}
  val_t T234;
  { T234 = TERNARY_1(T205, Main_route__din_local_valid.values[0], T233);}
  val_t T235;
  { T235 = TERNARY(T207, 0x0L, T234);}
  { T236.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T235);}
  { Main_route__io_lc_din_data.values[0] = Main__io_lc_din_data.values[0];}
  { T237.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_lc_din_data.values[0]);}
  { Main_route__io_le_din_data.values[0] = Main__io_le_din_data.values[0];}
  { T238.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_le_din_data.values[0]);}
  { Main_route__io_dn_din_data.values[0] = Main__io_dn_din_data.values[0];}
  { T239.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_dn_din_data.values[0]);}
  { Main_route__io_r_din_data.values[0] = Main__io_r_din_data.values[0];}
  { T240.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_r_din_data.values[0]);}
  { Main_route__io_up_din_data.values[0] = Main__io_up_din_data.values[0];}
  { T241.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_up_din_data.values[0]);}
  val_t T242;
  T242 = 0x5L == Main_route__directions_down.values[0];
  val_t T243;
  { T243 = TERNARY_1(T242, Main_route__din_up_data.values[0], Main_route__dout_down_data.values[0]);}
  val_t T244;
  T244 = 0x4L == Main_route__directions_down.values[0];
  val_t T245;
  { T245 = TERNARY_1(T244, Main_route__din_right_data.values[0], T243);}
  val_t T246;
  T246 = 0x2L == Main_route__directions_down.values[0];
  val_t T247;
  { T247 = TERNARY_1(T246, Main_route__din_down_data.values[0], T245);}
  val_t T248;
  T248 = 0x3L == Main_route__directions_down.values[0];
  val_t T249;
  { T249 = TERNARY_1(T248, Main_route__din_left_data.values[0], T247);}
  val_t T250;
  T250 = 0x1L == Main_route__directions_down.values[0];
  val_t T251;
  { T251 = TERNARY_1(T250, Main_route__din_local_data.values[0], T249);}
  val_t T252;
  T252 = 0x0L == Main_route__directions_down.values[0];
  val_t T253;
  { T253 = TERNARY(T252, 0x0L, T251);}
  { T254.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T253);}
  { Main_route__io_lc_din_valid.values[0] = Main__io_lc_din_valid.values[0];}
  { T255.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_lc_din_valid.values[0]);}
  { Main_route__io_le_din_valid.values[0] = Main__io_le_din_valid.values[0];}
  { T256.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_le_din_valid.values[0]);}
  { Main_route__io_dn_din_valid.values[0] = Main__io_dn_din_valid.values[0];}
  { T257.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_dn_din_valid.values[0]);}
  { Main_route__io_r_din_valid.values[0] = Main__io_r_din_valid.values[0];}
  { T258.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_r_din_valid.values[0]);}
  val_t T259;
  { T259 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T260;
  { T260 = TERNARY(T20, 0x0L, T259);}
  val_t T261;
  { T261 = TERNARY(T25, 0x3L, T260);}
  val_t T262;
  { T262 = TERNARY(T30, 0x0L, T261);}
  val_t T263;
  { T263 = TERNARY(T35, 0x0L, T262);}
  val_t T264;
  { T264 = TERNARY(T40, 0x0L, T263);}
  val_t T265;
  { T265 = TERNARY(T45, 0x0L, T264);}
  val_t T266;
  { T266 = TERNARY(T50, 0x0L, T265);}
  val_t T267;
  { T267 = TERNARY(T55, 0x0L, T266);}
  val_t T268;
  { T268 = TERNARY(T60, 0x3L, T267);}
  val_t T269;
  { T269 = TERNARY(T65, 0x0L, T268);}
  val_t T270;
  { T270 = TERNARY(T70, 0x0L, T269);}
  val_t T271;
  { T271 = TERNARY(T75, 0x0L, T270);}
  val_t T272;
  { T272 = TERNARY(T80, 0x1L, T271);}
  val_t T273;
  { T273 = TERNARY(T85, 0x0L, T272);}
  val_t T274;
  { T274 = TERNARY(T90, 0x0L, T273);}
  val_t T275;
  { T275 = TERNARY(T95, 0x1L, T274);}
  val_t T276;
  { T276 = TERNARY(T100, 0x0L, T275);}
  val_t T277;
  { T277 = TERNARY(T105, 0x0L, T276);}
  { Main_schedule_table__io_dir_rInfo_down.values[0] = T277;}
  { Main_route__io_routeInfo_rInfo_down.values[0] = Main_schedule_table__io_dir_rInfo_down.values[0];}
  { T278.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_routeInfo_rInfo_down.values[0]);}
  { Main_route__io_up_din_valid.values[0] = Main__io_up_din_valid.values[0];}
  { T279.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, Main_route__io_up_din_valid.values[0]);}
  val_t T280;
  { T280 = TERNARY_1(T242, Main_route__din_up_valid.values[0], Main_route__dout_down_valid.values[0]);}
  val_t T281;
  { T281 = TERNARY_1(T244, Main_route__din_right_valid.values[0], T280);}
  val_t T282;
  { T282 = TERNARY_1(T246, Main_route__din_down_valid.values[0], T281);}
  val_t T283;
  { T283 = TERNARY_1(T248, Main_route__din_left_valid.values[0], T282);}
  val_t T284;
  { T284 = TERNARY_1(T250, Main_route__din_local_valid.values[0], T283);}
  val_t T285;
  { T285 = TERNARY(T252, 0x0L, T284);}
  { T286.values[0] = TERNARY(Main_route__reset.values[0], 0x0L, T285);}
  { Main_route__io_lc_dout_data.values[0] = Main_route__dout_local_data.values[0];}
  { Main__io_lc_dout_data.values[0] = Main_route__io_lc_dout_data.values[0];}
  { Main_route__io_lc_dout_valid.values[0] = Main_route__dout_local_valid.values[0];}
  { Main__io_lc_dout_valid.values[0] = Main_route__io_lc_dout_valid.values[0];}
  { Main_route__io_r_dout_data.values[0] = Main_route__dout_right_data.values[0];}
  { Main__io_r_dout_data.values[0] = Main_route__io_r_dout_data.values[0];}
  { Main_route__io_r_dout_valid.values[0] = Main_route__dout_right_valid.values[0];}
  { Main__io_r_dout_valid.values[0] = Main_route__io_r_dout_valid.values[0];}
  { Main_route__io_le_dout_data.values[0] = Main_route__dout_left_data.values[0];}
  { Main__io_le_dout_data.values[0] = Main_route__io_le_dout_data.values[0];}
  { Main_route__io_le_dout_valid.values[0] = Main_route__dout_left_valid.values[0];}
  { Main__io_le_dout_valid.values[0] = Main_route__io_le_dout_valid.values[0];}
  { Main_route__io_up_dout_data.values[0] = Main_route__dout_up_data.values[0];}
  { Main__io_up_dout_data.values[0] = Main_route__io_up_dout_data.values[0];}
  { Main_route__io_up_dout_valid.values[0] = Main_route__dout_up_valid.values[0];}
  { Main__io_up_dout_valid.values[0] = Main_route__io_up_dout_valid.values[0];}
  { Main_route__io_dn_dout_data.values[0] = Main_route__dout_down_data.values[0];}
  { Main__io_dn_dout_data.values[0] = Main_route__io_dn_dout_data.values[0];}
  { Main_route__io_dn_dout_valid.values[0] = Main_route__dout_down_valid.values[0];}
  { Main__io_dn_dout_valid.values[0] = Main_route__io_dn_dout_valid.values[0];}
}


void Main_t::clock_hi ( dat_t<1> reset ) {
  dat_t<19> Main_route__reg_slotCount__shadow = T1;
  dat_t<32> Main_route__dout_local_data__shadow = T14;
  dat_t<3> Main_route__directions_local__shadow = T107;
  dat_t<1> Main_route__dout_local_valid__shadow = T114;
  dat_t<32> Main_route__dout_right_data__shadow = T129;
  dat_t<3> Main_route__directions_right__shadow = T149;
  dat_t<1> Main_route__dout_right_valid__shadow = T156;
  dat_t<32> Main_route__dout_left_data__shadow = T169;
  dat_t<3> Main_route__directions_left__shadow = T189;
  dat_t<1> Main_route__dout_left_valid__shadow = T196;
  dat_t<32> Main_route__dout_up_data__shadow = T209;
  dat_t<3> Main_route__directions_up__shadow = T229;
  dat_t<1> Main_route__dout_up_valid__shadow = T236;
  dat_t<32> Main_route__din_local_data__shadow = T237;
  dat_t<32> Main_route__din_left_data__shadow = T238;
  dat_t<32> Main_route__din_down_data__shadow = T239;
  dat_t<32> Main_route__din_right_data__shadow = T240;
  dat_t<32> Main_route__din_up_data__shadow = T241;
  dat_t<32> Main_route__dout_down_data__shadow = T254;
  dat_t<1> Main_route__din_local_valid__shadow = T255;
  dat_t<1> Main_route__din_left_valid__shadow = T256;
  dat_t<1> Main_route__din_down_valid__shadow = T257;
  dat_t<1> Main_route__din_right_valid__shadow = T258;
  dat_t<3> Main_route__directions_down__shadow = T278;
  dat_t<1> Main_route__din_up_valid__shadow = T279;
  dat_t<1> Main_route__dout_down_valid__shadow = T286;
  Main_route__reg_slotCount = T1;
  Main_route__dout_local_data = T14;
  Main_route__directions_local = T107;
  Main_route__dout_local_valid = T114;
  Main_route__dout_right_data = T129;
  Main_route__directions_right = T149;
  Main_route__dout_right_valid = T156;
  Main_route__dout_left_data = T169;
  Main_route__directions_left = T189;
  Main_route__dout_left_valid = T196;
  Main_route__dout_up_data = T209;
  Main_route__directions_up = T229;
  Main_route__dout_up_valid = T236;
  Main_route__din_local_data = T237;
  Main_route__din_left_data = T238;
  Main_route__din_down_data = T239;
  Main_route__din_right_data = T240;
  Main_route__din_up_data = T241;
  Main_route__dout_down_data = T254;
  Main_route__din_local_valid = T255;
  Main_route__din_left_valid = T256;
  Main_route__din_down_valid = T257;
  Main_route__din_right_valid = T258;
  Main_route__directions_down = T278;
  Main_route__din_up_valid = T279;
  Main_route__dout_down_valid = T286;
}


void Main_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  Main_t* mod = dynamic_cast<Main_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<32>(&mod->Main__io_lc_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->Main__io_lc_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->Main__io_r_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->Main__io_r_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->Main__io_le_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->Main__io_le_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->Main__io_up_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->Main__io_up_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->Main__io_dn_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->Main__io_dn_din_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->Main__io_lc_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Main__io_lc_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->Main__io_r_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Main__io_r_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->Main__io_le_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Main__io_le_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->Main__io_up_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Main__io_up_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->Main__io_dn_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Main__io_dn_dout_valid));
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__reset));
  sim_data.signal_map["Main.route.reset"] = 0;
  sim_data.signals.push_back(new dat_api<19>(&mod->Main_route__reg_slotCount));
  sim_data.signal_map["Main.route.reg_slotCount"] = 1;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__dout_local_data));
  sim_data.signal_map["Main.route.dout_local_data"] = 2;
  sim_data.signals.push_back(new dat_api<16>(&mod->Main_route__io_routeInfo_slotCounter));
  sim_data.signal_map["Main.route.io_routeInfo_slotCounter"] = 3;
  sim_data.signals.push_back(new dat_api<16>(&mod->Main_schedule_table__io_dir_slotCounter));
  sim_data.signal_map["Main.schedule_table.io_dir_slotCounter"] = 4;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_schedule_table__io_dir_rInfo_local));
  sim_data.signal_map["Main.schedule_table.io_dir_rInfo_local"] = 5;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__io_routeInfo_rInfo_local));
  sim_data.signal_map["Main.route.io_routeInfo_rInfo_local"] = 6;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__directions_local));
  sim_data.signal_map["Main.route.directions_local"] = 7;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__dout_local_valid));
  sim_data.signal_map["Main.route.dout_local_valid"] = 8;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_test));
  sim_data.signal_map["Main.route.io_test"] = 9;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__dout_right_data));
  sim_data.signal_map["Main.route.dout_right_data"] = 10;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_schedule_table__io_dir_rInfo_right));
  sim_data.signal_map["Main.schedule_table.io_dir_rInfo_right"] = 11;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__io_routeInfo_rInfo_right));
  sim_data.signal_map["Main.route.io_routeInfo_rInfo_right"] = 12;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__directions_right));
  sim_data.signal_map["Main.route.directions_right"] = 13;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__dout_right_valid));
  sim_data.signal_map["Main.route.dout_right_valid"] = 14;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__dout_left_data));
  sim_data.signal_map["Main.route.dout_left_data"] = 15;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_schedule_table__io_dir_rInfo_left));
  sim_data.signal_map["Main.schedule_table.io_dir_rInfo_left"] = 16;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__io_routeInfo_rInfo_left));
  sim_data.signal_map["Main.route.io_routeInfo_rInfo_left"] = 17;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__directions_left));
  sim_data.signal_map["Main.route.directions_left"] = 18;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__dout_left_valid));
  sim_data.signal_map["Main.route.dout_left_valid"] = 19;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__dout_up_data));
  sim_data.signal_map["Main.route.dout_up_data"] = 20;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_schedule_table__io_dir_rInfo_up));
  sim_data.signal_map["Main.schedule_table.io_dir_rInfo_up"] = 21;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__io_routeInfo_rInfo_up));
  sim_data.signal_map["Main.route.io_routeInfo_rInfo_up"] = 22;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__directions_up));
  sim_data.signal_map["Main.route.directions_up"] = 23;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__dout_up_valid));
  sim_data.signal_map["Main.route.dout_up_valid"] = 24;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_lc_din_data));
  sim_data.signal_map["Main.route.io_lc_din_data"] = 25;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__din_local_data));
  sim_data.signal_map["Main.route.din_local_data"] = 26;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_le_din_data));
  sim_data.signal_map["Main.route.io_le_din_data"] = 27;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__din_left_data));
  sim_data.signal_map["Main.route.din_left_data"] = 28;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_dn_din_data));
  sim_data.signal_map["Main.route.io_dn_din_data"] = 29;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__din_down_data));
  sim_data.signal_map["Main.route.din_down_data"] = 30;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_r_din_data));
  sim_data.signal_map["Main.route.io_r_din_data"] = 31;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__din_right_data));
  sim_data.signal_map["Main.route.din_right_data"] = 32;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_up_din_data));
  sim_data.signal_map["Main.route.io_up_din_data"] = 33;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__din_up_data));
  sim_data.signal_map["Main.route.din_up_data"] = 34;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__dout_down_data));
  sim_data.signal_map["Main.route.dout_down_data"] = 35;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_lc_din_valid));
  sim_data.signal_map["Main.route.io_lc_din_valid"] = 36;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__din_local_valid));
  sim_data.signal_map["Main.route.din_local_valid"] = 37;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_le_din_valid));
  sim_data.signal_map["Main.route.io_le_din_valid"] = 38;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__din_left_valid));
  sim_data.signal_map["Main.route.din_left_valid"] = 39;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_dn_din_valid));
  sim_data.signal_map["Main.route.io_dn_din_valid"] = 40;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__din_down_valid));
  sim_data.signal_map["Main.route.din_down_valid"] = 41;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_r_din_valid));
  sim_data.signal_map["Main.route.io_r_din_valid"] = 42;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__din_right_valid));
  sim_data.signal_map["Main.route.din_right_valid"] = 43;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_schedule_table__io_dir_rInfo_down));
  sim_data.signal_map["Main.schedule_table.io_dir_rInfo_down"] = 44;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__io_routeInfo_rInfo_down));
  sim_data.signal_map["Main.route.io_routeInfo_rInfo_down"] = 45;
  sim_data.signals.push_back(new dat_api<3>(&mod->Main_route__directions_down));
  sim_data.signal_map["Main.route.directions_down"] = 46;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_up_din_valid));
  sim_data.signal_map["Main.route.io_up_din_valid"] = 47;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__din_up_valid));
  sim_data.signal_map["Main.route.din_up_valid"] = 48;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__dout_down_valid));
  sim_data.signal_map["Main.route.dout_down_valid"] = 49;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_lc_dout_data));
  sim_data.signal_map["Main.route.io_lc_dout_data"] = 50;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_lc_dout_valid));
  sim_data.signal_map["Main.route.io_lc_dout_valid"] = 51;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_r_dout_data));
  sim_data.signal_map["Main.route.io_r_dout_data"] = 52;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_r_dout_valid));
  sim_data.signal_map["Main.route.io_r_dout_valid"] = 53;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_le_dout_data));
  sim_data.signal_map["Main.route.io_le_dout_data"] = 54;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_le_dout_valid));
  sim_data.signal_map["Main.route.io_le_dout_valid"] = 55;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_up_dout_data));
  sim_data.signal_map["Main.route.io_up_dout_data"] = 56;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_up_dout_valid));
  sim_data.signal_map["Main.route.io_up_dout_valid"] = 57;
  sim_data.signals.push_back(new dat_api<32>(&mod->Main_route__io_dn_dout_data));
  sim_data.signal_map["Main.route.io_dn_dout_data"] = 58;
  sim_data.signals.push_back(new dat_api<1>(&mod->Main_route__io_dn_dout_valid));
  sim_data.signal_map["Main.route.io_dn_dout_valid"] = 59;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
