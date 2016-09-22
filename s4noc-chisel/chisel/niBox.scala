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

*/
 // ================================================
 //  Create routers
 // ================================================
val routers = for(i<- 0 until TOTAL_IP_NUM) yield{
  val rC = Module(new RouterBox())
	rC
}

 // ================================================
 //  Connections niCOntroller to ROMs
 // ================================================

niControllers(0).io.dir_rdAddr <> rom0.io.dir.rdAddr
niControllers(0).io.dir_rdData_src <> rom0.io.dir.rdData.src
niControllers(0).io.dir_rdData_dst <> rom0.io.dir.rdData.dst
niControllers(0).io.dir_read <> rom0.io.dir.read

niControllers(1).io.dir_rdAddr <> rom1.io.dir.rdAddr
niControllers(1).io.dir_rdData_src <> rom1.io.dir.rdData.src
niControllers(1).io.dir_rdData_dst <> rom1.io.dir.rdData.dst
niControllers(1).io.dir_read <> rom1.io.dir.read

niControllers(2).io.dir_rdAddr <> rom2.io.dir.rdAddr
niControllers(2).io.dir_rdData_src <> rom2.io.dir.rdData.src
niControllers(2).io.dir_rdData_dst <> rom2.io.dir.rdData.dst
niControllers(2).io.dir_read <> rom2.io.dir.read

niControllers(3).io.dir_rdAddr <> rom3.io.dir.rdAddr
niControllers(3).io.dir_rdData_src <> rom3.io.dir.rdData.src
niControllers(3).io.dir_rdData_dst <> rom3.io.dir.rdData.dst
niControllers(3).io.dir_read <> rom3.io.dir.read

niControllers(4).io.dir_rdAddr <> rom4.io.dir.rdAddr
niControllers(4).io.dir_rdData_src <> rom4.io.dir.rdData.src
niControllers(4).io.dir_rdData_dst <> rom4.io.dir.rdData.dst
niControllers(4).io.dir_read <> rom4.io.dir.read

niControllers(5).io.dir_rdAddr <> rom5.io.dir.rdAddr
niControllers(5).io.dir_rdData_src <> rom5.io.dir.rdData.src
niControllers(5).io.dir_rdData_dst <> rom5.io.dir.rdData.dst
niControllers(5).io.dir_read <> rom5.io.dir.read

niControllers(6).io.dir_rdAddr <> rom6.io.dir.rdAddr
niControllers(6).io.dir_rdData_src <> rom6.io.dir.rdData.src
niControllers(6).io.dir_rdData_dst <> rom6.io.dir.rdData.dst
niControllers(6).io.dir_read <> rom6.io.dir.read

niControllers(7).io.dir_rdAddr <> rom7.io.dir.rdAddr
niControllers(7).io.dir_rdData_src <> rom7.io.dir.rdData.src
niControllers(7).io.dir_rdData_dst <> rom7.io.dir.rdData.dst
niControllers(7).io.dir_read <> rom7.io.dir.read

niControllers(8).io.dir_rdAddr <> rom8.io.dir.rdAddr
niControllers(8).io.dir_rdData_src <> rom8.io.dir.rdData.src
niControllers(8).io.dir_rdData_dst <> rom8.io.dir.rdData.dst
niControllers(8).io.dir_read <> rom8.io.dir.read

niControllers(9).io.dir_rdAddr <> rom9.io.dir.rdAddr
niControllers(9).io.dir_rdData_src <> rom9.io.dir.rdData.src
niControllers(9).io.dir_rdData_dst <> rom9.io.dir.rdData.dst
niControllers(9).io.dir_read <> rom9.io.dir.read

niControllers(10).io.dir_rdAddr <> rom10.io.dir.rdAddr
niControllers(10).io.dir_rdData_src <> rom10.io.dir.rdData.src
niControllers(10).io.dir_rdData_dst <> rom10.io.dir.rdData.dst
niControllers(10).io.dir_read <> rom10.io.dir.read


niControllers(11).io.dir_rdAddr <> rom11.io.dir.rdAddr
niControllers(11).io.dir_rdData_src <> rom11.io.dir.rdData.src
niControllers(11).io.dir_rdData_dst <> rom11.io.dir.rdData.dst
niControllers(11).io.dir_read <> rom11.io.dir.read

niControllers(12).io.dir_rdAddr <> rom12.io.dir.rdAddr
niControllers(12).io.dir_rdData_src <> rom12.io.dir.rdData.src
niControllers(12).io.dir_rdData_dst <> rom12.io.dir.rdData.dst
niControllers(12).io.dir_read <> rom12.io.dir.read


niControllers(13).io.dir_rdAddr <> rom13.io.dir.rdAddr
niControllers(13).io.dir_rdData_src <> rom13.io.dir.rdData.src
niControllers(13).io.dir_rdData_dst <> rom13.io.dir.rdData.dst
niControllers(13).io.dir_read <> rom13.io.dir.read


niControllers(14).io.dir_rdAddr <> rom14.io.dir.rdAddr
niControllers(14).io.dir_rdData_src <> rom14.io.dir.rdData.src
niControllers(14).io.dir_rdData_dst <> rom14.io.dir.rdData.dst
niControllers(14).io.dir_read <> rom14.io.dir.read


niControllers(15).io.dir_rdAddr <> rom15.io.dir.rdAddr
niControllers(15).io.dir_rdData_src <> rom15.io.dir.rdData.src
niControllers(15).io.dir_rdData_dst <> rom15.io.dir.rdData.dst
niControllers(15).io.dir_read <> rom15.io.dir.read

// each ipCore must connect to each ni_controller
/*
for (i<-0 until TOTAL_IP_NUM){
  ipCores(i).io.ipNI_io <> niControllers(i).io.ipNI_io
}*/

// ======
// connecting one core inputs on niController(0) for testing
// ======
niControllers(0).io.r_lc_dout <> io.output1
io.core_io <> niControllers(0).io.ipNI_io

}


class TestNiBox(dut: NiBox) extends Tester(dut) {

     poke(dut.io.core_io.ip_rtw,1)
     poke(dut.io.core_io.ip_din,15)
     poke(dut.io.core_io.ip_addr,14)
peek(dut.io.output1)
   step(1)
     poke(dut.io.core_io.ip_rtw,0)
peek(dut.io.output1)
step(50)

}

object tNiBox {
   def main(args: Array[String]): Unit = {
      chiselMainTest(args,
         () => Module(new NiBox())) {
            dut => new TestNiBox(dut)
         }
      }
   }
