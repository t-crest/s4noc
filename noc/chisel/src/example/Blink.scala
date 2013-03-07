/*
 * This code is part of the HDL comparison.
 * 
 * Copyright: 2013, Technical University of Denmark, DTU Compute
 * Author: Martin Schoeberl (martin@jopdesign.com)
 * License: Simplified BSD License
 * 
 * Blinking LED: the FPGA version of Hello World
 */

package example

import Chisel._
import Node._

class Blink() extends Component {
  val io = new Bundle {
    val led = UFix(OUTPUT, 1)
  }
  // BeMicro has a 16 MHz clock
  val CNT_MAX = UFix(16000000/2-1);
  val r1 = Reg(resetVal = UFix(0, 25))
  val blk = Reg(resetVal = UFix(0, 1))
  r1 := r1 + UFix(1)  
  when (r1 === CNT_MAX) {
    r1 := UFix(0)
    blk := ~blk
  }
  io.led := blk
}

// The sbt build tool passes some arguments to our main,
// which gives some arguments for the Chisel code generation

object BlinkMain {
  def main(args: Array[String]): Unit = {
    chiselMain(args, () => new Blink());
  }
}
