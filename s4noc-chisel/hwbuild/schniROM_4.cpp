#include "schniROM_4.h"

void schniROM_4_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  schniROM_4__rdAddrReg.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int schniROM_4_t::clock ( dat_t<1> reset ) {
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


void schniROM_4_t::print ( FILE* f ) {
}
void schniROM_4_t::print ( std::ostream& s ) {
}


void schniROM_4_t::dump_init ( FILE* f ) {
  fputs("$timescale 1ps $end\n", f);
  fputs("$scope module schniROM_4 $end\n", f);
  fputs("$var wire 1 \x21 clk $end\n", f);
  fputs("$var wire 1 \x22 reset $end\n", f);
  fputs("$var wire 1 \x23 io_dir_read $end\n", f);
  fputs("$var wire 4 \x24 io_dir_rdData_src $end\n", f);
  fputs("$var wire 4 \x25 io_dir_rdData_dst $end\n", f);
  fputs("$var wire 20 \x26 io_dir_rdAddr $end\n", f);
  fputs("$var wire 20 \x27 rdAddrReg $end\n", f);
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
  dat_dump<1>(f, schniROM_4__io_dir_read, 0x23);
  schniROM_4__io_dir_read__prev = schniROM_4__io_dir_read;
  dat_dump<1>(f, schniROM_4__io_dir_rdData_src, 0x24);
  schniROM_4__io_dir_rdData_src__prev = schniROM_4__io_dir_rdData_src;
  dat_dump<1>(f, schniROM_4__io_dir_rdData_dst, 0x25);
  schniROM_4__io_dir_rdData_dst__prev = schniROM_4__io_dir_rdData_dst;
  dat_dump<1>(f, schniROM_4__io_dir_rdAddr, 0x26);
  schniROM_4__io_dir_rdAddr__prev = schniROM_4__io_dir_rdAddr;
  dat_dump<1>(f, schniROM_4__rdAddrReg, 0x27);
  schniROM_4__rdAddrReg__prev = schniROM_4__rdAddrReg;
  fputs("#1\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 0;
    dat_dump<1>(f, clk, 0x21);
  }
}


void schniROM_4_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
  if (t == 0L) return dump_init(f);
  fprintf(f, "#%lu\n", t << 1);
  if (clk.cnt == 0)  goto L0;
K0:  if (reset != reset__prev)  goto L1;
K1:  if (schniROM_4__io_dir_read != schniROM_4__io_dir_read__prev)  goto L2;
K2:  if (schniROM_4__io_dir_rdData_src != schniROM_4__io_dir_rdData_src__prev)  goto L3;
K3:  if (schniROM_4__io_dir_rdData_dst != schniROM_4__io_dir_rdData_dst__prev)  goto L4;
K4:  if (schniROM_4__io_dir_rdAddr != schniROM_4__io_dir_rdAddr__prev)  goto L5;
K5:  if (schniROM_4__rdAddrReg != schniROM_4__rdAddrReg__prev)  goto L6;
K6:  fprintf(f, "#%lu\n", (t << 1) + 1);
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
  schniROM_4__io_dir_read__prev = schniROM_4__io_dir_read;
  dat_dump<1>(f, schniROM_4__io_dir_read, 0x23);
  goto K2;
L3:
  schniROM_4__io_dir_rdData_src__prev = schniROM_4__io_dir_rdData_src;
  dat_dump<1>(f, schniROM_4__io_dir_rdData_src, 0x24);
  goto K3;
L4:
  schniROM_4__io_dir_rdData_dst__prev = schniROM_4__io_dir_rdData_dst;
  dat_dump<1>(f, schniROM_4__io_dir_rdData_dst, 0x25);
  goto K4;
L5:
  schniROM_4__io_dir_rdAddr__prev = schniROM_4__io_dir_rdAddr;
  dat_dump<1>(f, schniROM_4__io_dir_rdAddr, 0x26);
  goto K5;
L6:
  schniROM_4__rdAddrReg__prev = schniROM_4__rdAddrReg;
  dat_dump<1>(f, schniROM_4__rdAddrReg, 0x27);
  goto K6;
Z0:
  clk.values[0] = 0;
  dat_dump<1>(f, clk, 0x21);
  goto C0;
}




void schniROM_4_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  val_t T0;
  T0 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T1;
  T1 = 0x0L == schniROM_4__rdAddrReg.values[0];
  val_t T2;
  { T2 = T1 & T0;}
  val_t T3;
  { T3 = TERNARY(T2, 0x4L, 0x4L);}
  val_t T4;
  T4 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T5;
  T5 = 0x1L == schniROM_4__rdAddrReg.values[0];
  val_t T6;
  { T6 = T5 & T4;}
  val_t T7;
  { T7 = TERNARY(T6, 0x4L, T3);}
  val_t T8;
  T8 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T9;
  T9 = 0x2L == schniROM_4__rdAddrReg.values[0];
  val_t T10;
  { T10 = T9 & T8;}
  val_t T11;
  { T11 = TERNARY(T10, 0x4L, T7);}
  val_t T12;
  T12 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T13;
  T13 = 0x3L == schniROM_4__rdAddrReg.values[0];
  val_t T14;
  { T14 = T13 & T12;}
  val_t T15;
  { T15 = TERNARY(T14, 0x3L, T11);}
  val_t T16;
  T16 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T17;
  T17 = 0x4L == schniROM_4__rdAddrReg.values[0];
  val_t T18;
  { T18 = T17 & T16;}
  val_t T19;
  { T19 = TERNARY(T18, 0xeL, T15);}
  val_t T20;
  T20 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T21;
  T21 = 0x5L == schniROM_4__rdAddrReg.values[0];
  val_t T22;
  { T22 = T21 & T20;}
  val_t T23;
  { T23 = TERNARY(T22, 0x4L, T19);}
  val_t T24;
  T24 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T25;
  T25 = 0x6L == schniROM_4__rdAddrReg.values[0];
  val_t T26;
  { T26 = T25 & T24;}
  val_t T27;
  { T27 = TERNARY(T26, 0xaL, T23);}
  val_t T28;
  T28 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T29;
  T29 = 0x7L == schniROM_4__rdAddrReg.values[0];
  val_t T30;
  { T30 = T29 & T28;}
  val_t T31;
  { T31 = TERNARY(T30, 0xfL, T27);}
  val_t T32;
  T32 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T33;
  T33 = 0x8L == schniROM_4__rdAddrReg.values[0];
  val_t T34;
  { T34 = T33 & T32;}
  val_t T35;
  { T35 = TERNARY(T34, 0xdL, T31);}
  val_t T36;
  T36 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T37;
  T37 = 0x9L == schniROM_4__rdAddrReg.values[0];
  val_t T38;
  { T38 = T37 & T36;}
  val_t T39;
  { T39 = TERNARY(T38, 0x8L, T35);}
  val_t T40;
  T40 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T41;
  T41 = 0xaL == schniROM_4__rdAddrReg.values[0];
  val_t T42;
  { T42 = T41 & T40;}
  val_t T43;
  { T43 = TERNARY(T42, 0x2L, T39);}
  val_t T44;
  T44 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T45;
  T45 = 0xbL == schniROM_4__rdAddrReg.values[0];
  val_t T46;
  { T46 = T45 & T44;}
  val_t T47;
  { T47 = TERNARY(T46, 0xbL, T43);}
  val_t T48;
  T48 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T49;
  T49 = 0xcL == schniROM_4__rdAddrReg.values[0];
  val_t T50;
  { T50 = T49 & T48;}
  val_t T51;
  { T51 = TERNARY(T50, 0x9L, T47);}
  val_t T52;
  T52 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T53;
  T53 = 0xdL == schniROM_4__rdAddrReg.values[0];
  val_t T54;
  { T54 = T53 & T52;}
  val_t T55;
  { T55 = TERNARY(T54, 0xcL, T51);}
  val_t T56;
  T56 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T57;
  T57 = 0xeL == schniROM_4__rdAddrReg.values[0];
  val_t T58;
  { T58 = T57 & T56;}
  val_t T59;
  { T59 = TERNARY(T58, 0x6L, T55);}
  val_t T60;
  T60 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T61;
  T61 = 0xfL == schniROM_4__rdAddrReg.values[0];
  val_t T62;
  { T62 = T61 & T60;}
  val_t T63;
  { T63 = TERNARY(T62, 0x1L, T59);}
  val_t T64;
  T64 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T65;
  T65 = 0x10L == schniROM_4__rdAddrReg.values[0];
  val_t T66;
  { T66 = T65 & T64;}
  val_t T67;
  { T67 = TERNARY(T66, 0x7L, T63);}
  val_t T68;
  T68 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T69;
  T69 = 0x11L == schniROM_4__rdAddrReg.values[0];
  val_t T70;
  { T70 = T69 & T68;}
  val_t T71;
  { T71 = TERNARY(T70, 0x0L, T67);}
  val_t T72;
  T72 = schniROM_4__io_dir_read.values[0] == 0x1L;
  val_t T73;
  T73 = 0x12L == schniROM_4__rdAddrReg.values[0];
  val_t T74;
  { T74 = T73 & T72;}
  val_t T75;
  { T75 = TERNARY(T74, 0x5L, T71);}
  { schniROM_4__io_dir_rdData_src.values[0] = T75;}
  val_t T76;
  { T76 = TERNARY(T2, 0x4L, 0x4L);}
  val_t T77;
  { T77 = TERNARY(T6, 0x2L, T76);}
  val_t T78;
  { T78 = TERNARY(T10, 0xdL, T77);}
  val_t T79;
  { T79 = TERNARY(T14, 0xfL, T78);}
  val_t T80;
  { T80 = TERNARY(T18, 0x4L, T79);}
  val_t T81;
  { T81 = TERNARY(T22, 0xaL, T80);}
  val_t T82;
  { T82 = TERNARY(T26, 0x0L, T81);}
  val_t T83;
  { T83 = TERNARY(T30, 0x1L, T82);}
  val_t T84;
  { T84 = TERNARY(T34, 0x3L, T83);}
  val_t T85;
  { T85 = TERNARY(T38, 0xcL, T84);}
  val_t T86;
  { T86 = TERNARY(T42, 0x6L, T85);}
  val_t T87;
  { T87 = TERNARY(T46, 0xbL, T86);}
  val_t T88;
  { T88 = TERNARY(T50, 0x4L, T87);}
  val_t T89;
  { T89 = TERNARY(T54, 0x5L, T88);}
  val_t T90;
  { T90 = TERNARY(T58, 0x8L, T89);}
  val_t T91;
  { T91 = TERNARY(T62, 0x7L, T90);}
  val_t T92;
  { T92 = TERNARY(T66, 0x4L, T91);}
  val_t T93;
  { T93 = TERNARY(T70, 0xeL, T92);}
  val_t T94;
  { T94 = TERNARY(T74, 0x9L, T93);}
  { schniROM_4__io_dir_rdData_dst.values[0] = T94;}
}


void schniROM_4_t::clock_hi ( dat_t<1> reset ) {
  dat_t<20> schniROM_4__rdAddrReg__shadow = schniROM_4__io_dir_rdAddr;
  schniROM_4__rdAddrReg = schniROM_4__io_dir_rdAddr;
}


void schniROM_4_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  schniROM_4_t* mod = dynamic_cast<schniROM_4_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<20>(&mod->schniROM_4__io_dir_rdAddr));
  sim_data.inputs.push_back(new dat_api<1>(&mod->schniROM_4__io_dir_read));
  sim_data.outputs.push_back(new dat_api<4>(&mod->schniROM_4__io_dir_rdData_src));
  sim_data.outputs.push_back(new dat_api<4>(&mod->schniROM_4__io_dir_rdData_dst));
  sim_data.signals.push_back(new dat_api<20>(&mod->schniROM_4__rdAddrReg));
  sim_data.signal_map["schniROM_4.rdAddrReg"] = 0;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
