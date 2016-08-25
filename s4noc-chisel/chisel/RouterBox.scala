package patmos
import Chisel._
import Node._

import ConstantsN._

class RouterBox() extends Module {
 val io = new RouterBoxIO()

 val schedule_table = Module(new schtab())
 val route = Module (new router() )



 schedule_table.io.dir <> route.io.routeInfo

 route.io.lc_din <> io.lc_din
 route.io.dn_din <> io.dn_din
 route.io.up_din <> io.up_din
 route.io.le_din <> io.le_din
 route.io.r_din <> io.r_din


 route.io.lc_dout <> io.lc_dout
 route.io.dn_dout <> io.dn_dout
 route.io.up_dout <> io.up_dout
 route.io.le_dout <> io.le_dout
 route.io.r_dout <> io.r_dout
 

}
class TestRouterBox(dut: RouterBox) extends Tester(dut) {
poke(dut.io.up_din.data,3)
poke(dut.io.dn_din.data,4)
poke(dut.io.r_din.data,5)
poke(dut.io.le_din.data,6)
poke(dut.io.lc_din.data,7)

//expect(dut.io.up_dout.data,3)
step(1)

}

object tRouterBox {
   def main(args: Array[String]): Unit = {
      chiselMainTest(args,
         () => Module(new RouterBox())) {
            dut => new TestRouterBox(dut)
         }
      }
   }
