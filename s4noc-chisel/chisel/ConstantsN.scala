/*
 * Authors: Constantina Ioannou
 *
 */
package patmos
import Chisel._
import Node._

object ConstantsN {

  val DATA_WIDTH    = 32
  val ADDRESS_WIDTH =  4
  val PORTS_NUM = 6

/*  constant TILE_CLK_FREQ  : positive := 100000000; */
 val TOTAL_IP_NUM  = 16
 val TOTAL_NI_SLOT_NUM = 20 // 5 bits 
 val TOTAL_NI_NUM = 4 // 4bits 
 val TDM_PERIOD   = 19

// =================
// test values for ip cores
// =================
val TEST_VALUE_1 = 5
val TEST_VALUE_2 = 7

 val D = Bits("b000")   
 val L = Bits("b001")   
 val S = Bits("b010")   
 val W = Bits("b011")   
 val E = Bits("b100")   
 val N = Bits("b101")   

  //constant DUAL_CLOCK_NOC : boolean  := false;

}
