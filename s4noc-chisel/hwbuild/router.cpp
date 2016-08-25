#include "router.h"

void router_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  router__reg_slotCount.randomize(&__rand_seed);
  router__directions_up.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int router_t::clock ( dat_t<1> reset ) {
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


void router_t::print ( FILE* f ) {
}
void router_t::print ( std::ostream& s ) {
}


void router_t::dump_init ( FILE* f ) {
  fputs("$timescale 1ps $end\n", f);
  fputs("$scope module router $end\n", f);
  fputs("$var wire 1 \x21 clk $end\n", f);
  fputs("$var wire 1 \x22 reset $end\n", f);
  fputs("$var wire 1 \x23 io_lc_dout_valid $end\n", f);
  fputs("$var wire 1 \x24 io_ready $end\n", f);
  fputs("$var wire 1 \x25 io_r_dout_valid $end\n", f);
  fputs("$var wire 1 \x26 io_le_dout_valid $end\n", f);
  fputs("$var wire 1 \x27 io_up_dout_valid $end\n", f);
  fputs("$var wire 1 \x28 io_dn_dout_valid $end\n", f);
  fputs("$var wire 1 \x29 io_dn_din_valid $end\n", f);
  fputs("$var wire 1 \x2a io_up_din_valid $end\n", f);
  fputs("$var wire 1 \x2b io_le_din_valid $end\n", f);
  fputs("$var wire 1 \x2c io_r_din_valid $end\n", f);
  fputs("$var wire 1 \x2d io_qFull $end\n", f);
  fputs("$var wire 1 \x2e io_lc_din_valid $end\n", f);
  fputs("$var wire 1 \x2f io_ena $end\n", f);
  fputs("$var wire 3 \x30 io_routeInfo_rInfo_up $end\n", f);
  fputs("$var wire 3 \x31 directions_up $end\n", f);
  fputs("$var wire 3 \x32 io_routeInfo_rInfo_dc $end\n", f);
  fputs("$var wire 3 \x33 io_routeInfo_rInfo_local $end\n", f);
  fputs("$var wire 3 \x34 io_routeInfo_rInfo_left $end\n", f);
  fputs("$var wire 3 \x35 io_routeInfo_rInfo_down $end\n", f);
  fputs("$var wire 3 \x36 io_routeInfo_rInfo_right $end\n", f);
  fputs("$var wire 16 \x37 io_routeInfo_slotCounter $end\n", f);
  fputs("$var wire 19 \x38 reg_slotCount $end\n", f);
  fputs("$var wire 32 \x39 io_lc_dout_data $end\n", f);
  fputs("$var wire 32 \x3a io_test $end\n", f);
  fputs("$var wire 32 \x3b io_r_dout_data $end\n", f);
  fputs("$var wire 32 \x3c io_le_dout_data $end\n", f);
  fputs("$var wire 32 \x3d io_up_dout_data $end\n", f);
  fputs("$var wire 32 \x3e io_dn_dout_data $end\n", f);
  fputs("$var wire 32 \x3f io_dn_din_data $end\n", f);
  fputs("$var wire 32 \x40 io_up_din_data $end\n", f);
  fputs("$var wire 32 \x41 io_le_din_data $end\n", f);
  fputs("$var wire 32 \x42 io_r_din_data $end\n", f);
  fputs("$var wire 32 \x43 io_addr $end\n", f);
  fputs("$var wire 32 \x44 io_lc_din_data $end\n", f);
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
  dat_dump<1>(f, router__io_lc_dout_valid, 0x23);
  router__io_lc_dout_valid__prev = router__io_lc_dout_valid;
  dat_dump<1>(f, router__io_ready, 0x24);
  router__io_ready__prev = router__io_ready;
  dat_dump<1>(f, router__io_r_dout_valid, 0x25);
  router__io_r_dout_valid__prev = router__io_r_dout_valid;
  dat_dump<1>(f, router__io_le_dout_valid, 0x26);
  router__io_le_dout_valid__prev = router__io_le_dout_valid;
  dat_dump<1>(f, router__io_up_dout_valid, 0x27);
  router__io_up_dout_valid__prev = router__io_up_dout_valid;
  dat_dump<1>(f, router__io_dn_dout_valid, 0x28);
  router__io_dn_dout_valid__prev = router__io_dn_dout_valid;
  dat_dump<1>(f, router__io_dn_din_valid, 0x29);
  router__io_dn_din_valid__prev = router__io_dn_din_valid;
  dat_dump<1>(f, router__io_up_din_valid, 0x2a);
  router__io_up_din_valid__prev = router__io_up_din_valid;
  dat_dump<1>(f, router__io_le_din_valid, 0x2b);
  router__io_le_din_valid__prev = router__io_le_din_valid;
  dat_dump<1>(f, router__io_r_din_valid, 0x2c);
  router__io_r_din_valid__prev = router__io_r_din_valid;
  dat_dump<1>(f, router__io_qFull, 0x2d);
  router__io_qFull__prev = router__io_qFull;
  dat_dump<1>(f, router__io_lc_din_valid, 0x2e);
  router__io_lc_din_valid__prev = router__io_lc_din_valid;
  dat_dump<1>(f, router__io_ena, 0x2f);
  router__io_ena__prev = router__io_ena;
  dat_dump<1>(f, router__io_routeInfo_rInfo_up, 0x30);
  router__io_routeInfo_rInfo_up__prev = router__io_routeInfo_rInfo_up;
  dat_dump<1>(f, router__directions_up, 0x31);
  router__directions_up__prev = router__directions_up;
  dat_dump<1>(f, router__io_routeInfo_rInfo_dc, 0x32);
  router__io_routeInfo_rInfo_dc__prev = router__io_routeInfo_rInfo_dc;
  dat_dump<1>(f, router__io_routeInfo_rInfo_local, 0x33);
  router__io_routeInfo_rInfo_local__prev = router__io_routeInfo_rInfo_local;
  dat_dump<1>(f, router__io_routeInfo_rInfo_left, 0x34);
  router__io_routeInfo_rInfo_left__prev = router__io_routeInfo_rInfo_left;
  dat_dump<1>(f, router__io_routeInfo_rInfo_down, 0x35);
  router__io_routeInfo_rInfo_down__prev = router__io_routeInfo_rInfo_down;
  dat_dump<1>(f, router__io_routeInfo_rInfo_right, 0x36);
  router__io_routeInfo_rInfo_right__prev = router__io_routeInfo_rInfo_right;
  dat_dump<1>(f, router__io_routeInfo_slotCounter, 0x37);
  router__io_routeInfo_slotCounter__prev = router__io_routeInfo_slotCounter;
  dat_dump<1>(f, router__reg_slotCount, 0x38);
  router__reg_slotCount__prev = router__reg_slotCount;
  dat_dump<1>(f, router__io_lc_dout_data, 0x39);
  router__io_lc_dout_data__prev = router__io_lc_dout_data;
  dat_dump<1>(f, router__io_test, 0x3a);
  router__io_test__prev = router__io_test;
  dat_dump<1>(f, router__io_r_dout_data, 0x3b);
  router__io_r_dout_data__prev = router__io_r_dout_data;
  dat_dump<1>(f, router__io_le_dout_data, 0x3c);
  router__io_le_dout_data__prev = router__io_le_dout_data;
  dat_dump<1>(f, router__io_up_dout_data, 0x3d);
  router__io_up_dout_data__prev = router__io_up_dout_data;
  dat_dump<1>(f, router__io_dn_dout_data, 0x3e);
  router__io_dn_dout_data__prev = router__io_dn_dout_data;
  dat_dump<1>(f, router__io_dn_din_data, 0x3f);
  router__io_dn_din_data__prev = router__io_dn_din_data;
  dat_dump<1>(f, router__io_up_din_data, 0x40);
  router__io_up_din_data__prev = router__io_up_din_data;
  dat_dump<1>(f, router__io_le_din_data, 0x41);
  router__io_le_din_data__prev = router__io_le_din_data;
  dat_dump<1>(f, router__io_r_din_data, 0x42);
  router__io_r_din_data__prev = router__io_r_din_data;
  dat_dump<1>(f, router__io_addr, 0x43);
  router__io_addr__prev = router__io_addr;
  dat_dump<1>(f, router__io_lc_din_data, 0x44);
  router__io_lc_din_data__prev = router__io_lc_din_data;
  fputs("#1\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 0;
    dat_dump<1>(f, clk, 0x21);
  }
}


void router_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
  if (t == 0L) return dump_init(f);
  fprintf(f, "#%lu\n", t << 1);
  if (clk.cnt == 0)  goto L0;
K0:  if (reset != reset__prev)  goto L1;
K1:  if (router__io_lc_dout_valid != router__io_lc_dout_valid__prev)  goto L2;
K2:  if (router__io_ready != router__io_ready__prev)  goto L3;
K3:  if (router__io_r_dout_valid != router__io_r_dout_valid__prev)  goto L4;
K4:  if (router__io_le_dout_valid != router__io_le_dout_valid__prev)  goto L5;
K5:  if (router__io_up_dout_valid != router__io_up_dout_valid__prev)  goto L6;
K6:  if (router__io_dn_dout_valid != router__io_dn_dout_valid__prev)  goto L7;
K7:  if (router__io_dn_din_valid != router__io_dn_din_valid__prev)  goto L8;
K8:  if (router__io_up_din_valid != router__io_up_din_valid__prev)  goto L9;
K9:  if (router__io_le_din_valid != router__io_le_din_valid__prev)  goto L10;
K10:  if (router__io_r_din_valid != router__io_r_din_valid__prev)  goto L11;
K11:  if (router__io_qFull != router__io_qFull__prev)  goto L12;
K12:  if (router__io_lc_din_valid != router__io_lc_din_valid__prev)  goto L13;
K13:  if (router__io_ena != router__io_ena__prev)  goto L14;
K14:  if (router__io_routeInfo_rInfo_up != router__io_routeInfo_rInfo_up__prev)  goto L15;
K15:  if (router__directions_up != router__directions_up__prev)  goto L16;
K16:  if (router__io_routeInfo_rInfo_dc != router__io_routeInfo_rInfo_dc__prev)  goto L17;
K17:  if (router__io_routeInfo_rInfo_local != router__io_routeInfo_rInfo_local__prev)  goto L18;
K18:  if (router__io_routeInfo_rInfo_left != router__io_routeInfo_rInfo_left__prev)  goto L19;
K19:  if (router__io_routeInfo_rInfo_down != router__io_routeInfo_rInfo_down__prev)  goto L20;
K20:  if (router__io_routeInfo_rInfo_right != router__io_routeInfo_rInfo_right__prev)  goto L21;
K21:  if (router__io_routeInfo_slotCounter != router__io_routeInfo_slotCounter__prev)  goto L22;
K22:  if (router__reg_slotCount != router__reg_slotCount__prev)  goto L23;
K23:  if (router__io_lc_dout_data != router__io_lc_dout_data__prev)  goto L24;
K24:  if (router__io_test != router__io_test__prev)  goto L25;
K25:  if (router__io_r_dout_data != router__io_r_dout_data__prev)  goto L26;
K26:  if (router__io_le_dout_data != router__io_le_dout_data__prev)  goto L27;
K27:  if (router__io_up_dout_data != router__io_up_dout_data__prev)  goto L28;
K28:  if (router__io_dn_dout_data != router__io_dn_dout_data__prev)  goto L29;
K29:  if (router__io_dn_din_data != router__io_dn_din_data__prev)  goto L30;
K30:  if (router__io_up_din_data != router__io_up_din_data__prev)  goto L31;
K31:  if (router__io_le_din_data != router__io_le_din_data__prev)  goto L32;
K32:  if (router__io_r_din_data != router__io_r_din_data__prev)  goto L33;
K33:  if (router__io_addr != router__io_addr__prev)  goto L34;
K34:  if (router__io_lc_din_data != router__io_lc_din_data__prev)  goto L35;
K35:  fprintf(f, "#%lu\n", (t << 1) + 1);
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
  router__io_lc_dout_valid__prev = router__io_lc_dout_valid;
  dat_dump<1>(f, router__io_lc_dout_valid, 0x23);
  goto K2;
L3:
  router__io_ready__prev = router__io_ready;
  dat_dump<1>(f, router__io_ready, 0x24);
  goto K3;
L4:
  router__io_r_dout_valid__prev = router__io_r_dout_valid;
  dat_dump<1>(f, router__io_r_dout_valid, 0x25);
  goto K4;
L5:
  router__io_le_dout_valid__prev = router__io_le_dout_valid;
  dat_dump<1>(f, router__io_le_dout_valid, 0x26);
  goto K5;
L6:
  router__io_up_dout_valid__prev = router__io_up_dout_valid;
  dat_dump<1>(f, router__io_up_dout_valid, 0x27);
  goto K6;
L7:
  router__io_dn_dout_valid__prev = router__io_dn_dout_valid;
  dat_dump<1>(f, router__io_dn_dout_valid, 0x28);
  goto K7;
L8:
  router__io_dn_din_valid__prev = router__io_dn_din_valid;
  dat_dump<1>(f, router__io_dn_din_valid, 0x29);
  goto K8;
L9:
  router__io_up_din_valid__prev = router__io_up_din_valid;
  dat_dump<1>(f, router__io_up_din_valid, 0x2a);
  goto K9;
L10:
  router__io_le_din_valid__prev = router__io_le_din_valid;
  dat_dump<1>(f, router__io_le_din_valid, 0x2b);
  goto K10;
L11:
  router__io_r_din_valid__prev = router__io_r_din_valid;
  dat_dump<1>(f, router__io_r_din_valid, 0x2c);
  goto K11;
L12:
  router__io_qFull__prev = router__io_qFull;
  dat_dump<1>(f, router__io_qFull, 0x2d);
  goto K12;
L13:
  router__io_lc_din_valid__prev = router__io_lc_din_valid;
  dat_dump<1>(f, router__io_lc_din_valid, 0x2e);
  goto K13;
L14:
  router__io_ena__prev = router__io_ena;
  dat_dump<1>(f, router__io_ena, 0x2f);
  goto K14;
L15:
  router__io_routeInfo_rInfo_up__prev = router__io_routeInfo_rInfo_up;
  dat_dump<1>(f, router__io_routeInfo_rInfo_up, 0x30);
  goto K15;
L16:
  router__directions_up__prev = router__directions_up;
  dat_dump<1>(f, router__directions_up, 0x31);
  goto K16;
L17:
  router__io_routeInfo_rInfo_dc__prev = router__io_routeInfo_rInfo_dc;
  dat_dump<1>(f, router__io_routeInfo_rInfo_dc, 0x32);
  goto K17;
L18:
  router__io_routeInfo_rInfo_local__prev = router__io_routeInfo_rInfo_local;
  dat_dump<1>(f, router__io_routeInfo_rInfo_local, 0x33);
  goto K18;
L19:
  router__io_routeInfo_rInfo_left__prev = router__io_routeInfo_rInfo_left;
  dat_dump<1>(f, router__io_routeInfo_rInfo_left, 0x34);
  goto K19;
L20:
  router__io_routeInfo_rInfo_down__prev = router__io_routeInfo_rInfo_down;
  dat_dump<1>(f, router__io_routeInfo_rInfo_down, 0x35);
  goto K20;
L21:
  router__io_routeInfo_rInfo_right__prev = router__io_routeInfo_rInfo_right;
  dat_dump<1>(f, router__io_routeInfo_rInfo_right, 0x36);
  goto K21;
L22:
  router__io_routeInfo_slotCounter__prev = router__io_routeInfo_slotCounter;
  dat_dump<1>(f, router__io_routeInfo_slotCounter, 0x37);
  goto K22;
L23:
  router__reg_slotCount__prev = router__reg_slotCount;
  dat_dump<1>(f, router__reg_slotCount, 0x38);
  goto K23;
L24:
  router__io_lc_dout_data__prev = router__io_lc_dout_data;
  dat_dump<1>(f, router__io_lc_dout_data, 0x39);
  goto K24;
L25:
  router__io_test__prev = router__io_test;
  dat_dump<1>(f, router__io_test, 0x3a);
  goto K25;
L26:
  router__io_r_dout_data__prev = router__io_r_dout_data;
  dat_dump<1>(f, router__io_r_dout_data, 0x3b);
  goto K26;
L27:
  router__io_le_dout_data__prev = router__io_le_dout_data;
  dat_dump<1>(f, router__io_le_dout_data, 0x3c);
  goto K27;
L28:
  router__io_up_dout_data__prev = router__io_up_dout_data;
  dat_dump<1>(f, router__io_up_dout_data, 0x3d);
  goto K28;
L29:
  router__io_dn_dout_data__prev = router__io_dn_dout_data;
  dat_dump<1>(f, router__io_dn_dout_data, 0x3e);
  goto K29;
L30:
  router__io_dn_din_data__prev = router__io_dn_din_data;
  dat_dump<1>(f, router__io_dn_din_data, 0x3f);
  goto K30;
L31:
  router__io_up_din_data__prev = router__io_up_din_data;
  dat_dump<1>(f, router__io_up_din_data, 0x40);
  goto K31;
L32:
  router__io_le_din_data__prev = router__io_le_din_data;
  dat_dump<1>(f, router__io_le_din_data, 0x41);
  goto K32;
L33:
  router__io_r_din_data__prev = router__io_r_din_data;
  dat_dump<1>(f, router__io_r_din_data, 0x42);
  goto K33;
L34:
  router__io_addr__prev = router__io_addr;
  dat_dump<1>(f, router__io_addr, 0x43);
  goto K34;
L35:
  router__io_lc_din_data__prev = router__io_lc_din_data;
  dat_dump<1>(f, router__io_lc_din_data, 0x44);
  goto K35;
Z0:
  clk.values[0] = 0;
  dat_dump<1>(f, clk, 0x21);
  goto C0;
}




void router_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  val_t T0;
  { T0 = router__reg_slotCount.values[0]+0x1L;}
  T0 = T0 & 0x7ffffL;
  { T1.values[0] = TERNARY(reset.values[0], 0x0L, T0);}
  val_t T2;
  { T2 = router__reg_slotCount.values[0];}
  T2 = T2 & 0xffffL;
  { router__io_routeInfo_slotCounter.values[0] = T2;}
  { val_t __r = this->__rand_val(); router__io_lc_dout_data.values[0] = __r;}
  router__io_lc_dout_data.values[0] = router__io_lc_dout_data.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); router__io_lc_dout_valid.values[0] = __r;}
  router__io_lc_dout_valid.values[0] = router__io_lc_dout_valid.values[0] & 0x1L;
  { T3.values[0] = TERNARY(reset.values[0], 0x0L, router__io_routeInfo_rInfo_up.values[0]);}
  val_t T4;
  T4 = router__directions_up.values[0] == 0x1L;
  val_t T5;
  { T5 = T4 | 0x0L << 1;}
  { router__io_test.values[0] = T5;}
  { val_t __r = this->__rand_val(); router__io_ready.values[0] = __r;}
  router__io_ready.values[0] = router__io_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); router__io_r_dout_data.values[0] = __r;}
  router__io_r_dout_data.values[0] = router__io_r_dout_data.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); router__io_r_dout_valid.values[0] = __r;}
  router__io_r_dout_valid.values[0] = router__io_r_dout_valid.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); router__io_le_dout_data.values[0] = __r;}
  router__io_le_dout_data.values[0] = router__io_le_dout_data.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); router__io_le_dout_valid.values[0] = __r;}
  router__io_le_dout_valid.values[0] = router__io_le_dout_valid.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); router__io_up_dout_data.values[0] = __r;}
  router__io_up_dout_data.values[0] = router__io_up_dout_data.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); router__io_up_dout_valid.values[0] = __r;}
  router__io_up_dout_valid.values[0] = router__io_up_dout_valid.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); router__io_dn_dout_data.values[0] = __r;}
  router__io_dn_dout_data.values[0] = router__io_dn_dout_data.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); router__io_dn_dout_valid.values[0] = __r;}
  router__io_dn_dout_valid.values[0] = router__io_dn_dout_valid.values[0] & 0x1L;
}


void router_t::clock_hi ( dat_t<1> reset ) {
  dat_t<19> router__reg_slotCount__shadow = T1;
  dat_t<3> router__directions_up__shadow = T3;
  router__reg_slotCount = T1;
  router__directions_up = T3;
}


void router_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  router_t* mod = dynamic_cast<router_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<1>(&mod->router__io_ena));
  sim_data.inputs.push_back(new dat_api<3>(&mod->router__io_routeInfo_rInfo_up));
  sim_data.inputs.push_back(new dat_api<3>(&mod->router__io_routeInfo_rInfo_right));
  sim_data.inputs.push_back(new dat_api<3>(&mod->router__io_routeInfo_rInfo_down));
  sim_data.inputs.push_back(new dat_api<3>(&mod->router__io_routeInfo_rInfo_left));
  sim_data.inputs.push_back(new dat_api<3>(&mod->router__io_routeInfo_rInfo_local));
  sim_data.inputs.push_back(new dat_api<3>(&mod->router__io_routeInfo_rInfo_dc));
  sim_data.inputs.push_back(new dat_api<32>(&mod->router__io_lc_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->router__io_lc_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->router__io_addr));
  sim_data.inputs.push_back(new dat_api<1>(&mod->router__io_qFull));
  sim_data.inputs.push_back(new dat_api<32>(&mod->router__io_r_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->router__io_r_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->router__io_le_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->router__io_le_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->router__io_up_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->router__io_up_din_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->router__io_dn_din_data));
  sim_data.inputs.push_back(new dat_api<1>(&mod->router__io_dn_din_valid));
  sim_data.outputs.push_back(new dat_api<16>(&mod->router__io_routeInfo_slotCounter));
  sim_data.outputs.push_back(new dat_api<32>(&mod->router__io_lc_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->router__io_lc_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->router__io_test));
  sim_data.outputs.push_back(new dat_api<1>(&mod->router__io_ready));
  sim_data.outputs.push_back(new dat_api<32>(&mod->router__io_r_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->router__io_r_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->router__io_le_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->router__io_le_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->router__io_up_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->router__io_up_dout_valid));
  sim_data.outputs.push_back(new dat_api<32>(&mod->router__io_dn_dout_data));
  sim_data.outputs.push_back(new dat_api<1>(&mod->router__io_dn_dout_valid));
  sim_data.signals.push_back(new dat_api<19>(&mod->router__reg_slotCount));
  sim_data.signal_map["router.reg_slotCount"] = 0;
  sim_data.signals.push_back(new dat_api<3>(&mod->router__directions_up));
  sim_data.signal_map["router.directions_up"] = 1;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
