/*
 * Authors: Constantina Ioannou
 *
 */
package patmos
import Chisel._
import Node._

import ConstantsN._

class schniROM_7() extends Module {
  val io = new niRomIO()

  	val id = Vec(Array( new nav(UInt(7),UInt(7)), new nav(UInt(1),UInt(7)), new  nav(UInt(12),UInt(7)),
					 new nav(UInt(14),UInt(2)), new nav(UInt(7),UInt(13)), new  nav(UInt(9),UInt(7)),
					 new nav(UInt(3),UInt(9)), new nav(UInt(0),UInt(14)), new  nav(UInt(2),UInt(12)),
					 new nav(UInt(15),UInt(11)), new nav(UInt(5),UInt(1)), new  nav(UInt(10),UInt(10)),
					 new nav(UInt(7),UInt(8)), new nav(UInt(4),UInt(15)), new  nav(UInt(11),UInt(5)),
					 new nav(UInt(6),UInt(0)), new nav(UInt(7),UInt(6)), new  nav(UInt(13),UInt(3)),
					 new nav(UInt(8),UInt(4))))

val rdAddrReg = Reg(next = io.dir.rdAddr)

 io.dir.rdData := new nav(UInt(7),UInt(7))

  	 for( i <- 0 until 19 )
        {
        	when (UInt(i) === rdAddrReg && io.dir.read === Bool(true)){
	           io.dir.rdData := id(i)
	       }
        }
}

class schniROM_7Test(dut: schniROM_7) extends Tester(dut) {

	poke(dut.io.dir.rdAddr,5)
	poke(dut.io.dir.read,0)
	peek(dut.io.dir.rdData)
	step(1)

	poke(dut.io.dir.read,1)
	peek(dut.io.dir.rdData)
	step(1)

	poke(dut.io.dir.read,0)
	peek(dut.io.dir.rdData)
	step(1)
}


object schniROM_7Tester {
  def main(args: Array[String]): Unit = {
    chiselMainTest(args,
      () => Module(new schniROM_7())) {
        dut => new schniROM_7Test(dut)
      }
  }
}

		