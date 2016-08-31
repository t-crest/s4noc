package patmos
import Chisel._
import Node._

import ConstantsN._

class Ip() extends Module {
 val io = new ipIO()

      io.ipNI_io.ip_din:= Bits(0)
      io.ipNI_io.ip_addr:= Bits(0)
      io.led1:=UInt(0) 
      io.led2:= UInt(0)

      io.ipNI_io.router_tx:= Bool(false) 
 val transmit = Bool()
     transmit := !(io.ipNI_io.ip_qtBusy)

 val CNT_MAX = UInt(20000000 / 2 - 1);

  val cntReg = Reg(init = UInt(0, 25))
  val blkReg = Reg(init = UInt(0, 1))

  cntReg := cntReg + UInt(1)
  when(cntReg === CNT_MAX) {
    cntReg := UInt(0)
    blkReg := ~blkReg
    when (transmit){
      io.ipNI_io.ip_din:= TEST_VALUE_1
      io.ipNI_io.router_tx:= Bool(true) 
      io.ipNI_io.ip_addr:= Bits(10) // suppose to change
    }
  }
//  io.led1 := blkReg

  when ( io.ipNI_io.ip_dout === TEST_VALUE_1 ){
    io.led1:=blkReg
    io.led2:= UInt(0)

  }.elsewhen (io.ipNI_io.ip_dout === TEST_VALUE_2) {
    io.led1:= UInt(0)
    io.led2:=  ~blkReg
  }.otherwise{
    io.led1:= UInt(0)
    io.led2:= UInt(0)
  }




}


class TestIp(dut: Ip) extends Tester(dut) {


}

object tIpBox {
   def main(args: Array[String]): Unit = {
      chiselMainTest(args,
         () => Module(new Ip())) {
            dut => new TestIp(dut)
         }
      }
}




 