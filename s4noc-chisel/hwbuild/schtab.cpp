#include "schtab.h"

void schtab_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int schtab_t::clock ( dat_t<1> reset ) {
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


void schtab_t::print ( FILE* f ) {
}
void schtab_t::print ( std::ostream& s ) {
}


void schtab_t::dump_init ( FILE* f ) {
  fputs("$timescale 1ps $end\n", f);
  fputs("$scope module schtab $end\n", f);
  fputs("$var wire 1 \x21 clk $end\n", f);
  fputs("$var wire 1 \x22 reset $end\n", f);
  fputs("$var wire 3 \x23 io_rInfo_schtab_io_up $end\n", f);
  fputs("$var wire 3 \x24 io_rInfo_schtab_io_right $end\n", f);
  fputs("$var wire 3 \x25 io_rInfo_schtab_io_down $end\n", f);
  fputs("$var wire 3 \x26 io_rInfo_schtab_io_left $end\n", f);
  fputs("$var wire 3 \x27 io_rInfo_schtab_io_local $end\n", f);
  fputs("$var wire 3 \x28 io_rInfo_schtab_io_dc $end\n", f);
  fputs("$var wire 16 \x29 io_slotCounter_schtab_io $end\n", f);
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
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_up, 0x23);
  schtab__io_rInfo_schtab_io_up__prev = schtab__io_rInfo_schtab_io_up;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_right, 0x24);
  schtab__io_rInfo_schtab_io_right__prev = schtab__io_rInfo_schtab_io_right;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_down, 0x25);
  schtab__io_rInfo_schtab_io_down__prev = schtab__io_rInfo_schtab_io_down;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_left, 0x26);
  schtab__io_rInfo_schtab_io_left__prev = schtab__io_rInfo_schtab_io_left;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_local, 0x27);
  schtab__io_rInfo_schtab_io_local__prev = schtab__io_rInfo_schtab_io_local;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_dc, 0x28);
  schtab__io_rInfo_schtab_io_dc__prev = schtab__io_rInfo_schtab_io_dc;
  dat_dump<1>(f, schtab__io_slotCounter_schtab_io, 0x29);
  schtab__io_slotCounter_schtab_io__prev = schtab__io_slotCounter_schtab_io;
  fputs("#1\n", f);
  if (clk.cnt == 0) {
    clk.values[0] = 0;
    dat_dump<1>(f, clk, 0x21);
  }
}


void schtab_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
  if (t == 0L) return dump_init(f);
  fprintf(f, "#%lu\n", t << 1);
  if (clk.cnt == 0)  goto L0;
K0:  if (reset != reset__prev)  goto L1;
K1:  if (schtab__io_rInfo_schtab_io_up != schtab__io_rInfo_schtab_io_up__prev)  goto L2;
K2:  if (schtab__io_rInfo_schtab_io_right != schtab__io_rInfo_schtab_io_right__prev)  goto L3;
K3:  if (schtab__io_rInfo_schtab_io_down != schtab__io_rInfo_schtab_io_down__prev)  goto L4;
K4:  if (schtab__io_rInfo_schtab_io_left != schtab__io_rInfo_schtab_io_left__prev)  goto L5;
K5:  if (schtab__io_rInfo_schtab_io_local != schtab__io_rInfo_schtab_io_local__prev)  goto L6;
K6:  if (schtab__io_rInfo_schtab_io_dc != schtab__io_rInfo_schtab_io_dc__prev)  goto L7;
K7:  if (schtab__io_slotCounter_schtab_io != schtab__io_slotCounter_schtab_io__prev)  goto L8;
K8:  fprintf(f, "#%lu\n", (t << 1) + 1);
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
  schtab__io_rInfo_schtab_io_up__prev = schtab__io_rInfo_schtab_io_up;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_up, 0x23);
  goto K2;
L3:
  schtab__io_rInfo_schtab_io_right__prev = schtab__io_rInfo_schtab_io_right;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_right, 0x24);
  goto K3;
L4:
  schtab__io_rInfo_schtab_io_down__prev = schtab__io_rInfo_schtab_io_down;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_down, 0x25);
  goto K4;
L5:
  schtab__io_rInfo_schtab_io_left__prev = schtab__io_rInfo_schtab_io_left;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_left, 0x26);
  goto K5;
L6:
  schtab__io_rInfo_schtab_io_local__prev = schtab__io_rInfo_schtab_io_local;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_local, 0x27);
  goto K6;
L7:
  schtab__io_rInfo_schtab_io_dc__prev = schtab__io_rInfo_schtab_io_dc;
  dat_dump<1>(f, schtab__io_rInfo_schtab_io_dc, 0x28);
  goto K7;
L8:
  schtab__io_slotCounter_schtab_io__prev = schtab__io_slotCounter_schtab_io;
  dat_dump<1>(f, schtab__io_slotCounter_schtab_io, 0x29);
  goto K8;
Z0:
  clk.values[0] = 0;
  dat_dump<1>(f, clk, 0x21);
  goto C0;
}




void schtab_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  val_t T0;
  T0 = schtab__io_slotCounter_schtab_io.values[0] == 0x0L;
  val_t T1;
  { T1 = TERNARY(T0, 0x1L, 0x0L);}
  val_t T2;
  T2 = schtab__io_slotCounter_schtab_io.values[0] == 0x1L;
  val_t T3;
  { T3 = T0 ^ 0x1L;}
  val_t T4;
  { T4 = T3 & T2;}
  val_t T5;
  { T5 = TERNARY(T4, 0x2L, T1);}
  val_t T6;
  T6 = schtab__io_slotCounter_schtab_io.values[0] == 0x2L;
  val_t T7;
  { T7 = T0 | T2;}
  val_t T8;
  { T8 = T7 ^ 0x1L;}
  val_t T9;
  { T9 = T8 & T6;}
  val_t T10;
  { T10 = TERNARY(T9, 0x0L, T5);}
  val_t T11;
  T11 = schtab__io_slotCounter_schtab_io.values[0] == 0x3L;
  val_t T12;
  { T12 = T7 | T6;}
  val_t T13;
  { T13 = T12 ^ 0x1L;}
  val_t T14;
  { T14 = T13 & T11;}
  val_t T15;
  { T15 = TERNARY(T14, 0x1L, T10);}
  val_t T16;
  T16 = schtab__io_slotCounter_schtab_io.values[0] == 0x4L;
  val_t T17;
  { T17 = T12 | T11;}
  val_t T18;
  { T18 = T17 ^ 0x1L;}
  val_t T19;
  { T19 = T18 & T16;}
  val_t T20;
  { T20 = TERNARY(T19, 0x1L, T15);}
  val_t T21;
  T21 = schtab__io_slotCounter_schtab_io.values[0] == 0x5L;
  val_t T22;
  { T22 = T17 | T16;}
  val_t T23;
  { T23 = T22 ^ 0x1L;}
  val_t T24;
  { T24 = T23 & T21;}
  val_t T25;
  { T25 = TERNARY(T24, 0x2L, T20);}
  val_t T26;
  T26 = schtab__io_slotCounter_schtab_io.values[0] == 0x6L;
  val_t T27;
  { T27 = T22 | T21;}
  val_t T28;
  { T28 = T27 ^ 0x1L;}
  val_t T29;
  { T29 = T28 & T26;}
  val_t T30;
  { T30 = TERNARY(T29, 0x4L, T25);}
  val_t T31;
  T31 = schtab__io_slotCounter_schtab_io.values[0] == 0x7L;
  val_t T32;
  { T32 = T27 | T26;}
  val_t T33;
  { T33 = T32 ^ 0x1L;}
  val_t T34;
  { T34 = T33 & T31;}
  val_t T35;
  { T35 = TERNARY(T34, 0x2L, T30);}
  val_t T36;
  T36 = schtab__io_slotCounter_schtab_io.values[0] == 0x8L;
  val_t T37;
  { T37 = T32 | T31;}
  val_t T38;
  { T38 = T37 ^ 0x1L;}
  val_t T39;
  { T39 = T38 & T36;}
  val_t T40;
  { T40 = TERNARY(T39, 0x1L, T35);}
  val_t T41;
  T41 = schtab__io_slotCounter_schtab_io.values[0] == 0x9L;
  val_t T42;
  { T42 = T37 | T36;}
  val_t T43;
  { T43 = T42 ^ 0x1L;}
  val_t T44;
  { T44 = T43 & T41;}
  val_t T45;
  { T45 = TERNARY(T44, 0x1L, T40);}
  val_t T46;
  T46 = schtab__io_slotCounter_schtab_io.values[0] == 0xaL;
  val_t T47;
  { T47 = T42 | T41;}
  val_t T48;
  { T48 = T47 ^ 0x1L;}
  val_t T49;
  { T49 = T48 & T46;}
  val_t T50;
  { T50 = TERNARY(T49, 0x1L, T45);}
  val_t T51;
  T51 = schtab__io_slotCounter_schtab_io.values[0] == 0xbL;
  val_t T52;
  { T52 = T47 | T46;}
  val_t T53;
  { T53 = T52 ^ 0x1L;}
  val_t T54;
  { T54 = T53 & T51;}
  val_t T55;
  { T55 = TERNARY(T54, 0x1L, T50);}
  val_t T56;
  T56 = schtab__io_slotCounter_schtab_io.values[0] == 0xcL;
  val_t T57;
  { T57 = T52 | T51;}
  val_t T58;
  { T58 = T57 ^ 0x1L;}
  val_t T59;
  { T59 = T58 & T56;}
  val_t T60;
  { T60 = TERNARY(T59, 0x2L, T55);}
  val_t T61;
  T61 = schtab__io_slotCounter_schtab_io.values[0] == 0xdL;
  val_t T62;
  { T62 = T57 | T56;}
  val_t T63;
  { T63 = T62 ^ 0x1L;}
  val_t T64;
  { T64 = T63 & T61;}
  val_t T65;
  { T65 = TERNARY(T64, 0x0L, T60);}
  val_t T66;
  T66 = schtab__io_slotCounter_schtab_io.values[0] == 0xeL;
  val_t T67;
  { T67 = T62 | T61;}
  val_t T68;
  { T68 = T67 ^ 0x1L;}
  val_t T69;
  { T69 = T68 & T66;}
  val_t T70;
  { T70 = TERNARY(T69, 0x0L, T65);}
  val_t T71;
  T71 = schtab__io_slotCounter_schtab_io.values[0] == 0xfL;
  val_t T72;
  { T72 = T67 | T66;}
  val_t T73;
  { T73 = T72 ^ 0x1L;}
  val_t T74;
  { T74 = T73 & T71;}
  val_t T75;
  { T75 = TERNARY(T74, 0x0L, T70);}
  val_t T76;
  T76 = schtab__io_slotCounter_schtab_io.values[0] == 0x10L;
  val_t T77;
  { T77 = T72 | T71;}
  val_t T78;
  { T78 = T77 ^ 0x1L;}
  val_t T79;
  { T79 = T78 & T76;}
  val_t T80;
  { T80 = TERNARY(T79, 0x0L, T75);}
  val_t T81;
  T81 = schtab__io_slotCounter_schtab_io.values[0] == 0x11L;
  val_t T82;
  { T82 = T77 | T76;}
  val_t T83;
  { T83 = T82 ^ 0x1L;}
  val_t T84;
  { T84 = T83 & T81;}
  val_t T85;
  { T85 = TERNARY(T84, 0x0L, T80);}
  val_t T86;
  T86 = schtab__io_slotCounter_schtab_io.values[0] == 0x12L;
  val_t T87;
  { T87 = T82 | T81;}
  val_t T88;
  { T88 = T87 ^ 0x1L;}
  val_t T89;
  { T89 = T88 & T86;}
  val_t T90;
  { T90 = TERNARY(T89, 0x0L, T85);}
  { schtab__io_rInfo_schtab_io_up.values[0] = T90;}
  val_t T91;
  { T91 = TERNARY(T0, 0x0L, 0x0L);}
  val_t T92;
  { T92 = TERNARY(T4, 0x1L, T91);}
  val_t T93;
  { T93 = TERNARY(T9, 0x2L, T92);}
  val_t T94;
  { T94 = TERNARY(T14, 0x3L, T93);}
  val_t T95;
  { T95 = TERNARY(T19, 0x2L, T94);}
  val_t T96;
  { T96 = TERNARY(T24, 0x3L, T95);}
  val_t T97;
  { T97 = TERNARY(T29, 0x2L, T96);}
  val_t T98;
  { T98 = TERNARY(T34, 0x1L, T97);}
  val_t T99;
  { T99 = TERNARY(T39, 0x3L, T98);}
  val_t T100;
  { T100 = TERNARY(T44, 0x0L, T99);}
  val_t T101;
  { T101 = TERNARY(T49, 0x2L, T100);}
  val_t T102;
  { T102 = TERNARY(T54, 0x0L, T101);}
  val_t T103;
  { T103 = TERNARY(T59, 0x1L, T102);}
  val_t T104;
  { T104 = TERNARY(T64, 0x3L, T103);}
  val_t T105;
  { T105 = TERNARY(T69, 0x0L, T104);}
  val_t T106;
  { T106 = TERNARY(T74, 0x1L, T105);}
  val_t T107;
  { T107 = TERNARY(T79, 0x0L, T106);}
  val_t T108;
  { T108 = TERNARY(T84, 0x0L, T107);}
  val_t T109;
  { T109 = TERNARY(T89, 0x0L, T108);}
  { schtab__io_rInfo_schtab_io_right.values[0] = T109;}
  val_t T110;
  { T110 = TERNARY(T0, 0x0L, 0x0L);}
  val_t T111;
  { T111 = TERNARY(T4, 0x0L, T110);}
  val_t T112;
  { T112 = TERNARY(T9, 0x3L, T111);}
  val_t T113;
  { T113 = TERNARY(T14, 0x0L, T112);}
  val_t T114;
  { T114 = TERNARY(T19, 0x0L, T113);}
  val_t T115;
  { T115 = TERNARY(T24, 0x0L, T114);}
  val_t T116;
  { T116 = TERNARY(T29, 0x0L, T115);}
  val_t T117;
  { T117 = TERNARY(T34, 0x0L, T116);}
  val_t T118;
  { T118 = TERNARY(T39, 0x0L, T117);}
  val_t T119;
  { T119 = TERNARY(T44, 0x3L, T118);}
  val_t T120;
  { T120 = TERNARY(T49, 0x0L, T119);}
  val_t T121;
  { T121 = TERNARY(T54, 0x0L, T120);}
  val_t T122;
  { T122 = TERNARY(T59, 0x0L, T121);}
  val_t T123;
  { T123 = TERNARY(T64, 0x1L, T122);}
  val_t T124;
  { T124 = TERNARY(T69, 0x0L, T123);}
  val_t T125;
  { T125 = TERNARY(T74, 0x0L, T124);}
  val_t T126;
  { T126 = TERNARY(T79, 0x1L, T125);}
  val_t T127;
  { T127 = TERNARY(T84, 0x0L, T126);}
  val_t T128;
  { T128 = TERNARY(T89, 0x0L, T127);}
  { schtab__io_rInfo_schtab_io_down.values[0] = T128;}
  val_t T129;
  { T129 = TERNARY(T0, 0x0L, 0x0L);}
  val_t T130;
  { T130 = TERNARY(T4, 0x0L, T129);}
  val_t T131;
  { T131 = TERNARY(T9, 0x0L, T130);}
  val_t T132;
  { T132 = TERNARY(T14, 0x0L, T131);}
  val_t T133;
  { T133 = TERNARY(T19, 0x0L, T132);}
  val_t T134;
  { T134 = TERNARY(T24, 0x1L, T133);}
  val_t T135;
  { T135 = TERNARY(T29, 0x0L, T134);}
  val_t T136;
  { T136 = TERNARY(T34, 0x0L, T135);}
  val_t T137;
  { T137 = TERNARY(T39, 0x0L, T136);}
  val_t T138;
  { T138 = TERNARY(T44, 0x0L, T137);}
  val_t T139;
  { T139 = TERNARY(T49, 0x0L, T138);}
  val_t T140;
  { T140 = TERNARY(T54, 0x2L, T139);}
  val_t T141;
  { T141 = TERNARY(T59, 0x0L, T140);}
  val_t T142;
  { T142 = TERNARY(T64, 0x0L, T141);}
  val_t T143;
  { T143 = TERNARY(T69, 0x5L, T142);}
  val_t T144;
  { T144 = TERNARY(T74, 0x0L, T143);}
  val_t T145;
  { T145 = TERNARY(T79, 0x0L, T144);}
  val_t T146;
  { T146 = TERNARY(T84, 0x1L, T145);}
  val_t T147;
  { T147 = TERNARY(T89, 0x0L, T146);}
  { schtab__io_rInfo_schtab_io_left.values[0] = T147;}
  val_t T148;
  { T148 = TERNARY(T0, 0x0L, 0x0L);}
  val_t T149;
  { T149 = TERNARY(T4, 0x0L, T148);}
  val_t T150;
  { T150 = TERNARY(T9, 0x0L, T149);}
  val_t T151;
  { T151 = TERNARY(T14, 0x5L, T150);}
  val_t T152;
  { T152 = TERNARY(T19, 0x3L, T151);}
  val_t T153;
  { T153 = TERNARY(T24, 0x0L, T152);}
  val_t T154;
  { T154 = TERNARY(T29, 0x3L, T153);}
  val_t T155;
  { T155 = TERNARY(T34, 0x3L, T154);}
  val_t T156;
  { T156 = TERNARY(T39, 0x2L, T155);}
  val_t T157;
  { T157 = TERNARY(T44, 0x2L, T156);}
  val_t T158;
  { T158 = TERNARY(T49, 0x5L, T157);}
  val_t T159;
  { T159 = TERNARY(T54, 0x3L, T158);}
  val_t T160;
  { T160 = TERNARY(T59, 0x4L, T159);}
  val_t T161;
  { T161 = TERNARY(T64, 0x2L, T160);}
  val_t T162;
  { T162 = TERNARY(T69, 0x3L, T161);}
  val_t T163;
  { T163 = TERNARY(T74, 0x4L, T162);}
  val_t T164;
  { T164 = TERNARY(T79, 0x3L, T163);}
  val_t T165;
  { T165 = TERNARY(T84, 0x5L, T164);}
  val_t T166;
  { T166 = TERNARY(T89, 0x4L, T165);}
  { schtab__io_rInfo_schtab_io_local.values[0] = T166;}
  { schtab__io_rInfo_schtab_io_dc.values[0] = 0x0L;}
}


void schtab_t::clock_hi ( dat_t<1> reset ) {
}


void schtab_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  schtab_t* mod = dynamic_cast<schtab_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<16>(&mod->schtab__io_slotCounter_schtab_io));
  sim_data.outputs.push_back(new dat_api<3>(&mod->schtab__io_rInfo_schtab_io_up));
  sim_data.outputs.push_back(new dat_api<3>(&mod->schtab__io_rInfo_schtab_io_right));
  sim_data.outputs.push_back(new dat_api<3>(&mod->schtab__io_rInfo_schtab_io_down));
  sim_data.outputs.push_back(new dat_api<3>(&mod->schtab__io_rInfo_schtab_io_left));
  sim_data.outputs.push_back(new dat_api<3>(&mod->schtab__io_rInfo_schtab_io_local));
  sim_data.outputs.push_back(new dat_api<3>(&mod->schtab__io_rInfo_schtab_io_dc));
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
