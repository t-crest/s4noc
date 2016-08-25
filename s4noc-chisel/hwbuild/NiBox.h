#ifndef __NiBox__
#define __NiBox__

#include "emulator.h"

class NiBox_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> NiBox__io_core_io_ip_rtw;
  dat_t<1> NiBox_control_ni__io_ipNI_io_ip_rtw;
  dat_t<1> reset;
  dat_t<1> NiBox_control_ni__reset;
  dat_t<1> T34;
  dat_t<1> NiBox_control_ni__qt_3_valid;
  dat_t<1> T37;
  dat_t<1> NiBox_control_ni__qt_2_valid;
  dat_t<1> T46;
  dat_t<1> NiBox_control_ni__qt_1_valid;
  dat_t<1> T55;
  dat_t<1> NiBox_control_ni__qt_0_valid;
  dat_t<1> T63;
  dat_t<1> NiBox_control_ni__tx_dout_valid;
  dat_t<1> NiBox_control_ni__io_ipNI_io_ip_ack;
  dat_t<1> NiBox_control_ni__io_dir_read;
  dat_t<1> NiBox_schedule_ni__io_dir_read;
  dat_t<1> NiBox__io_core_io_ip_ack;
  dat_t<1> NiBox_control_ni__io_ipNI_io_ip_qtBusy;
  dat_t<1> NiBox__io_core_io_ip_qtBusy;
  dat_t<1> NiBox_control_ni__io_r_lc_dout_valid;
  dat_t<1> NiBox__io_output1_valid;
  dat_t<1> NiBox__io_core_io_router_tx;
  dat_t<2> T43;
  dat_t<2> NiBox_control_ni__qtHead;
  dat_t<2> T52;
  dat_t<2> NiBox_control_ni__qtTail;
  dat_t<3> T152;
  dat_t<3> NiBox_control_ni__qtPhitCount;
  dat_t<4> NiBox_schedule_ni__io_dir_rdData_dst;
  dat_t<4> NiBox_control_ni__io_dir_rdData_dst;
  dat_t<4> T140;
  dat_t<4> NiBox_control_ni__reg_dir_data_dst;
  dat_t<4> NiBox__io_core_io_ip_addr;
  dat_t<4> NiBox_control_ni__io_ipNI_io_ip_addr;
  dat_t<4> T141;
  dat_t<4> NiBox_control_ni__reg_tx_dst;
  dat_t<19> T154;
  dat_t<19> NiBox_control_ni__reg_slotCount;
  dat_t<20> NiBox_control_ni__io_dir_rdAddr;
  dat_t<20> NiBox_schedule_ni__io_dir_rdAddr;
  dat_t<20> NiBox_schedule_ni__rdAddrReg;
  dat_t<32> NiBox__io_core_io_ip_din;
  dat_t<32> NiBox_control_ni__io_ipNI_io_ip_din;
  dat_t<32> T7;
  dat_t<32> NiBox_control_ni__qt_3_data;
  dat_t<32> T11;
  dat_t<32> NiBox_control_ni__qt_2_data;
  dat_t<32> T15;
  dat_t<32> NiBox_control_ni__qt_1_data;
  dat_t<32> T19;
  dat_t<32> NiBox_control_ni__qt_0_data;
  dat_t<32> T31;
  dat_t<32> NiBox_control_ni__tx_dout_data;
  dat_t<32> NiBox_control_ni__io_ipNI_io_ip_dout;
  dat_t<32> NiBox__io_core_io_ip_dout;
  dat_t<32> NiBox_control_ni__io_r_lc_dout_data;
  dat_t<32> NiBox__io_output1_data;
  dat_t<1> NiBox__io_core_io_ip_rtw__prev;
  dat_t<1> NiBox_control_ni__io_ipNI_io_ip_rtw__prev;
  dat_t<1> NiBox_control_ni__reset__prev;
  dat_t<1> NiBox_control_ni__qt_3_valid__prev;
  dat_t<1> NiBox_control_ni__qt_2_valid__prev;
  dat_t<1> NiBox_control_ni__qt_1_valid__prev;
  dat_t<1> NiBox_control_ni__qt_0_valid__prev;
  dat_t<1> NiBox_control_ni__tx_dout_valid__prev;
  dat_t<1> NiBox_control_ni__io_ipNI_io_ip_ack__prev;
  dat_t<1> NiBox_control_ni__io_dir_read__prev;
  dat_t<1> NiBox_schedule_ni__io_dir_read__prev;
  dat_t<1> NiBox__io_core_io_ip_ack__prev;
  dat_t<1> NiBox_control_ni__io_ipNI_io_ip_qtBusy__prev;
  dat_t<1> NiBox__io_core_io_ip_qtBusy__prev;
  dat_t<1> NiBox_control_ni__io_r_lc_dout_valid__prev;
  dat_t<1> NiBox__io_output1_valid__prev;
  dat_t<1> NiBox__io_core_io_router_tx__prev;
  dat_t<2> NiBox_control_ni__qtHead__prev;
  dat_t<2> NiBox_control_ni__qtTail__prev;
  dat_t<3> NiBox_control_ni__qtPhitCount__prev;
  dat_t<4> NiBox_schedule_ni__io_dir_rdData_dst__prev;
  dat_t<4> NiBox_control_ni__io_dir_rdData_dst__prev;
  dat_t<4> NiBox_control_ni__reg_dir_data_dst__prev;
  dat_t<4> NiBox__io_core_io_ip_addr__prev;
  dat_t<4> NiBox_control_ni__io_ipNI_io_ip_addr__prev;
  dat_t<4> NiBox_control_ni__reg_tx_dst__prev;
  dat_t<19> NiBox_control_ni__reg_slotCount__prev;
  dat_t<20> NiBox_control_ni__io_dir_rdAddr__prev;
  dat_t<20> NiBox_schedule_ni__io_dir_rdAddr__prev;
  dat_t<20> NiBox_schedule_ni__rdAddrReg__prev;
  dat_t<32> NiBox__io_core_io_ip_din__prev;
  dat_t<32> NiBox_control_ni__io_ipNI_io_ip_din__prev;
  dat_t<32> NiBox_control_ni__qt_3_data__prev;
  dat_t<32> NiBox_control_ni__qt_2_data__prev;
  dat_t<32> NiBox_control_ni__qt_1_data__prev;
  dat_t<32> NiBox_control_ni__qt_0_data__prev;
  dat_t<32> NiBox_control_ni__tx_dout_data__prev;
  dat_t<32> NiBox_control_ni__io_ipNI_io_ip_dout__prev;
  dat_t<32> NiBox__io_core_io_ip_dout__prev;
  dat_t<32> NiBox_control_ni__io_r_lc_dout_data__prev;
  dat_t<32> NiBox__io_output1_data__prev;
  clk_t clk;
  dat_t<1> reset__prev;

  void init ( val_t rand_init = 0 );
  void clock_lo ( dat_t<1> reset, bool assert_fire=true );
  void clock_hi ( dat_t<1> reset );
  int clock ( dat_t<1> reset );
  void print ( FILE* f );
  void print ( std::ostream& s );
  void dump ( FILE* f, val_t t, dat_t<1> reset=LIT<1>(0) );
  void dump_init ( FILE* f );

};

#include "emul_api.h"
class NiBox_api_t : public emul_api_t {
 public:
  NiBox_api_t(mod_t* m) : emul_api_t(m) { }
  void init_sim_data();
};

#endif
