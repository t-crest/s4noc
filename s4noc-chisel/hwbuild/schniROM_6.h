#ifndef __schniROM_6__
#define __schniROM_6__

#include "emulator.h"

class schniROM_6_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> schniROM_6__io_dir_read;
  dat_t<4> schniROM_6__io_dir_rdData_src;
  dat_t<4> schniROM_6__io_dir_rdData_dst;
  dat_t<20> schniROM_6__io_dir_rdAddr;
  dat_t<20> schniROM_6__rdAddrReg;
  dat_t<1> schniROM_6__io_dir_read__prev;
  dat_t<4> schniROM_6__io_dir_rdData_src__prev;
  dat_t<4> schniROM_6__io_dir_rdData_dst__prev;
  dat_t<20> schniROM_6__io_dir_rdAddr__prev;
  dat_t<20> schniROM_6__rdAddrReg__prev;
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
class schniROM_6_api_t : public emul_api_t {
 public:
  schniROM_6_api_t(mod_t* m) : emul_api_t(m) { }
  void init_sim_data();
};

#endif
