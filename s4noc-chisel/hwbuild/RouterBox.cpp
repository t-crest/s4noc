#include "RouterBox.h"

void RouterBox_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  RouterBox_route__reg_slotCount.randomize(&__rand_seed);
  RouterBox_route__dout_local_data.randomize(&__rand_seed);
  RouterBox_route__directions_local.randomize(&__rand_seed);
  RouterBox_route__dout_local_valid.randomize(&__rand_seed);
  RouterBox_route__dout_right_data.randomize(&__rand_seed);
  RouterBox_route__directions_right.randomize(&__rand_seed);
  RouterBox_route__dout_right_valid.randomize(&__rand_seed);
  RouterBox_route__dout_left_data.randomize(&__rand_seed);
  RouterBox_route__directions_left.randomize(&__rand_seed);
  RouterBox_route__dout_left_valid.randomize(&__rand_seed);
  RouterBox_route__dout_up_data.randomize(&__rand_seed);
  RouterBox_route__directions_up.randomize(&__rand_seed);
  RouterBox_route__dout_up_valid.randomize(&__rand_seed);
  RouterBox_route__din_local_data.randomize(&__rand_seed);
  RouterBox_route__din_left_data.randomize(&__rand_seed);
  RouterBox_route__din_down_data.randomize(&__rand_seed);
  RouterBox_route__din_right_data.randomize(&__rand_seed);
  RouterBox_route__din_up_data.randomize(&__rand_seed);
  RouterBox_route__dout_down_data.randomize(&__rand_seed);
  RouterBox_route__din_local_valid.randomize(&__rand_seed);
  RouterBox_route__din_left_valid.randomize(&__rand_seed);
  RouterBox_route__din_down_valid.randomize(&__rand_seed);
  RouterBox_route__din_right_valid.randomize(&__rand_seed);
  RouterBox_route__directions_down.randomize(&__rand_seed);
  RouterBox_route__din_up_valid.randomize(&__rand_seed);
  RouterBox_route__dout_down_valid.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int RouterBox_t::clock ( dat_t<1> reset ) {
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


void RouterBox_t::print ( FILE* f ) {
}
void RouterBox_t::print ( std::ostream& s ) {
}


void RouterBox_t::dump_init ( FILE* f ) {
  fputs("$timescale 1ps $end\n", f);
  fputs("$scope module RouterBox $end\n", f);
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
  dat_dump<1>(f, RouterBox_route__reset, 0x23);
  RouterBox_route__reset__prev = RouterBox_route__reset;
  dat_dump<1>(f, RouterBox_route__dout_local_valid, 0x24);
  RouterBox_route__dout_local_valid__prev = RouterBox_route__dout_local_valid;
  dat_dump<1>(f, RouterBox_route__io_ready, 0x25);
  RouterBox_route__io_ready__prev = RouterBox_route__io_ready;
  dat_dump<1>(f, RouterBox_route__dout_right_valid, 0x26);
  RouterBox_route__dout_right_valid__prev = RouterBox_route__dout_right_valid;
  dat_dump<1>(f, RouterBox_route__dout_left_valid, 0x27);
  RouterBox_route__dout_left_valid__prev = RouterBox_route__dout_left_valid;
  dat_dump<1>(f, RouterBox_route__dout_up_valid, 0x28);
  RouterBox_route__dout_up_valid__prev = RouterBox_route__dout_up_valid;
  dat_dump<1>(f, RouterBox__io_lc_din_valid, 0x29);
  RouterBox__io_lc_din_valid__prev = RouterBox__io_lc_din_valid;
  dat_dump<1>(f, RouterBox_route__io_lc_din_valid, 0x2a);
  RouterBox_route__io_lc_din_valid__prev = RouterBox_route__io_lc_din_valid;
  dat_dump<1>(f, RouterBox_route__din_local_valid, 0x2b);
  RouterBox_route__din_local_valid__prev = RouterBox_route__din_local_valid;
  dat_dump<1>(f, RouterBox__io_le_din_valid, 0x2c);
  RouterBox__io_le_din_valid__prev = RouterBox__io_le_din_valid;
  dat_dump<1>(f, RouterBox_route__io_le_din_valid, 0x2d);
  RouterBox_route__io_le_din_valid__prev = RouterBox_route__io_le_din_valid;
  dat_dump<1>(f, RouterBox_route__din_left_valid, 0x2e);
  RouterBox_route__din_left_valid__prev = RouterBox_route__din_left_valid;
  dat_dump<1>(f, RouterBox__io_dn_din_valid, 0x2f);
  RouterBox__io_dn_din_valid__prev = RouterBox__io_dn_din_valid;
  dat_dump<1>(f, RouterBox_route__io_dn_din_valid, 0x30);
  RouterBox_route__io_dn_din_valid__prev = RouterBox_route__io_dn_din_valid;
  dat_dump<1>(f, RouterBox_route__din_down_valid, 0x31);
  RouterBox_route__din_down_valid__prev = RouterBox_route__din_down_valid;
  dat_dump<1>(f, RouterBox__io_r_din_valid, 0x32);
  RouterBox__io_r_din_valid__prev = RouterBox__io_r_din_valid;
  dat_dump<1>(f, RouterBox_route__io_r_din_valid, 0x33);
  RouterBox_route__io_r_din_valid__prev = RouterBox_route__io_r_din_valid;
  dat_dump<1>(f, RouterBox_route__din_right_valid, 0x34);
  RouterBox_route__din_right_valid__prev = RouterBox_route__din_right_valid;
  dat_dump<1>(f, RouterBox__io_up_din_valid, 0x35);
  RouterBox__io_up_din_valid__prev = RouterBox__io_up_din_valid;
  dat_dump<1>(f, RouterBox_route__io_up_din_valid, 0x36);
  RouterBox_route__io_up_din_valid__prev = RouterBox_route__io_up_din_valid;
  dat_dump<1>(f, RouterBox_route__din_up_valid, 0x37);
  RouterBox_route__din_up_valid__prev = RouterBox_route__din_up_valid;
  dat_dump<1>(f, RouterBox_route__dout_down_valid, 0x38);
  RouterBox_route__dout_down_valid__prev = RouterBox_route__dout_down_valid;
  dat_dump<1>(f, RouterBox_route__io_lc_dout_valid, 0x39);
  RouterBox_route__io_lc_dout_valid__prev = RouterBox_route__io_lc_dout_valid;
  dat_dump<1>(f, RouterBox__io_lc_dout_valid, 0x3a);
  RouterBox__io_lc_dout_valid__prev = RouterBox__io_lc_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_r_dout_valid, 0x3b);
  RouterBox_route__io_r_dout_valid__prev = RouterBox_route__io_r_dout_valid;
  dat_dump<1>(f, RouterBox__io_r_dout_valid, 0x3c);
  RouterBox__io_r_dout_valid__prev = RouterBox__io_r_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_le_dout_valid, 0x3d);
  RouterBox_route__io_le_dout_valid__prev = RouterBox_route__io_le_dout_valid;
  dat_dump<1>(f, RouterBox__io_le_dout_valid, 0x3e);
  RouterBox__io_le_dout_valid__prev = RouterBox__io_le_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_up_dout_valid, 0x3f);
  RouterBox_route__io_up_dout_valid__prev = RouterBox_route__io_up_dout_valid;
  dat_dump<1>(f, RouterBox__io_up_dout_valid, 0x40);
  RouterBox__io_up_dout_valid__prev = RouterBox__io_up_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_dn_dout_valid, 0x41);
  RouterBox_route__io_dn_dout_valid__prev = RouterBox_route__io_dn_dout_valid;
  dat_dump<1>(f, RouterBox__io_dn_dout_valid, 0x42);
  RouterBox__io_dn_dout_valid__prev = RouterBox__io_dn_dout_valid;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_local, 0x43);
  RouterBox_schedule_table__io_dir_rInfo_local__prev = RouterBox_schedule_table__io_dir_rInfo_local;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_local, 0x44);
  RouterBox_route__io_routeInfo_rInfo_local__prev = RouterBox_route__io_routeInfo_rInfo_local;
  dat_dump<1>(f, RouterBox_route__directions_local, 0x45);
  RouterBox_route__directions_local__prev = RouterBox_route__directions_local;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_right, 0x46);
  RouterBox_schedule_table__io_dir_rInfo_right__prev = RouterBox_schedule_table__io_dir_rInfo_right;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_right, 0x47);
  RouterBox_route__io_routeInfo_rInfo_right__prev = RouterBox_route__io_routeInfo_rInfo_right;
  dat_dump<1>(f, RouterBox_route__directions_right, 0x48);
  RouterBox_route__directions_right__prev = RouterBox_route__directions_right;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_left, 0x49);
  RouterBox_schedule_table__io_dir_rInfo_left__prev = RouterBox_schedule_table__io_dir_rInfo_left;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_left, 0x4a);
  RouterBox_route__io_routeInfo_rInfo_left__prev = RouterBox_route__io_routeInfo_rInfo_left;
  dat_dump<1>(f, RouterBox_route__directions_left, 0x4b);
  RouterBox_route__directions_left__prev = RouterBox_route__directions_left;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_up, 0x4c);
  RouterBox_schedule_table__io_dir_rInfo_up__prev = RouterBox_schedule_table__io_dir_rInfo_up;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_up, 0x4d);
  RouterBox_route__io_routeInfo_rInfo_up__prev = RouterBox_route__io_routeInfo_rInfo_up;
  dat_dump<1>(f, RouterBox_route__directions_up, 0x4e);
  RouterBox_route__directions_up__prev = RouterBox_route__directions_up;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_down, 0x4f);
  RouterBox_schedule_table__io_dir_rInfo_down__prev = RouterBox_schedule_table__io_dir_rInfo_down;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_down, 0x50);
  RouterBox_route__io_routeInfo_rInfo_down__prev = RouterBox_route__io_routeInfo_rInfo_down;
  dat_dump<1>(f, RouterBox_route__directions_down, 0x51);
  RouterBox_route__directions_down__prev = RouterBox_route__directions_down;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_slotCounter, 0x52);
  RouterBox_route__io_routeInfo_slotCounter__prev = RouterBox_route__io_routeInfo_slotCounter;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_slotCounter, 0x53);
  RouterBox_schedule_table__io_dir_slotCounter__prev = RouterBox_schedule_table__io_dir_slotCounter;
  dat_dump<1>(f, RouterBox_route__reg_slotCount, 0x54);
  RouterBox_route__reg_slotCount__prev = RouterBox_route__reg_slotCount;
  dat_dump<1>(f, RouterBox_route__dout_local_data, 0x55);
  RouterBox_route__dout_local_data__prev = RouterBox_route__dout_local_data;
  dat_dump<1>(f, RouterBox_route__io_test, 0x56);
  RouterBox_route__io_test__prev = RouterBox_route__io_test;
  dat_dump<1>(f, RouterBox_route__dout_right_data, 0x57);
  RouterBox_route__dout_right_data__prev = RouterBox_route__dout_right_data;
  dat_dump<1>(f, RouterBox_route__dout_left_data, 0x58);
  RouterBox_route__dout_left_data__prev = RouterBox_route__dout_left_data;
  dat_dump<1>(f, RouterBox_route__dout_up_data, 0x59);
  RouterBox_route__dout_up_data__prev = RouterBox_route__dout_up_data;
  dat_dump<1>(f, RouterBox__io_lc_din_data, 0x5a);
  RouterBox__io_lc_din_data__prev = RouterBox__io_lc_din_data;
  dat_dump<1>(f, RouterBox_route__io_lc_din_data, 0x5b);
  RouterBox_route__io_lc_din_data__prev = RouterBox_route__io_lc_din_data;
  dat_dump<1>(f, RouterBox_route__din_local_data, 0x5c);
  RouterBox_route__din_local_data__prev = RouterBox_route__din_local_data;
  dat_dump<1>(f, RouterBox__io_le_din_data, 0x5d);
  RouterBox__io_le_din_data__prev = RouterBox__io_le_din_data;
  dat_dump<1>(f, RouterBox_route__io_le_din_data, 0x5e);
  RouterBox_route__io_le_din_data__prev = RouterBox_route__io_le_din_data;
  dat_dump<1>(f, RouterBox_route__din_left_data, 0x5f);
  RouterBox_route__din_left_data__prev = RouterBox_route__din_left_data;
  dat_dump<1>(f, RouterBox__io_dn_din_data, 0x60);
  RouterBox__io_dn_din_data__prev = RouterBox__io_dn_din_data;
  dat_dump<1>(f, RouterBox_route__io_dn_din_data, 0x61);
  RouterBox_route__io_dn_din_data__prev = RouterBox_route__io_dn_din_data;
  dat_dump<1>(f, RouterBox_route__din_down_data, 0x62);
  RouterBox_route__din_down_data__prev = RouterBox_route__din_down_data;
  dat_dump<1>(f, RouterBox__io_r_din_data, 0x63);
  RouterBox__io_r_din_data__prev = RouterBox__io_r_din_data;
  dat_dump<1>(f, RouterBox_route__io_r_din_data, 0x64);
  RouterBox_route__io_r_din_data__prev = RouterBox_route__io_r_din_data;
  dat_dump<1>(f, RouterBox_route__din_right_data, 0x65);
  RouterBox_route__din_right_data__prev = RouterBox_route__din_right_data;
  dat_dump<1>(f, RouterBox__io_up_din_data, 0x66);
  RouterBox__io_up_din_data__prev = RouterBox__io_up_din_data;
  dat_dump<1>(f, RouterBox_route__io_up_din_data, 0x67);
  RouterBox_route__io_up_din_data__prev = RouterBox_route__io_up_din_data;
  dat_dump<1>(f, RouterBox_route__din_up_data, 0x68);
  RouterBox_route__din_up_data__prev = RouterBox_route__din_up_data;
  dat_dump<1>(f, RouterBox_route__dout_down_data, 0x69);
  RouterBox_route__dout_down_data__prev = RouterBox_route__dout_down_data;
  dat_dump<1>(f, RouterBox_route__io_lc_dout_data, 0x6a);
  RouterBox_route__io_lc_dout_data__prev = RouterBox_route__io_lc_dout_data;
  dat_dump<1>(f, RouterBox__io_lc_dout_data, 0x6b);
  RouterBox__io_lc_dout_data__prev = RouterBox__io_lc_dout_data;
  dat_dump<1>(f, RouterBox_route__io_r_dout_data, 0x6c);
  RouterBox_route__io_r_dout_data__prev = RouterBox_route__io_r_dout_data;
  dat_dump<1>(f, RouterBox__io_r_dout_data, 0x6d);
  RouterBox__io_r_dout_data__prev = RouterBox__io_r_dout_data;
  dat_dump<1>(f, RouterBox_route__io_le_dout_data, 0x6e);
  RouterBox_route__io_le_dout_data__prev = RouterBox_route__io_le_dout_data;
  dat_dump<1>(f, RouterBox__io_le_dout_data, 0x6f);
  RouterBox__io_le_dout_data__prev = RouterBox__io_le_dout_data;
  dat_dump<1>(f, RouterBox_route__io_up_dout_data, 0x70);
  RouterBox_route__io_up_dout_data__prev = RouterBox_route__io_up_dout_data;
  dat_dump<1>(f, RouterBox__io_up_dout_data, 0x71);
  RouterBox__io_up_dout_data__prev = RouterBox__io_up_dout_data;
  dat_dump<1>(f, RouterBox_route__io_dn_dout_data, 0x72);
  RouterBox_route__io_dn_dout_data__prev = RouterBox_route__io_dn_dout_data;
  dat_dump<1>(f, RouterBox__io_dn_dout_data, 0x73);
  RouterBox__io_dn_dout_data__prev = RouterBox__io_dn_dout_data;
  fputs("#1\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 0;
    dat_dump<1>(f, clk, 0x21);
  }
}


void RouterBox_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
  if (t == 0L) return dump_init(f);
  fprintf(f, "#%lu\n", t << 1);
  if (clk.cnt == 0)  goto L0;
K0:  if (reset != reset__prev)  goto L1;
K1:  if (RouterBox_route__reset != RouterBox_route__reset__prev)  goto L2;
K2:  if (RouterBox_route__dout_local_valid != RouterBox_route__dout_local_valid__prev)  goto L3;
K3:  if (RouterBox_route__io_ready != RouterBox_route__io_ready__prev)  goto L4;
K4:  if (RouterBox_route__dout_right_valid != RouterBox_route__dout_right_valid__prev)  goto L5;
K5:  if (RouterBox_route__dout_left_valid != RouterBox_route__dout_left_valid__prev)  goto L6;
K6:  if (RouterBox_route__dout_up_valid != RouterBox_route__dout_up_valid__prev)  goto L7;
K7:  if (RouterBox__io_lc_din_valid != RouterBox__io_lc_din_valid__prev)  goto L8;
K8:  if (RouterBox_route__io_lc_din_valid != RouterBox_route__io_lc_din_valid__prev)  goto L9;
K9:  if (RouterBox_route__din_local_valid != RouterBox_route__din_local_valid__prev)  goto L10;
K10:  if (RouterBox__io_le_din_valid != RouterBox__io_le_din_valid__prev)  goto L11;
K11:  if (RouterBox_route__io_le_din_valid != RouterBox_route__io_le_din_valid__prev)  goto L12;
K12:  if (RouterBox_route__din_left_valid != RouterBox_route__din_left_valid__prev)  goto L13;
K13:  if (RouterBox__io_dn_din_valid != RouterBox__io_dn_din_valid__prev)  goto L14;
K14:  if (RouterBox_route__io_dn_din_valid != RouterBox_route__io_dn_din_valid__prev)  goto L15;
K15:  if (RouterBox_route__din_down_valid != RouterBox_route__din_down_valid__prev)  goto L16;
K16:  if (RouterBox__io_r_din_valid != RouterBox__io_r_din_valid__prev)  goto L17;
K17:  if (RouterBox_route__io_r_din_valid != RouterBox_route__io_r_din_valid__prev)  goto L18;
K18:  if (RouterBox_route__din_right_valid != RouterBox_route__din_right_valid__prev)  goto L19;
K19:  if (RouterBox__io_up_din_valid != RouterBox__io_up_din_valid__prev)  goto L20;
K20:  if (RouterBox_route__io_up_din_valid != RouterBox_route__io_up_din_valid__prev)  goto L21;
K21:  if (RouterBox_route__din_up_valid != RouterBox_route__din_up_valid__prev)  goto L22;
K22:  if (RouterBox_route__dout_down_valid != RouterBox_route__dout_down_valid__prev)  goto L23;
K23:  if (RouterBox_route__io_lc_dout_valid != RouterBox_route__io_lc_dout_valid__prev)  goto L24;
K24:  if (RouterBox__io_lc_dout_valid != RouterBox__io_lc_dout_valid__prev)  goto L25;
K25:  if (RouterBox_route__io_r_dout_valid != RouterBox_route__io_r_dout_valid__prev)  goto L26;
K26:  if (RouterBox__io_r_dout_valid != RouterBox__io_r_dout_valid__prev)  goto L27;
K27:  if (RouterBox_route__io_le_dout_valid != RouterBox_route__io_le_dout_valid__prev)  goto L28;
K28:  if (RouterBox__io_le_dout_valid != RouterBox__io_le_dout_valid__prev)  goto L29;
K29:  if (RouterBox_route__io_up_dout_valid != RouterBox_route__io_up_dout_valid__prev)  goto L30;
K30:  if (RouterBox__io_up_dout_valid != RouterBox__io_up_dout_valid__prev)  goto L31;
K31:  if (RouterBox_route__io_dn_dout_valid != RouterBox_route__io_dn_dout_valid__prev)  goto L32;
K32:  if (RouterBox__io_dn_dout_valid != RouterBox__io_dn_dout_valid__prev)  goto L33;
K33:  if (RouterBox_schedule_table__io_dir_rInfo_local != RouterBox_schedule_table__io_dir_rInfo_local__prev)  goto L34;
K34:  if (RouterBox_route__io_routeInfo_rInfo_local != RouterBox_route__io_routeInfo_rInfo_local__prev)  goto L35;
K35:  if (RouterBox_route__directions_local != RouterBox_route__directions_local__prev)  goto L36;
K36:  if (RouterBox_schedule_table__io_dir_rInfo_right != RouterBox_schedule_table__io_dir_rInfo_right__prev)  goto L37;
K37:  if (RouterBox_route__io_routeInfo_rInfo_right != RouterBox_route__io_routeInfo_rInfo_right__prev)  goto L38;
K38:  if (RouterBox_route__directions_right != RouterBox_route__directions_right__prev)  goto L39;
K39:  if (RouterBox_schedule_table__io_dir_rInfo_left != RouterBox_schedule_table__io_dir_rInfo_left__prev)  goto L40;
K40:  if (RouterBox_route__io_routeInfo_rInfo_left != RouterBox_route__io_routeInfo_rInfo_left__prev)  goto L41;
K41:  if (RouterBox_route__directions_left != RouterBox_route__directions_left__prev)  goto L42;
K42:  if (RouterBox_schedule_table__io_dir_rInfo_up != RouterBox_schedule_table__io_dir_rInfo_up__prev)  goto L43;
K43:  if (RouterBox_route__io_routeInfo_rInfo_up != RouterBox_route__io_routeInfo_rInfo_up__prev)  goto L44;
K44:  if (RouterBox_route__directions_up != RouterBox_route__directions_up__prev)  goto L45;
K45:  if (RouterBox_schedule_table__io_dir_rInfo_down != RouterBox_schedule_table__io_dir_rInfo_down__prev)  goto L46;
K46:  if (RouterBox_route__io_routeInfo_rInfo_down != RouterBox_route__io_routeInfo_rInfo_down__prev)  goto L47;
K47:  if (RouterBox_route__directions_down != RouterBox_route__directions_down__prev)  goto L48;
K48:  if (RouterBox_route__io_routeInfo_slotCounter != RouterBox_route__io_routeInfo_slotCounter__prev)  goto L49;
K49:  if (RouterBox_schedule_table__io_dir_slotCounter != RouterBox_schedule_table__io_dir_slotCounter__prev)  goto L50;
K50:  if (RouterBox_route__reg_slotCount != RouterBox_route__reg_slotCount__prev)  goto L51;
K51:  if (RouterBox_route__dout_local_data != RouterBox_route__dout_local_data__prev)  goto L52;
K52:  if (RouterBox_route__io_test != RouterBox_route__io_test__prev)  goto L53;
K53:  if (RouterBox_route__dout_right_data != RouterBox_route__dout_right_data__prev)  goto L54;
K54:  if (RouterBox_route__dout_left_data != RouterBox_route__dout_left_data__prev)  goto L55;
K55:  if (RouterBox_route__dout_up_data != RouterBox_route__dout_up_data__prev)  goto L56;
K56:  if (RouterBox__io_lc_din_data != RouterBox__io_lc_din_data__prev)  goto L57;
K57:  if (RouterBox_route__io_lc_din_data != RouterBox_route__io_lc_din_data__prev)  goto L58;
K58:  if (RouterBox_route__din_local_data != RouterBox_route__din_local_data__prev)  goto L59;
K59:  if (RouterBox__io_le_din_data != RouterBox__io_le_din_data__prev)  goto L60;
K60:  if (RouterBox_route__io_le_din_data != RouterBox_route__io_le_din_data__prev)  goto L61;
K61:  if (RouterBox_route__din_left_data != RouterBox_route__din_left_data__prev)  goto L62;
K62:  if (RouterBox__io_dn_din_data != RouterBox__io_dn_din_data__prev)  goto L63;
K63:  if (RouterBox_route__io_dn_din_data != RouterBox_route__io_dn_din_data__prev)  goto L64;
K64:  if (RouterBox_route__din_down_data != RouterBox_route__din_down_data__prev)  goto L65;
K65:  if (RouterBox__io_r_din_data != RouterBox__io_r_din_data__prev)  goto L66;
K66:  if (RouterBox_route__io_r_din_data != RouterBox_route__io_r_din_data__prev)  goto L67;
K67:  if (RouterBox_route__din_right_data != RouterBox_route__din_right_data__prev)  goto L68;
K68:  if (RouterBox__io_up_din_data != RouterBox__io_up_din_data__prev)  goto L69;
K69:  if (RouterBox_route__io_up_din_data != RouterBox_route__io_up_din_data__prev)  goto L70;
K70:  if (RouterBox_route__din_up_data != RouterBox_route__din_up_data__prev)  goto L71;
K71:  if (RouterBox_route__dout_down_data != RouterBox_route__dout_down_data__prev)  goto L72;
K72:  if (RouterBox_route__io_lc_dout_data != RouterBox_route__io_lc_dout_data__prev)  goto L73;
K73:  if (RouterBox__io_lc_dout_data != RouterBox__io_lc_dout_data__prev)  goto L74;
K74:  if (RouterBox_route__io_r_dout_data != RouterBox_route__io_r_dout_data__prev)  goto L75;
K75:  if (RouterBox__io_r_dout_data != RouterBox__io_r_dout_data__prev)  goto L76;
K76:  if (RouterBox_route__io_le_dout_data != RouterBox_route__io_le_dout_data__prev)  goto L77;
K77:  if (RouterBox__io_le_dout_data != RouterBox__io_le_dout_data__prev)  goto L78;
K78:  if (RouterBox_route__io_up_dout_data != RouterBox_route__io_up_dout_data__prev)  goto L79;
K79:  if (RouterBox__io_up_dout_data != RouterBox__io_up_dout_data__prev)  goto L80;
K80:  if (RouterBox_route__io_dn_dout_data != RouterBox_route__io_dn_dout_data__prev)  goto L81;
K81:  if (RouterBox__io_dn_dout_data != RouterBox__io_dn_dout_data__prev)  goto L82;
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
  RouterBox_route__reset__prev = RouterBox_route__reset;
  dat_dump<1>(f, RouterBox_route__reset, 0x23);
  goto K2;
L3:
  RouterBox_route__dout_local_valid__prev = RouterBox_route__dout_local_valid;
  dat_dump<1>(f, RouterBox_route__dout_local_valid, 0x24);
  goto K3;
L4:
  RouterBox_route__io_ready__prev = RouterBox_route__io_ready;
  dat_dump<1>(f, RouterBox_route__io_ready, 0x25);
  goto K4;
L5:
  RouterBox_route__dout_right_valid__prev = RouterBox_route__dout_right_valid;
  dat_dump<1>(f, RouterBox_route__dout_right_valid, 0x26);
  goto K5;
L6:
  RouterBox_route__dout_left_valid__prev = RouterBox_route__dout_left_valid;
  dat_dump<1>(f, RouterBox_route__dout_left_valid, 0x27);
  goto K6;
L7:
  RouterBox_route__dout_up_valid__prev = RouterBox_route__dout_up_valid;
  dat_dump<1>(f, RouterBox_route__dout_up_valid, 0x28);
  goto K7;
L8:
  RouterBox__io_lc_din_valid__prev = RouterBox__io_lc_din_valid;
  dat_dump<1>(f, RouterBox__io_lc_din_valid, 0x29);
  goto K8;
L9:
  RouterBox_route__io_lc_din_valid__prev = RouterBox_route__io_lc_din_valid;
  dat_dump<1>(f, RouterBox_route__io_lc_din_valid, 0x2a);
  goto K9;
L10:
  RouterBox_route__din_local_valid__prev = RouterBox_route__din_local_valid;
  dat_dump<1>(f, RouterBox_route__din_local_valid, 0x2b);
  goto K10;
L11:
  RouterBox__io_le_din_valid__prev = RouterBox__io_le_din_valid;
  dat_dump<1>(f, RouterBox__io_le_din_valid, 0x2c);
  goto K11;
L12:
  RouterBox_route__io_le_din_valid__prev = RouterBox_route__io_le_din_valid;
  dat_dump<1>(f, RouterBox_route__io_le_din_valid, 0x2d);
  goto K12;
L13:
  RouterBox_route__din_left_valid__prev = RouterBox_route__din_left_valid;
  dat_dump<1>(f, RouterBox_route__din_left_valid, 0x2e);
  goto K13;
L14:
  RouterBox__io_dn_din_valid__prev = RouterBox__io_dn_din_valid;
  dat_dump<1>(f, RouterBox__io_dn_din_valid, 0x2f);
  goto K14;
L15:
  RouterBox_route__io_dn_din_valid__prev = RouterBox_route__io_dn_din_valid;
  dat_dump<1>(f, RouterBox_route__io_dn_din_valid, 0x30);
  goto K15;
L16:
  RouterBox_route__din_down_valid__prev = RouterBox_route__din_down_valid;
  dat_dump<1>(f, RouterBox_route__din_down_valid, 0x31);
  goto K16;
L17:
  RouterBox__io_r_din_valid__prev = RouterBox__io_r_din_valid;
  dat_dump<1>(f, RouterBox__io_r_din_valid, 0x32);
  goto K17;
L18:
  RouterBox_route__io_r_din_valid__prev = RouterBox_route__io_r_din_valid;
  dat_dump<1>(f, RouterBox_route__io_r_din_valid, 0x33);
  goto K18;
L19:
  RouterBox_route__din_right_valid__prev = RouterBox_route__din_right_valid;
  dat_dump<1>(f, RouterBox_route__din_right_valid, 0x34);
  goto K19;
L20:
  RouterBox__io_up_din_valid__prev = RouterBox__io_up_din_valid;
  dat_dump<1>(f, RouterBox__io_up_din_valid, 0x35);
  goto K20;
L21:
  RouterBox_route__io_up_din_valid__prev = RouterBox_route__io_up_din_valid;
  dat_dump<1>(f, RouterBox_route__io_up_din_valid, 0x36);
  goto K21;
L22:
  RouterBox_route__din_up_valid__prev = RouterBox_route__din_up_valid;
  dat_dump<1>(f, RouterBox_route__din_up_valid, 0x37);
  goto K22;
L23:
  RouterBox_route__dout_down_valid__prev = RouterBox_route__dout_down_valid;
  dat_dump<1>(f, RouterBox_route__dout_down_valid, 0x38);
  goto K23;
L24:
  RouterBox_route__io_lc_dout_valid__prev = RouterBox_route__io_lc_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_lc_dout_valid, 0x39);
  goto K24;
L25:
  RouterBox__io_lc_dout_valid__prev = RouterBox__io_lc_dout_valid;
  dat_dump<1>(f, RouterBox__io_lc_dout_valid, 0x3a);
  goto K25;
L26:
  RouterBox_route__io_r_dout_valid__prev = RouterBox_route__io_r_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_r_dout_valid, 0x3b);
  goto K26;
L27:
  RouterBox__io_r_dout_valid__prev = RouterBox__io_r_dout_valid;
  dat_dump<1>(f, RouterBox__io_r_dout_valid, 0x3c);
  goto K27;
L28:
  RouterBox_route__io_le_dout_valid__prev = RouterBox_route__io_le_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_le_dout_valid, 0x3d);
  goto K28;
L29:
  RouterBox__io_le_dout_valid__prev = RouterBox__io_le_dout_valid;
  dat_dump<1>(f, RouterBox__io_le_dout_valid, 0x3e);
  goto K29;
L30:
  RouterBox_route__io_up_dout_valid__prev = RouterBox_route__io_up_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_up_dout_valid, 0x3f);
  goto K30;
L31:
  RouterBox__io_up_dout_valid__prev = RouterBox__io_up_dout_valid;
  dat_dump<1>(f, RouterBox__io_up_dout_valid, 0x40);
  goto K31;
L32:
  RouterBox_route__io_dn_dout_valid__prev = RouterBox_route__io_dn_dout_valid;
  dat_dump<1>(f, RouterBox_route__io_dn_dout_valid, 0x41);
  goto K32;
L33:
  RouterBox__io_dn_dout_valid__prev = RouterBox__io_dn_dout_valid;
  dat_dump<1>(f, RouterBox__io_dn_dout_valid, 0x42);
  goto K33;
L34:
  RouterBox_schedule_table__io_dir_rInfo_local__prev = RouterBox_schedule_table__io_dir_rInfo_local;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_local, 0x43);
  goto K34;
L35:
  RouterBox_route__io_routeInfo_rInfo_local__prev = RouterBox_route__io_routeInfo_rInfo_local;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_local, 0x44);
  goto K35;
L36:
  RouterBox_route__directions_local__prev = RouterBox_route__directions_local;
  dat_dump<1>(f, RouterBox_route__directions_local, 0x45);
  goto K36;
L37:
  RouterBox_schedule_table__io_dir_rInfo_right__prev = RouterBox_schedule_table__io_dir_rInfo_right;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_right, 0x46);
  goto K37;
L38:
  RouterBox_route__io_routeInfo_rInfo_right__prev = RouterBox_route__io_routeInfo_rInfo_right;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_right, 0x47);
  goto K38;
L39:
  RouterBox_route__directions_right__prev = RouterBox_route__directions_right;
  dat_dump<1>(f, RouterBox_route__directions_right, 0x48);
  goto K39;
L40:
  RouterBox_schedule_table__io_dir_rInfo_left__prev = RouterBox_schedule_table__io_dir_rInfo_left;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_left, 0x49);
  goto K40;
L41:
  RouterBox_route__io_routeInfo_rInfo_left__prev = RouterBox_route__io_routeInfo_rInfo_left;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_left, 0x4a);
  goto K41;
L42:
  RouterBox_route__directions_left__prev = RouterBox_route__directions_left;
  dat_dump<1>(f, RouterBox_route__directions_left, 0x4b);
  goto K42;
L43:
  RouterBox_schedule_table__io_dir_rInfo_up__prev = RouterBox_schedule_table__io_dir_rInfo_up;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_up, 0x4c);
  goto K43;
L44:
  RouterBox_route__io_routeInfo_rInfo_up__prev = RouterBox_route__io_routeInfo_rInfo_up;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_up, 0x4d);
  goto K44;
L45:
  RouterBox_route__directions_up__prev = RouterBox_route__directions_up;
  dat_dump<1>(f, RouterBox_route__directions_up, 0x4e);
  goto K45;
L46:
  RouterBox_schedule_table__io_dir_rInfo_down__prev = RouterBox_schedule_table__io_dir_rInfo_down;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_rInfo_down, 0x4f);
  goto K46;
L47:
  RouterBox_route__io_routeInfo_rInfo_down__prev = RouterBox_route__io_routeInfo_rInfo_down;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_rInfo_down, 0x50);
  goto K47;
L48:
  RouterBox_route__directions_down__prev = RouterBox_route__directions_down;
  dat_dump<1>(f, RouterBox_route__directions_down, 0x51);
  goto K48;
L49:
  RouterBox_route__io_routeInfo_slotCounter__prev = RouterBox_route__io_routeInfo_slotCounter;
  dat_dump<1>(f, RouterBox_route__io_routeInfo_slotCounter, 0x52);
  goto K49;
L50:
  RouterBox_schedule_table__io_dir_slotCounter__prev = RouterBox_schedule_table__io_dir_slotCounter;
  dat_dump<1>(f, RouterBox_schedule_table__io_dir_slotCounter, 0x53);
  goto K50;
L51:
  RouterBox_route__reg_slotCount__prev = RouterBox_route__reg_slotCount;
  dat_dump<1>(f, RouterBox_route__reg_slotCount, 0x54);
  goto K51;
L52:
  RouterBox_route__dout_local_data__prev = RouterBox_route__dout_local_data;
  dat_dump<1>(f, RouterBox_route__dout_local_data, 0x55);
  goto K52;
L53:
  RouterBox_route__io_test__prev = RouterBox_route__io_test;
  dat_dump<1>(f, RouterBox_route__io_test, 0x56);
  goto K53;
L54:
  RouterBox_route__dout_right_data__prev = RouterBox_route__dout_right_data;
  dat_dump<1>(f, RouterBox_route__dout_right_data, 0x57);
  goto K54;
L55:
  RouterBox_route__dout_left_data__prev = RouterBox_route__dout_left_data;
  dat_dump<1>(f, RouterBox_route__dout_left_data, 0x58);
  goto K55;
L56:
  RouterBox_route__dout_up_data__prev = RouterBox_route__dout_up_data;
  dat_dump<1>(f, RouterBox_route__dout_up_data, 0x59);
  goto K56;
L57:
  RouterBox__io_lc_din_data__prev = RouterBox__io_lc_din_data;
  dat_dump<1>(f, RouterBox__io_lc_din_data, 0x5a);
  goto K57;
L58:
  RouterBox_route__io_lc_din_data__prev = RouterBox_route__io_lc_din_data;
  dat_dump<1>(f, RouterBox_route__io_lc_din_data, 0x5b);
  goto K58;
L59:
  RouterBox_route__din_local_data__prev = RouterBox_route__din_local_data;
  dat_dump<1>(f, RouterBox_route__din_local_data, 0x5c);
  goto K59;
L60:
  RouterBox__io_le_din_data__prev = RouterBox__io_le_din_data;
  dat_dump<1>(f, RouterBox__io_le_din_data, 0x5d);
  goto K60;
L61:
  RouterBox_route__io_le_din_data__prev = RouterBox_route__io_le_din_data;
  dat_dump<1>(f, RouterBox_route__io_le_din_data, 0x5e);
  goto K61;
L62:
  RouterBox_route__din_left_data__prev = RouterBox_route__din_left_data;
  dat_dump<1>(f, RouterBox_route__din_left_data, 0x5f);
  goto K62;
L63:
  RouterBox__io_dn_din_data__prev = RouterBox__io_dn_din_data;
  dat_dump<1>(f, RouterBox__io_dn_din_data, 0x60);
  goto K63;
L64:
  RouterBox_route__io_dn_din_data__prev = RouterBox_route__io_dn_din_data;
  dat_dump<1>(f, RouterBox_route__io_dn_din_data, 0x61);
  goto K64;
L65:
  RouterBox_route__din_down_data__prev = RouterBox_route__din_down_data;
  dat_dump<1>(f, RouterBox_route__din_down_data, 0x62);
  goto K65;
L66:
  RouterBox__io_r_din_data__prev = RouterBox__io_r_din_data;
  dat_dump<1>(f, RouterBox__io_r_din_data, 0x63);
  goto K66;
L67:
  RouterBox_route__io_r_din_data__prev = RouterBox_route__io_r_din_data;
  dat_dump<1>(f, RouterBox_route__io_r_din_data, 0x64);
  goto K67;
L68:
  RouterBox_route__din_right_data__prev = RouterBox_route__din_right_data;
  dat_dump<1>(f, RouterBox_route__din_right_data, 0x65);
  goto K68;
L69:
  RouterBox__io_up_din_data__prev = RouterBox__io_up_din_data;
  dat_dump<1>(f, RouterBox__io_up_din_data, 0x66);
  goto K69;
L70:
  RouterBox_route__io_up_din_data__prev = RouterBox_route__io_up_din_data;
  dat_dump<1>(f, RouterBox_route__io_up_din_data, 0x67);
  goto K70;
L71:
  RouterBox_route__din_up_data__prev = RouterBox_route__din_up_data;
  dat_dump<1>(f, RouterBox_route__din_up_data, 0x68);
  goto K71;
L72:
  RouterBox_route__dout_down_data__prev = RouterBox_route__dout_down_data;
  dat_dump<1>(f, RouterBox_route__dout_down_data, 0x69);
  goto K72;
L73:
  RouterBox_route__io_lc_dout_data__prev = RouterBox_route__io_lc_dout_data;
  dat_dump<1>(f, RouterBox_route__io_lc_dout_data, 0x6a);
  goto K73;
L74:
  RouterBox__io_lc_dout_data__prev = RouterBox__io_lc_dout_data;
  dat_dump<1>(f, RouterBox__io_lc_dout_data, 0x6b);
  goto K74;
L75:
  RouterBox_route__io_r_dout_data__prev = RouterBox_route__io_r_dout_data;
  dat_dump<1>(f, RouterBox_route__io_r_dout_data, 0x6c);
  goto K75;
L76:
  RouterBox__io_r_dout_data__prev = RouterBox__io_r_dout_data;
  dat_dump<1>(f, RouterBox__io_r_dout_data, 0x6d);
  goto K76;
L77:
  RouterBox_route__io_le_dout_data__prev = RouterBox_route__io_le_dout_data;
  dat_dump<1>(f, RouterBox_route__io_le_dout_data, 0x6e);
  goto K77;
L78:
  RouterBox__io_le_dout_data__prev = RouterBox__io_le_dout_data;
  dat_dump<1>(f, RouterBox__io_le_dout_data, 0x6f);
  goto K78;
L79:
  RouterBox_route__io_up_dout_data__prev = RouterBox_route__io_up_dout_data;
  dat_dump<1>(f, RouterBox_route__io_up_dout_data, 0x70);
  goto K79;
L80:
  RouterBox__io_up_dout_data__prev = RouterBox__io_up_dout_data;
  dat_dump<1>(f, RouterBox__io_up_dout_data, 0x71);
  goto K80;
L81:
  RouterBox_route__io_dn_dout_data__prev = RouterBox_route__io_dn_dout_data;
  dat_dump<1>(f, RouterBox_route__io_dn_dout_data, 0x72);
  goto K81;
L82:
  RouterBox__io_dn_dout_data__prev = RouterBox__io_dn_dout_data;
  dat_dump<1>(f, RouterBox__io_dn_dout_data, 0x73);
  goto K82;
Z0:
  clk.values[0] = 0;
  dat_dump<1>(f, clk, 0x21);
  goto C0;
}




void RouterBox_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  val_t T0;
  { T0 = RouterBox_route__reg_slotCount.values[0]+0x1L;}
  T0 = T0 & 0x7ffffL;
  { RouterBox_route__reset.values[0] = reset.values[0];}
  { T1.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T0);}
  val_t T2;
  T2 = 0x5L == RouterBox_route__directions_local.values[0];
  val_t T3;
  { T3 = TERNARY_1(T2, RouterBox_route__din_up_data.values[0], RouterBox_route__dout_local_data.values[0]);}
  val_t T4;
  T4 = 0x4L == RouterBox_route__directions_local.values[0];
  val_t T5;
  { T5 = TERNARY_1(T4, RouterBox_route__din_right_data.values[0], T3);}
  val_t T6;
  T6 = 0x2L == RouterBox_route__directions_local.values[0];
  val_t T7;
  { T7 = TERNARY_1(T6, RouterBox_route__din_down_data.values[0], T5);}
  val_t T8;
  T8 = 0x3L == RouterBox_route__directions_local.values[0];
  val_t T9;
  { T9 = TERNARY_1(T8, RouterBox_route__din_left_data.values[0], T7);}
  val_t T10;
  T10 = 0x1L == RouterBox_route__directions_local.values[0];
  val_t T11;
  { T11 = TERNARY_1(T10, RouterBox_route__din_local_data.values[0], T9);}
  val_t T12;
  T12 = 0x0L == RouterBox_route__directions_local.values[0];
  val_t T13;
  { T13 = TERNARY(T12, 0x0L, T11);}
  { T14.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T13);}
  val_t T15;
  { T15 = RouterBox_route__reg_slotCount.values[0];}
  T15 = T15 & 0xffffL;
  { RouterBox_route__io_routeInfo_slotCounter.values[0] = T15;}
  { RouterBox_schedule_table__io_dir_slotCounter.values[0] = RouterBox_route__io_routeInfo_slotCounter.values[0];}
  val_t T16;
  T16 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x0L;
  val_t T17;
  { T17 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T18;
  T18 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x1L;
  val_t T19;
  { T19 = T16 ^ 0x1L;}
  val_t T20;
  { T20 = T19 & T18;}
  val_t T21;
  { T21 = TERNARY(T20, 0x0L, T17);}
  val_t T22;
  T22 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x2L;
  val_t T23;
  { T23 = T16 | T18;}
  val_t T24;
  { T24 = T23 ^ 0x1L;}
  val_t T25;
  { T25 = T24 & T22;}
  val_t T26;
  { T26 = TERNARY(T25, 0x0L, T21);}
  val_t T27;
  T27 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x3L;
  val_t T28;
  { T28 = T23 | T22;}
  val_t T29;
  { T29 = T28 ^ 0x1L;}
  val_t T30;
  { T30 = T29 & T27;}
  val_t T31;
  { T31 = TERNARY(T30, 0x5L, T26);}
  val_t T32;
  T32 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x4L;
  val_t T33;
  { T33 = T28 | T27;}
  val_t T34;
  { T34 = T33 ^ 0x1L;}
  val_t T35;
  { T35 = T34 & T32;}
  val_t T36;
  { T36 = TERNARY(T35, 0x3L, T31);}
  val_t T37;
  T37 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x5L;
  val_t T38;
  { T38 = T33 | T32;}
  val_t T39;
  { T39 = T38 ^ 0x1L;}
  val_t T40;
  { T40 = T39 & T37;}
  val_t T41;
  { T41 = TERNARY(T40, 0x0L, T36);}
  val_t T42;
  T42 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x6L;
  val_t T43;
  { T43 = T38 | T37;}
  val_t T44;
  { T44 = T43 ^ 0x1L;}
  val_t T45;
  { T45 = T44 & T42;}
  val_t T46;
  { T46 = TERNARY(T45, 0x3L, T41);}
  val_t T47;
  T47 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x7L;
  val_t T48;
  { T48 = T43 | T42;}
  val_t T49;
  { T49 = T48 ^ 0x1L;}
  val_t T50;
  { T50 = T49 & T47;}
  val_t T51;
  { T51 = TERNARY(T50, 0x3L, T46);}
  val_t T52;
  T52 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x8L;
  val_t T53;
  { T53 = T48 | T47;}
  val_t T54;
  { T54 = T53 ^ 0x1L;}
  val_t T55;
  { T55 = T54 & T52;}
  val_t T56;
  { T56 = TERNARY(T55, 0x2L, T51);}
  val_t T57;
  T57 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x9L;
  val_t T58;
  { T58 = T53 | T52;}
  val_t T59;
  { T59 = T58 ^ 0x1L;}
  val_t T60;
  { T60 = T59 & T57;}
  val_t T61;
  { T61 = TERNARY(T60, 0x2L, T56);}
  val_t T62;
  T62 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0xaL;
  val_t T63;
  { T63 = T58 | T57;}
  val_t T64;
  { T64 = T63 ^ 0x1L;}
  val_t T65;
  { T65 = T64 & T62;}
  val_t T66;
  { T66 = TERNARY(T65, 0x5L, T61);}
  val_t T67;
  T67 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0xbL;
  val_t T68;
  { T68 = T63 | T62;}
  val_t T69;
  { T69 = T68 ^ 0x1L;}
  val_t T70;
  { T70 = T69 & T67;}
  val_t T71;
  { T71 = TERNARY(T70, 0x3L, T66);}
  val_t T72;
  T72 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0xcL;
  val_t T73;
  { T73 = T68 | T67;}
  val_t T74;
  { T74 = T73 ^ 0x1L;}
  val_t T75;
  { T75 = T74 & T72;}
  val_t T76;
  { T76 = TERNARY(T75, 0x4L, T71);}
  val_t T77;
  T77 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0xdL;
  val_t T78;
  { T78 = T73 | T72;}
  val_t T79;
  { T79 = T78 ^ 0x1L;}
  val_t T80;
  { T80 = T79 & T77;}
  val_t T81;
  { T81 = TERNARY(T80, 0x2L, T76);}
  val_t T82;
  T82 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0xeL;
  val_t T83;
  { T83 = T78 | T77;}
  val_t T84;
  { T84 = T83 ^ 0x1L;}
  val_t T85;
  { T85 = T84 & T82;}
  val_t T86;
  { T86 = TERNARY(T85, 0x3L, T81);}
  val_t T87;
  T87 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0xfL;
  val_t T88;
  { T88 = T83 | T82;}
  val_t T89;
  { T89 = T88 ^ 0x1L;}
  val_t T90;
  { T90 = T89 & T87;}
  val_t T91;
  { T91 = TERNARY(T90, 0x4L, T86);}
  val_t T92;
  T92 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x10L;
  val_t T93;
  { T93 = T88 | T87;}
  val_t T94;
  { T94 = T93 ^ 0x1L;}
  val_t T95;
  { T95 = T94 & T92;}
  val_t T96;
  { T96 = TERNARY(T95, 0x3L, T91);}
  val_t T97;
  T97 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x11L;
  val_t T98;
  { T98 = T93 | T92;}
  val_t T99;
  { T99 = T98 ^ 0x1L;}
  val_t T100;
  { T100 = T99 & T97;}
  val_t T101;
  { T101 = TERNARY(T100, 0x5L, T96);}
  val_t T102;
  T102 = RouterBox_schedule_table__io_dir_slotCounter.values[0] == 0x12L;
  val_t T103;
  { T103 = T98 | T97;}
  val_t T104;
  { T104 = T103 ^ 0x1L;}
  val_t T105;
  { T105 = T104 & T102;}
  val_t T106;
  { T106 = TERNARY(T105, 0x4L, T101);}
  { RouterBox_schedule_table__io_dir_rInfo_local.values[0] = T106;}
  { RouterBox_route__io_routeInfo_rInfo_local.values[0] = RouterBox_schedule_table__io_dir_rInfo_local.values[0];}
  { T107.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_routeInfo_rInfo_local.values[0]);}
  val_t T108;
  { T108 = TERNARY_1(T2, RouterBox_route__din_up_valid.values[0], RouterBox_route__dout_local_valid.values[0]);}
  val_t T109;
  { T109 = TERNARY_1(T4, RouterBox_route__din_right_valid.values[0], T108);}
  val_t T110;
  { T110 = TERNARY_1(T6, RouterBox_route__din_down_valid.values[0], T109);}
  val_t T111;
  { T111 = TERNARY_1(T8, RouterBox_route__din_left_valid.values[0], T110);}
  val_t T112;
  { T112 = TERNARY_1(T10, RouterBox_route__din_local_valid.values[0], T111);}
  val_t T113;
  { T113 = TERNARY(T12, 0x0L, T112);}
  { T114.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T113);}
  { val_t __r = this->__rand_val(); RouterBox_route__io_test.values[0] = __r;}
  RouterBox_route__io_test.values[0] = RouterBox_route__io_test.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); RouterBox_route__io_ready.values[0] = __r;}
  RouterBox_route__io_ready.values[0] = RouterBox_route__io_ready.values[0] & 0x1L;
  val_t T115;
  T115 = 0x5L == RouterBox_route__directions_right.values[0];
  val_t T116;
  { T116 = TERNARY_1(T115, RouterBox_route__din_up_data.values[0], RouterBox_route__dout_right_data.values[0]);}
  val_t T117;
  T117 = 0x4L == RouterBox_route__directions_right.values[0];
  val_t T118;
  { T118 = TERNARY_1(T117, RouterBox_route__din_right_data.values[0], T116);}
  val_t T119;
  T119 = 0x2L == RouterBox_route__directions_right.values[0];
  val_t T120;
  { T120 = TERNARY_1(T119, RouterBox_route__din_down_data.values[0], T118);}
  val_t T121;
  T121 = 0x3L == RouterBox_route__directions_right.values[0];
  val_t T122;
  { T122 = TERNARY_1(T121, RouterBox_route__din_left_data.values[0], T120);}
  val_t T123;
  T123 = 0x1L == RouterBox_route__directions_right.values[0];
  val_t T124;
  { T124 = TERNARY_1(T123, RouterBox_route__din_local_data.values[0], T122);}
  val_t T125;
  T125 = 0x0L == RouterBox_route__directions_right.values[0];
  val_t T126;
  { T126 = TERNARY(T125, 0x0L, T124);}
  { T127.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T126);}
  val_t T128;
  { T128 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T129;
  { T129 = TERNARY(T20, 0x1L, T128);}
  val_t T130;
  { T130 = TERNARY(T25, 0x2L, T129);}
  val_t T131;
  { T131 = TERNARY(T30, 0x3L, T130);}
  val_t T132;
  { T132 = TERNARY(T35, 0x2L, T131);}
  val_t T133;
  { T133 = TERNARY(T40, 0x3L, T132);}
  val_t T134;
  { T134 = TERNARY(T45, 0x2L, T133);}
  val_t T135;
  { T135 = TERNARY(T50, 0x1L, T134);}
  val_t T136;
  { T136 = TERNARY(T55, 0x3L, T135);}
  val_t T137;
  { T137 = TERNARY(T60, 0x0L, T136);}
  val_t T138;
  { T138 = TERNARY(T65, 0x2L, T137);}
  val_t T139;
  { T139 = TERNARY(T70, 0x0L, T138);}
  val_t T140;
  { T140 = TERNARY(T75, 0x1L, T139);}
  val_t T141;
  { T141 = TERNARY(T80, 0x3L, T140);}
  val_t T142;
  { T142 = TERNARY(T85, 0x0L, T141);}
  val_t T143;
  { T143 = TERNARY(T90, 0x1L, T142);}
  val_t T144;
  { T144 = TERNARY(T95, 0x0L, T143);}
  val_t T145;
  { T145 = TERNARY(T100, 0x0L, T144);}
  val_t T146;
  { T146 = TERNARY(T105, 0x0L, T145);}
  { RouterBox_schedule_table__io_dir_rInfo_right.values[0] = T146;}
  { RouterBox_route__io_routeInfo_rInfo_right.values[0] = RouterBox_schedule_table__io_dir_rInfo_right.values[0];}
  { T147.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_routeInfo_rInfo_right.values[0]);}
  val_t T148;
  { T148 = TERNARY_1(T115, RouterBox_route__din_up_valid.values[0], RouterBox_route__dout_right_valid.values[0]);}
  val_t T149;
  { T149 = TERNARY_1(T117, RouterBox_route__din_right_valid.values[0], T148);}
  val_t T150;
  { T150 = TERNARY_1(T119, RouterBox_route__din_down_valid.values[0], T149);}
  val_t T151;
  { T151 = TERNARY_1(T121, RouterBox_route__din_left_valid.values[0], T150);}
  val_t T152;
  { T152 = TERNARY_1(T123, RouterBox_route__din_local_valid.values[0], T151);}
  val_t T153;
  { T153 = TERNARY(T125, 0x0L, T152);}
  { T154.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T153);}
  val_t T155;
  T155 = 0x5L == RouterBox_route__directions_left.values[0];
  val_t T156;
  { T156 = TERNARY_1(T155, RouterBox_route__din_up_data.values[0], RouterBox_route__dout_left_data.values[0]);}
  val_t T157;
  T157 = 0x4L == RouterBox_route__directions_left.values[0];
  val_t T158;
  { T158 = TERNARY_1(T157, RouterBox_route__din_right_data.values[0], T156);}
  val_t T159;
  T159 = 0x2L == RouterBox_route__directions_left.values[0];
  val_t T160;
  { T160 = TERNARY_1(T159, RouterBox_route__din_down_data.values[0], T158);}
  val_t T161;
  T161 = 0x3L == RouterBox_route__directions_left.values[0];
  val_t T162;
  { T162 = TERNARY_1(T161, RouterBox_route__din_left_data.values[0], T160);}
  val_t T163;
  T163 = 0x1L == RouterBox_route__directions_left.values[0];
  val_t T164;
  { T164 = TERNARY_1(T163, RouterBox_route__din_local_data.values[0], T162);}
  val_t T165;
  T165 = 0x0L == RouterBox_route__directions_left.values[0];
  val_t T166;
  { T166 = TERNARY(T165, 0x0L, T164);}
  { T167.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T166);}
  val_t T168;
  { T168 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T169;
  { T169 = TERNARY(T20, 0x0L, T168);}
  val_t T170;
  { T170 = TERNARY(T25, 0x0L, T169);}
  val_t T171;
  { T171 = TERNARY(T30, 0x0L, T170);}
  val_t T172;
  { T172 = TERNARY(T35, 0x0L, T171);}
  val_t T173;
  { T173 = TERNARY(T40, 0x1L, T172);}
  val_t T174;
  { T174 = TERNARY(T45, 0x0L, T173);}
  val_t T175;
  { T175 = TERNARY(T50, 0x0L, T174);}
  val_t T176;
  { T176 = TERNARY(T55, 0x0L, T175);}
  val_t T177;
  { T177 = TERNARY(T60, 0x0L, T176);}
  val_t T178;
  { T178 = TERNARY(T65, 0x0L, T177);}
  val_t T179;
  { T179 = TERNARY(T70, 0x2L, T178);}
  val_t T180;
  { T180 = TERNARY(T75, 0x0L, T179);}
  val_t T181;
  { T181 = TERNARY(T80, 0x0L, T180);}
  val_t T182;
  { T182 = TERNARY(T85, 0x5L, T181);}
  val_t T183;
  { T183 = TERNARY(T90, 0x0L, T182);}
  val_t T184;
  { T184 = TERNARY(T95, 0x0L, T183);}
  val_t T185;
  { T185 = TERNARY(T100, 0x1L, T184);}
  val_t T186;
  { T186 = TERNARY(T105, 0x0L, T185);}
  { RouterBox_schedule_table__io_dir_rInfo_left.values[0] = T186;}
  { RouterBox_route__io_routeInfo_rInfo_left.values[0] = RouterBox_schedule_table__io_dir_rInfo_left.values[0];}
  { T187.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_routeInfo_rInfo_left.values[0]);}
  val_t T188;
  { T188 = TERNARY_1(T155, RouterBox_route__din_up_valid.values[0], RouterBox_route__dout_left_valid.values[0]);}
  val_t T189;
  { T189 = TERNARY_1(T157, RouterBox_route__din_right_valid.values[0], T188);}
  val_t T190;
  { T190 = TERNARY_1(T159, RouterBox_route__din_down_valid.values[0], T189);}
  val_t T191;
  { T191 = TERNARY_1(T161, RouterBox_route__din_left_valid.values[0], T190);}
  val_t T192;
  { T192 = TERNARY_1(T163, RouterBox_route__din_local_valid.values[0], T191);}
  val_t T193;
  { T193 = TERNARY(T165, 0x0L, T192);}
  { T194.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T193);}
  val_t T195;
  T195 = 0x5L == RouterBox_route__directions_up.values[0];
  val_t T196;
  { T196 = TERNARY_1(T195, RouterBox_route__din_up_data.values[0], RouterBox_route__dout_up_data.values[0]);}
  val_t T197;
  T197 = 0x4L == RouterBox_route__directions_up.values[0];
  val_t T198;
  { T198 = TERNARY_1(T197, RouterBox_route__din_right_data.values[0], T196);}
  val_t T199;
  T199 = 0x2L == RouterBox_route__directions_up.values[0];
  val_t T200;
  { T200 = TERNARY_1(T199, RouterBox_route__din_down_data.values[0], T198);}
  val_t T201;
  T201 = 0x3L == RouterBox_route__directions_up.values[0];
  val_t T202;
  { T202 = TERNARY_1(T201, RouterBox_route__din_left_data.values[0], T200);}
  val_t T203;
  T203 = 0x1L == RouterBox_route__directions_up.values[0];
  val_t T204;
  { T204 = TERNARY_1(T203, RouterBox_route__din_local_data.values[0], T202);}
  val_t T205;
  T205 = 0x0L == RouterBox_route__directions_up.values[0];
  val_t T206;
  { T206 = TERNARY(T205, 0x0L, T204);}
  { T207.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T206);}
  val_t T208;
  { T208 = TERNARY(T16, 0x1L, 0x0L);}
  val_t T209;
  { T209 = TERNARY(T20, 0x2L, T208);}
  val_t T210;
  { T210 = TERNARY(T25, 0x0L, T209);}
  val_t T211;
  { T211 = TERNARY(T30, 0x1L, T210);}
  val_t T212;
  { T212 = TERNARY(T35, 0x1L, T211);}
  val_t T213;
  { T213 = TERNARY(T40, 0x2L, T212);}
  val_t T214;
  { T214 = TERNARY(T45, 0x4L, T213);}
  val_t T215;
  { T215 = TERNARY(T50, 0x2L, T214);}
  val_t T216;
  { T216 = TERNARY(T55, 0x1L, T215);}
  val_t T217;
  { T217 = TERNARY(T60, 0x1L, T216);}
  val_t T218;
  { T218 = TERNARY(T65, 0x1L, T217);}
  val_t T219;
  { T219 = TERNARY(T70, 0x1L, T218);}
  val_t T220;
  { T220 = TERNARY(T75, 0x2L, T219);}
  val_t T221;
  { T221 = TERNARY(T80, 0x0L, T220);}
  val_t T222;
  { T222 = TERNARY(T85, 0x0L, T221);}
  val_t T223;
  { T223 = TERNARY(T90, 0x0L, T222);}
  val_t T224;
  { T224 = TERNARY(T95, 0x0L, T223);}
  val_t T225;
  { T225 = TERNARY(T100, 0x0L, T224);}
  val_t T226;
  { T226 = TERNARY(T105, 0x0L, T225);}
  { RouterBox_schedule_table__io_dir_rInfo_up.values[0] = T226;}
  { RouterBox_route__io_routeInfo_rInfo_up.values[0] = RouterBox_schedule_table__io_dir_rInfo_up.values[0];}
  { T227.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_routeInfo_rInfo_up.values[0]);}
  val_t T228;
  { T228 = TERNARY_1(T195, RouterBox_route__din_up_valid.values[0], RouterBox_route__dout_up_valid.values[0]);}
  val_t T229;
  { T229 = TERNARY_1(T197, RouterBox_route__din_right_valid.values[0], T228);}
  val_t T230;
  { T230 = TERNARY_1(T199, RouterBox_route__din_down_valid.values[0], T229);}
  val_t T231;
  { T231 = TERNARY_1(T201, RouterBox_route__din_left_valid.values[0], T230);}
  val_t T232;
  { T232 = TERNARY_1(T203, RouterBox_route__din_local_valid.values[0], T231);}
  val_t T233;
  { T233 = TERNARY(T205, 0x0L, T232);}
  { T234.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T233);}
  { RouterBox_route__io_lc_din_data.values[0] = RouterBox__io_lc_din_data.values[0];}
  { T235.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_lc_din_data.values[0]);}
  { RouterBox_route__io_le_din_data.values[0] = RouterBox__io_le_din_data.values[0];}
  { T236.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_le_din_data.values[0]);}
  { RouterBox_route__io_dn_din_data.values[0] = RouterBox__io_dn_din_data.values[0];}
  { T237.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_dn_din_data.values[0]);}
  { RouterBox_route__io_r_din_data.values[0] = RouterBox__io_r_din_data.values[0];}
  { T238.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_r_din_data.values[0]);}
  { RouterBox_route__io_up_din_data.values[0] = RouterBox__io_up_din_data.values[0];}
  { T239.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_up_din_data.values[0]);}
  val_t T240;
  T240 = 0x5L == RouterBox_route__directions_down.values[0];
  val_t T241;
  { T241 = TERNARY_1(T240, RouterBox_route__din_up_data.values[0], RouterBox_route__dout_down_data.values[0]);}
  val_t T242;
  T242 = 0x4L == RouterBox_route__directions_down.values[0];
  val_t T243;
  { T243 = TERNARY_1(T242, RouterBox_route__din_right_data.values[0], T241);}
  val_t T244;
  T244 = 0x2L == RouterBox_route__directions_down.values[0];
  val_t T245;
  { T245 = TERNARY_1(T244, RouterBox_route__din_down_data.values[0], T243);}
  val_t T246;
  T246 = 0x3L == RouterBox_route__directions_down.values[0];
  val_t T247;
  { T247 = TERNARY_1(T246, RouterBox_route__din_left_data.values[0], T245);}
  val_t T248;
  T248 = 0x1L == RouterBox_route__directions_down.values[0];
  val_t T249;
  { T249 = TERNARY_1(T248, RouterBox_route__din_local_data.values[0], T247);}
  val_t T250;
  T250 = 0x0L == RouterBox_route__directions_down.values[0];
  val_t T251;
  { T251 = TERNARY(T250, 0x0L, T249);}
  { T252.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T251);}
  { RouterBox_route__io_lc_din_valid.values[0] = RouterBox__io_lc_din_valid.values[0];}
  { T253.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_lc_din_valid.values[0]);}
  { RouterBox_route__io_le_din_valid.values[0] = RouterBox__io_le_din_valid.values[0];}
  { T254.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_le_din_valid.values[0]);}
  { RouterBox_route__io_dn_din_valid.values[0] = RouterBox__io_dn_din_valid.values[0];}
  { T255.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_dn_din_valid.values[0]);}
  { RouterBox_route__io_r_din_valid.values[0] = RouterBox__io_r_din_valid.values[0];}
  { T256.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_r_din_valid.values[0]);}
  val_t T257;
  { T257 = TERNARY(T16, 0x0L, 0x0L);}
  val_t T258;
  { T258 = TERNARY(T20, 0x0L, T257);}
  val_t T259;
  { T259 = TERNARY(T25, 0x3L, T258);}
  val_t T260;
  { T260 = TERNARY(T30, 0x0L, T259);}
  val_t T261;
  { T261 = TERNARY(T35, 0x0L, T260);}
  val_t T262;
  { T262 = TERNARY(T40, 0x0L, T261);}
  val_t T263;
  { T263 = TERNARY(T45, 0x0L, T262);}
  val_t T264;
  { T264 = TERNARY(T50, 0x0L, T263);}
  val_t T265;
  { T265 = TERNARY(T55, 0x0L, T264);}
  val_t T266;
  { T266 = TERNARY(T60, 0x3L, T265);}
  val_t T267;
  { T267 = TERNARY(T65, 0x0L, T266);}
  val_t T268;
  { T268 = TERNARY(T70, 0x0L, T267);}
  val_t T269;
  { T269 = TERNARY(T75, 0x0L, T268);}
  val_t T270;
  { T270 = TERNARY(T80, 0x1L, T269);}
  val_t T271;
  { T271 = TERNARY(T85, 0x0L, T270);}
  val_t T272;
  { T272 = TERNARY(T90, 0x0L, T271);}
  val_t T273;
  { T273 = TERNARY(T95, 0x1L, T272);}
  val_t T274;
  { T274 = TERNARY(T100, 0x0L, T273);}
  val_t T275;
  { T275 = TERNARY(T105, 0x0L, T274);}
  { RouterBox_schedule_table__io_dir_rInfo_down.values[0] = T275;}
  { RouterBox_route__io_routeInfo_rInfo_down.values[0] = RouterBox_schedule_table__io_dir_rInfo_down.values[0];}
  { T276.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_routeInfo_rInfo_down.values[0]);}
  { RouterBox_route__io_up_din_valid.values[0] = RouterBox__io_up_din_valid.values[0];}
  { T277.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, RouterBox_route__io_up_din_valid.values[0]);}
  val_t T278;
  { T278 = TERNARY_1(T240, RouterBox_route__din_up_valid.values[0], RouterBox_route__dout_down_valid.values[0]);}
  val_t T279;
  { T279 = TERNARY_1(T242, RouterBox_route__din_right_valid.values[0], T278);}
  val_t T280;
  { T280 = TERNARY_1(T244, RouterBox_route__din_down_valid.values[0], T279);}
  val_t T281;
  { T281 = TERNARY_1(T246, RouterBox_route__din_left_valid.values[0], T280);}
  val_t T282;
  { T282 = TERNARY_1(T248, RouterBox_route__din_local_valid.values[0], T281);}
  val_t T283;
  { T283 = TERNARY(T250, 0x0L, T282);}
  { T284.values[0] = TERNARY(RouterBox_route__reset.values[0], 0x0L, T283);}
  { RouterBox_route__io_lc_dout_data.values[0] = RouterBox_route__dout_local_data.values[0];}
  { RouterBox__io_lc_dout_data.values[0] = RouterBox_route__io_lc_dout_data.values[0];}
  { RouterBox_route__io_lc_dout_valid.values[0] = RouterBox_route__dout_local_valid.values[0];}
  { RouterBox__io_lc_dout_valid.values[0] = RouterBox_route__io_lc_dout_valid.values[0];}
  { RouterBox_route__io_r_dout_data.values[0] = RouterBox_route__dout_right_data.values[0];}
  { RouterBox__io_r_dout_data.values[0] = RouterBox_route__io_r_dout_data.values[0];}
  { RouterBox_route__io_r_dout_valid.values[0] = RouterBox_route__dout_right_valid.values[0];}
  { RouterBox__io_r_dout_valid.values[0] = RouterBox_route__io_r_dout_valid.values[0];}
  { RouterBox_route__io_le_dout_data.values[0] = RouterBox_route__dout_left_data.values[0];}
  { RouterBox__io_le_dout_data.values[0] = RouterBox_route__io_le_dout_data.values[0];}
  { RouterBox_route__io_le_dout_valid.values[0] = RouterBox_route__dout_left_valid.values[0];}
  { RouterBox__io_le_dout_valid.values[0] = RouterBox_route__io_le_dout_valid.values[0];}
  { RouterBox_route__io_up_dout_data.values[0] = RouterBox_route__dout_up_data.values[0];}
  { RouterBox__io_up_dout_data.values[0] = RouterBox_route__io_up_dout_data.values[0];}
  { RouterBox_route__io_up_dout_valid.values[0] = RouterBox_route__dout_up_valid.values[0];}
  { RouterBox__io_up_dout_valid.values[0] = RouterBox_route__io_up_dout_valid.values[0];}
  { RouterBox_route__io_dn_dout_data.values[0] = RouterBox_route__dout_down_data.values[0];}
  { RouterBox__io_dn_dout_data.values[0] = RouterBox_route__io_dn_dout_data.values[0];}
  { RouterBox_route__io_dn_dout_valid.values[0] = RouterBox_route__dout_down_valid.values[0];}
  { RouterBox__io_dn_dout_valid.values[0] = RouterBox_route__io_dn_dout_valid.values[0];}
}


void RouterBox_t::clock_hi ( dat_t<1> reset ) {
  dat_t<19> RouterBox_route__reg_slotCount__shadow = T1;
  dat_t<32> RouterBox_route__dout_local_data__shadow = T14;
  dat_t<3> RouterBox_route__directions_local__shadow = T107;
  dat_t<1> RouterBox_route__dout_local_valid__shadow = T114;
  dat_t<32> RouterBox_route__dout_right_data__shadow = T127;
  dat_t<3> RouterBox_route__directions_right__shadow = T147;
  dat_t<1> RouterBox_route__dout_right_valid__shadow = T154;
  dat_t<32> RouterBox_route__dout_left_data__shadow = T167;
  dat_t<3> RouterBox_route__directions_left__shadow = T187;
  dat_t<1> RouterBox_route__dout_left_valid__shadow = T194;
  dat_t<32> RouterBox_route__dout_up_data__shadow = T207;
  dat_t<3> RouterBox_route__directions_up__shadow = T227;
  dat_t<1> RouterBox_route__dout_up_valid__shadow = T234;
  dat_t<32> RouterBox_route__din_local_data__shadow = T235;
  dat_t<32> RouterBox_route__din_left_data__shadow = T236;
  dat_t<32> RouterBox_route__din_down_data__shadow = T237;
  dat_t<32> RouterBox_route__din_right_data__shadow = T238;
  dat_t<32> RouterBox_route__din_up_data__shadow = T239;
  dat_t<32> RouterBox_route__dout_down_data__shadow = T252;
  dat_t<1> RouterBox_route__din_local_valid__shadow = T253;
  dat_t<1> RouterBox_route__din_left_valid__shadow = T254;
  dat_t<1> RouterBox_route__din_down_valid__shadow = T255;
  dat_t<1> RouterBox_route__din_right_valid__shadow = T256;
  dat_t<3> RouterBox_route__directions_down__shadow = T276;
  dat_t<1> RouterBox_route__din_up_valid__shadow = T277;
  dat_t<1> RouterBox_route__dout_down_valid__shadow = T284;
  RouterBox_route__reg_slotCount = T1;
  RouterBox_route__dout_local_data = T14;
  RouterBox_route__directions_local = T107;
  RouterBox_route__dout_local_valid = T114;
  RouterBox_route__dout_right_data = T127;
  RouterBox_route__directions_right = T147;
  RouterBox_route__dout_right_valid = T154;
  RouterBox_route__dout_left_data = T167;
  RouterBox_route__directions_left = T187;
  RouterBox_route__dout_left_valid = T194;
  RouterBox_route__dout_up_data = T207;
  RouterBox_route__directions_up = T227;
  RouterBox_route__dout_up_valid = T234;
  RouterBox_route__din_local_data = T235;
  RouterBox_route__din_left_data = T236;
  RouterBox_route__din_down_data = T237;
  RouterBox_route__din_right_data = T238;
  RouterBox_route__din_up_data = T239;
  RouterBox_route__dout_down_data = T252;
  RouterBox_route__din_local_valid = T253;
  RouterBox_route__din_left_valid = T254;
  RouterBox_route__din_down_valid = T255;
  RouterBox_route__din_right_valid = T256;
  RouterBox_route__directions_down = T276;
  RouterBox_route__din_up_valid = T277;
  RouterBox_route__dout_down_valid = T284;
}


void RouterBox_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  RouterBox_t* mod = dynamic_cast<RouterBox_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<32>(&mod->RouterBox__io_lc_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->RouterBox__io_lc_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->RouterBox__io_r_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->RouterBox__io_r_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->RouterBox__io_le_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->RouterBox__io_le_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->RouterBox__io_up_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->RouterBox__io_up_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->RouterBox__io_dn_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->RouterBox__io_dn_din_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->RouterBox__io_lc_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->RouterBox__io_lc_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->RouterBox__io_r_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->RouterBox__io_r_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->RouterBox__io_le_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->RouterBox__io_le_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->RouterBox__io_up_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->RouterBox__io_up_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->RouterBox__io_dn_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->RouterBox__io_dn_dout_valid));
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__reset));
  sim_data.signal_map["RouterBox.route.reset"] = 0;
  sim_data.signals.push_back(new dat_api<19>(&mod->RouterBox_route__reg_slotCount));
  sim_data.signal_map["RouterBox.route.reg_slotCount"] = 1;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__dout_local_data));
  sim_data.signal_map["RouterBox.route.dout_local_data"] = 2;
  sim_data.signals.push_back(new dat_api<16>(&mod->RouterBox_route__io_routeInfo_slotCounter));
  sim_data.signal_map["RouterBox.route.io_routeInfo_slotCounter"] = 3;
  sim_data.signals.push_back(new dat_api<16>(&mod->RouterBox_schedule_table__io_dir_slotCounter));
  sim_data.signal_map["RouterBox.schedule_table.io_dir_slotCounter"] = 4;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_schedule_table__io_dir_rInfo_local));
  sim_data.signal_map["RouterBox.schedule_table.io_dir_rInfo_local"] = 5;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__io_routeInfo_rInfo_local));
  sim_data.signal_map["RouterBox.route.io_routeInfo_rInfo_local"] = 6;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__directions_local));
  sim_data.signal_map["RouterBox.route.directions_local"] = 7;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__dout_local_valid));
  sim_data.signal_map["RouterBox.route.dout_local_valid"] = 8;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__dout_right_data));
  sim_data.signal_map["RouterBox.route.dout_right_data"] = 9;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_schedule_table__io_dir_rInfo_right));
  sim_data.signal_map["RouterBox.schedule_table.io_dir_rInfo_right"] = 10;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__io_routeInfo_rInfo_right));
  sim_data.signal_map["RouterBox.route.io_routeInfo_rInfo_right"] = 11;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__directions_right));
  sim_data.signal_map["RouterBox.route.directions_right"] = 12;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__dout_right_valid));
  sim_data.signal_map["RouterBox.route.dout_right_valid"] = 13;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__dout_left_data));
  sim_data.signal_map["RouterBox.route.dout_left_data"] = 14;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_schedule_table__io_dir_rInfo_left));
  sim_data.signal_map["RouterBox.schedule_table.io_dir_rInfo_left"] = 15;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__io_routeInfo_rInfo_left));
  sim_data.signal_map["RouterBox.route.io_routeInfo_rInfo_left"] = 16;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__directions_left));
  sim_data.signal_map["RouterBox.route.directions_left"] = 17;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__dout_left_valid));
  sim_data.signal_map["RouterBox.route.dout_left_valid"] = 18;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__dout_up_data));
  sim_data.signal_map["RouterBox.route.dout_up_data"] = 19;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_schedule_table__io_dir_rInfo_up));
  sim_data.signal_map["RouterBox.schedule_table.io_dir_rInfo_up"] = 20;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__io_routeInfo_rInfo_up));
  sim_data.signal_map["RouterBox.route.io_routeInfo_rInfo_up"] = 21;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__directions_up));
  sim_data.signal_map["RouterBox.route.directions_up"] = 22;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__dout_up_valid));
  sim_data.signal_map["RouterBox.route.dout_up_valid"] = 23;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_lc_din_data));
  sim_data.signal_map["RouterBox.route.io_lc_din_data"] = 24;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__din_local_data));
  sim_data.signal_map["RouterBox.route.din_local_data"] = 25;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_le_din_data));
  sim_data.signal_map["RouterBox.route.io_le_din_data"] = 26;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__din_left_data));
  sim_data.signal_map["RouterBox.route.din_left_data"] = 27;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_dn_din_data));
  sim_data.signal_map["RouterBox.route.io_dn_din_data"] = 28;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__din_down_data));
  sim_data.signal_map["RouterBox.route.din_down_data"] = 29;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_r_din_data));
  sim_data.signal_map["RouterBox.route.io_r_din_data"] = 30;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__din_right_data));
  sim_data.signal_map["RouterBox.route.din_right_data"] = 31;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_up_din_data));
  sim_data.signal_map["RouterBox.route.io_up_din_data"] = 32;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__din_up_data));
  sim_data.signal_map["RouterBox.route.din_up_data"] = 33;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__dout_down_data));
  sim_data.signal_map["RouterBox.route.dout_down_data"] = 34;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_lc_din_valid));
  sim_data.signal_map["RouterBox.route.io_lc_din_valid"] = 35;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__din_local_valid));
  sim_data.signal_map["RouterBox.route.din_local_valid"] = 36;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_le_din_valid));
  sim_data.signal_map["RouterBox.route.io_le_din_valid"] = 37;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__din_left_valid));
  sim_data.signal_map["RouterBox.route.din_left_valid"] = 38;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_dn_din_valid));
  sim_data.signal_map["RouterBox.route.io_dn_din_valid"] = 39;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__din_down_valid));
  sim_data.signal_map["RouterBox.route.din_down_valid"] = 40;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_r_din_valid));
  sim_data.signal_map["RouterBox.route.io_r_din_valid"] = 41;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__din_right_valid));
  sim_data.signal_map["RouterBox.route.din_right_valid"] = 42;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_schedule_table__io_dir_rInfo_down));
  sim_data.signal_map["RouterBox.schedule_table.io_dir_rInfo_down"] = 43;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__io_routeInfo_rInfo_down));
  sim_data.signal_map["RouterBox.route.io_routeInfo_rInfo_down"] = 44;
  sim_data.signals.push_back(new dat_api<3>(&mod->RouterBox_route__directions_down));
  sim_data.signal_map["RouterBox.route.directions_down"] = 45;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_up_din_valid));
  sim_data.signal_map["RouterBox.route.io_up_din_valid"] = 46;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__din_up_valid));
  sim_data.signal_map["RouterBox.route.din_up_valid"] = 47;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__dout_down_valid));
  sim_data.signal_map["RouterBox.route.dout_down_valid"] = 48;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_lc_dout_data));
  sim_data.signal_map["RouterBox.route.io_lc_dout_data"] = 49;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_lc_dout_valid));
  sim_data.signal_map["RouterBox.route.io_lc_dout_valid"] = 50;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_r_dout_data));
  sim_data.signal_map["RouterBox.route.io_r_dout_data"] = 51;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_r_dout_valid));
  sim_data.signal_map["RouterBox.route.io_r_dout_valid"] = 52;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_le_dout_data));
  sim_data.signal_map["RouterBox.route.io_le_dout_data"] = 53;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_le_dout_valid));
  sim_data.signal_map["RouterBox.route.io_le_dout_valid"] = 54;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_up_dout_data));
  sim_data.signal_map["RouterBox.route.io_up_dout_data"] = 55;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_up_dout_valid));
  sim_data.signal_map["RouterBox.route.io_up_dout_valid"] = 56;
  sim_data.signals.push_back(new dat_api<32>(&mod->RouterBox_route__io_dn_dout_data));
  sim_data.signal_map["RouterBox.route.io_dn_dout_data"] = 57;
  sim_data.signals.push_back(new dat_api<1>(&mod->RouterBox_route__io_dn_dout_valid));
  sim_data.signal_map["RouterBox.route.io_dn_dout_valid"] = 58;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
