package patmos
import Chisel._
import Node._

import ConstantsN._

class NiBox() extends Module {
 val io = new NiBoxIO()

 // ================================================
 //  Create ROMs
 // ================================================
 val rom0  = Module(new schniROM_0() )
 val rom1  = Module(new schniROM_1() )
 val rom2  = Module(new schniROM_2() )
 val rom3  = Module(new schniROM_3() )
 val rom4  = Module(new schniROM_4() )
 val rom5  = Module(new schniROM_5() )
 val rom6  = Module(new schniROM_6() )
 val rom7  = Module(new schniROM_7() )
 val rom8  = Module(new schniROM_8() )
 val rom9  = Module(new schniROM_9() )
 val rom10 = Module(new schniROM_10())
 val rom11 = Module(new schniROM_11())
 val rom12 = Module(new schniROM_12())
 val rom13 = Module(new schniROM_13())
 val rom14 = Module(new schniROM_14())
 val rom15 = Module(new schniROM_15())

 // ================================================
 //  Create niControllers
 // ================================================
 
val niControllers = for(i<- 0 until TOTAL_IP_NUM) yield
{
    val niC = Module(new niQueue(3))
    niC

}

 // ================================================
 //  Create ipCores
 // ================================================

val ipCores = for(i<-0 until TOTAL_IP_NUM) yield {
  val ipC = Module(new Ip())
  ipC
}

/*
// Create connection between ip ni and rom
for (i <- 0 until TOTAL_IP_NUM) {
  niControllers(i).io <> ipCores(i).io
}
//niControllers(0).io <> rom0 


 // ================================================
 //  Create routers
 // ================================================
val routers = for() yield{

}

*/
 // ================================================
 //  Connections
 // ================================================




//schedule_ni.io.dir.rdAddr <>control_ni.io.dir_rdAddr
//schedule_ni.io.dir.rdData.src <> control_ni.io.dir_rdData_src

//schedule_ni.io.dir.rdData.dst <> control_ni.io.dir_rdData_dst
//schedule_ni.io.dir.read <> control_ni.io.dir_read

//io.core_io <> control_ni.io.ipNI_io
//control_ni.io.r_lc_dout <> io.output1

}


class TestNiBox(dut: NiBox) extends Tester(dut) {

     poke(dut.io.core_io.ip_rtw,1)
     poke(dut.io.core_io.ip_din,15)
     poke(dut.io.core_io.ip_addr,5)
peek(dut.io.output1)
   step(1)
     poke(dut.io.core_io.ip_rtw,0)
peek(dut.io.output1)
  step(1)
    peek(dut.io.output1)
  step(1)  
  peek(dut.io.output1)
  step(1)
  peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

peek(dut.io.output1)
  step(1)

//expect(dut.io.up_dout.data,3)
step(1)

}

object tNiBox {
   def main(args: Array[String]): Unit = {
      chiselMainTest(args,
         () => Module(new NiBox())) {
            dut => new TestNiBox(dut)
         }
      }
   }
