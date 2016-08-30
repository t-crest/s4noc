/*
 * Authors: Constantina Ioannou
 *
 */
package patmos
import Chisel._
import Node._

import ConstantsN._


class routeDir() extends Bundle(){
   val up = Bits( width = 3)
   val right = Bits( width = 3 )
   val down = Bits( width = 3 )
   val left = Bits( width = 3 )
   val local = Bits( width = 3 )
   val dc = Bits( width = 3 )

    override def clone() = {
      val res = new routeDir()
      res.asInstanceOf[this.type]
    }
}
class nav(d:UInt, s:UInt) extends Bundle(){
   val src = UInt(width =ADDRESS_WIDTH)
   val dst = UInt(width =ADDRESS_WIDTH)
   src:= s
   dst:= d
    override def clone() = {
      val res = new nav(s,d)
      res.asInstanceOf[this.type]
    }
}
class phit() extends Bundle() {
   val data = Bits(width=DATA_WIDTH)
   val valid = Bool()

   override def clone() = {
      val res = new phit()
      res.asInstanceOf[this.type]
    }

}

class routerSchTab extends Bundle(){
	val slotCounter = UInt(INPUT, TOTAL_IP_NUM)
    val rInfo = new routeDir().asOutput
}

class schtabIO() extends Bundle() {
  val dir = new routerSchTab()

}

class routerIO() extends Bundle() {
 
   val ena = Bool(INPUT)
   val routeInfo = new routerSchTab().flip()
 
// =======================================
//    Signals to/from NI
// =======================================  
   val lc_din =new phit().asInput
   val lc_dout = new phit().asOutput
 

   val addr= Bits(INPUT, DATA_WIDTH)
   val qFull = Bool(INPUT)
   val test = Bits(OUTPUT,DATA_WIDTH)


   val ready = Bool(OUTPUT)
// =======================================
//    Signals to other routers 
// =======================================
   val r_din = new phit().asInput
   val r_dout = new phit().asOutput

   val le_din  = new phit().asInput
   val le_dout = new phit().asOutput


   val up_din = new phit().asInput
   val up_dout = new phit().asOutput

   val dn_din = new phit().asInput
   val dn_dout = new phit().asOutput


}


class schniNI() extends Bundle(){
  val rdAddr = Bits(INPUT, TOTAL_NI_SLOT_NUM)
  val rdData = new nav(UInt(0),UInt(0)).asOutput
  val read = Bool(INPUT)

}
class niRomIO() extends Bundle(){
  val dir = new schniNI()
}

class ipNI() extends Bundle(){
  val ip_din = Bits(INPUT, DATA_WIDTH)
  val router_tx = Bool(INPUT)
  val ip_rtw = Bool(INPUT)
  val ip_ack = Bool(OUTPUT)
  val ip_addr = Bits(INPUT, ADDRESS_WIDTH)
  val ip_qtBusy = Bool(OUTPUT)
  val ip_dout = Bits(OUTPUT, DATA_WIDTH)

}
class niIO() extends Bundle(){
// =======================================
//    NI - ROUTER
// =======================================

//receive channel 
   val r_lc_din_ =new phit().asInput

//transmit channel
   val r_lc_dout = new phit().asOutput

// =======================================
//    NI - PROCESSOR
// =======================================
//receive
val ipNI_io = new ipNI()
//transmit


// =======================================
//    NI - NI - SCHEDULE
// =======================================
val dir_rdAddr = Bits(OUTPUT, TOTAL_NI_SLOT_NUM)
val dir_rdData_src = UInt(INPUT,ADDRESS_WIDTH)
val dir_rdData_dst = UInt(INPUT,ADDRESS_WIDTH)
val dir_read = Bool(OUTPUT)


}

class NiBoxIO() extends Bundle(){
  /* change when i create the core*/
  val core_io = new ipNI()

   val output1 = new phit().asOutput
}



class RouterBoxIO() extends Bundle(){

   val lc_din =new phit().asInput
   val lc_dout = new phit().asOutput


   val r_din = new phit().asInput
   val r_dout = new phit().asOutput

   val le_din  = new phit().asInput
   val le_dout = new phit().asOutput


   val up_din = new phit().asInput
   val up_dout = new phit().asOutput

   val dn_din = new phit().asInput
   val dn_dout = new phit().asOutput


}

class ipIO() extends Bundle(){

  val led1 = UInt(OUTPUT, 1)

  val led2 = UInt(OUTPUT, 1)

  val ipNI_io = new ipNI().flip

}


