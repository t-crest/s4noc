package patmos

import Chisel._
import Node._

import ConstantsN._


class niQueue(length: Int) extends Module {
  val io = new niIO()
  val reg_slotCount = Reg(init = UInt(0, TDM_PERIOD))

  val router_tx = Bool()
    router_tx:= Bool(false)


// =====================================================================
// Slot Counter
// ===================================================================== 

  when(reg_slotCount === UInt(TDM_PERIOD)) {
    reg_slotCount := UInt(0)
  }

  reg_slotCount := reg_slotCount + UInt(1)

// ===================================================================== 


   val init_phit = new phit()

   init_phit.data := Bits(0)
   init_phit.valid := Bits(0)

  val tx_dout = Reg(init = init_phit)
  
// =====================================================================
// qT: Queue Transmit
// =====================================================================

  val qtHead = Reg(init = UInt(0, width = log2Up(length)))
  val qtTail = Reg(init = UInt(0, width = log2Up(length)))

  val qtPhitCount = Reg(init = UInt(0, width = log2Up(length+1)))
  
  val qtInc = Bool() 
      qtInc := Bool(false)
  val qtDec = Bool()
      qtDec := Bool(false)

  val qtFull = Bool()
      qtFull:= (qtPhitCount === UInt(length))

  val qtEmpty = Bool()
      qtEmpty:=(qtPhitCount === UInt(0))

  val qtTailNext = UInt(width = log2Up(length))
      qtTailNext := Mux(qtTail === UInt(length), UInt(0), qtTail + UInt(1))

  val qtHeadNext = UInt(width = log2Up(length))
      qtHeadNext := Mux(qtHead === UInt(length), UInt(0), qtHead + UInt(1))
// =====================================================================
// qT: Signal state of Queueu Transmit
// =====================================================================
  io.ipNI_io.ip_qtBusy:= qtFull
// =====================================================================
// Inistantiate phit - queue elements
// =====================================================================

  val qphit_init_state = new phit()
    
    qphit_init_state.data:= Bits(0)
    qphit_init_state.valid:= Bool(false)

  
  val qt = Vec.fill(length) { Reg(init = qphit_init_state) }

//  val qReceived = Vec.fill(length) { Reg(init = qphit_init_state) }

// =====================================================================
// Insert Element in TransmitQueue
// =====================================================================

  when (io.ipNI_io.ip_rtw && !qtFull) {
    qt(qtTail).data:= io.ipNI_io.ip_din
    qt(qtTail).valid:= Bool(true)
    qtTail := qtTailNext
    qtInc := Bool(true)
  }

// =====================================================================
// Remove Element in TransmitQueue
// =====================================================================

  when(router_tx && !qtEmpty ){
      tx_dout:= qt(qtHead)
      qtHead:= qtHeadNext
      qtDec := Bool(true)
  }.otherwise{
    io.r_lc_dout.data:= Bits(0)
    io.r_lc_dout.valid:= Bool(false)
  }


  io.r_lc_dout:= tx_dout

  when (qtInc && !qtDec) {
    qtPhitCount := qtPhitCount + UInt(1)
  } 
  .elsewhen (!qtInc && qtDec) {
    qtPhitCount := qtPhitCount - UInt(1)
  }


// =======================================
//    NI - SCHEDULE 
// =======================================
val init_dir_data = new nav(UInt(0),UInt(0))

val reg_dir_data_src = Reg(init = UInt(0,ADDRESS_WIDTH))
val reg_dir_data_dst = Reg(init = UInt(0,ADDRESS_WIDTH))

/*** ip_addr should be received from the top of transmit queue ***/
val reg_tx_dst = Reg(init = UInt(0,ADDRESS_WIDTH))
reg_tx_dst:= io.ipNI_io.ip_addr
/*** --------------------------------------------------------- ***/

// send slot counter and receive src and destination
io.dir_rdAddr:= reg_slotCount
io.dir_read:= Bool(true)
reg_dir_data_src:= io.dir_rdData_src
reg_dir_data_dst:= io.dir_rdData_dst

when (reg_dir_data_dst === reg_tx_dst){
  router_tx:=Bool(true)
}
/*

//what do we do according to dir_data destination and source
//address

*/
}
 class niQueueTest(dut: niQueue) extends Tester(dut) {
   // ====================================
   // check that queue logic works
   // ====================================
     poke(dut.io.ipNI_io.ip_rtw,1)
     poke(dut.io.ipNI_io.ip_din,5)

     poke(dut.io.ipNI_io.ip_addr,5)
     poke(dut.io.dir_rdData_dst,0)

    expect(dut.qtPhitCount,0) 
   step(1)
    poke(dut.io.ipNI_io.ip_rtw,1)
     poke(dut.io.ipNI_io.ip_din,4)

    expect(dut.qtPhitCount,1) 
    // poke(dut.io.ipNI_io.ip_addr,3)
  step(1)
    poke(dut.io.ipNI_io.ip_rtw,1)
     poke(dut.io.ipNI_io.ip_din,2)
        expect(dut.qtPhitCount,2)  
   step(1)
     poke(dut.io.dir_rdData_dst,5)
//val reg_valid = Reg(init = Bits(0,1))
        expect(dut.qtPhitCount,3)  

    peek(dut.io.r_lc_dout)
    peek(dut.tx_dout)
     poke(dut.io.ipNI_io.ip_addr,5)
     poke(dut.io.ipNI_io.ip_rtw,0)
   step(1)

     poke(dut.io.ipNI_io.ip_addr,2)
    expect(dut.qtPhitCount,3)
     
    peek(dut.io.r_lc_dout)

    peek(dut.tx_dout)
    expect(dut.io.ipNI_io.ip_qtBusy,0)
   step(1)

     poke(dut.io.ipNI_io.ip_addr,5)

    peek(dut.io.r_lc_dout)

    peek(dut.tx_dout)
     expect(dut.qtPhitCount,2)
     expect(dut.io.ipNI_io.ip_qtBusy,0)
   step(1)

     poke(dut.io.ipNI_io.ip_addr,3)
     expect(dut.qtPhitCount,2)

    peek(dut.io.r_lc_dout)
    peek(dut.tx_dout)
     expect(dut.io.ipNI_io.ip_qtBusy,0)
   step(1)

     expect(dut.qtPhitCount,2)
     expect(dut.io.ipNI_io.ip_qtBusy,0)
   step(1)

     expect(dut.qtPhitCount,2)
     expect(dut.io.ipNI_io.ip_qtBusy,0)
   step(1)

}


object niQueueTester {
  def main(args: Array[String]): Unit = {
    chiselMainTest(args, () => Module(new niQueue(4))) {
      c => new niQueueTest(c)
    }
  }
}
