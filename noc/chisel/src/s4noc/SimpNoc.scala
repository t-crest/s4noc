/*
   Copyright 2013 Technical University of Denmark, DTU Compute. 
   All rights reserved.
   
   This file is part of the time-predictable network-on-chip S4NoC.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

      1. Redistributions of source code must retain the above copyright notice,
         this list of conditions and the following disclaimer.

      2. Redistributions in binary form must reproduce the above copyright
         notice, this list of conditions and the following disclaimer in the
         documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER ``AS IS'' AND ANY EXPRESS
   OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
   OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
   NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
   THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   The views and conclusions contained in the software and documentation are
   those of the authors and should not be interpreted as representing official
   policies, either expressed or implied, of the copyright holder.
 */

/*
 * S4NoC top level component and test driver.
 * 
 * Author: Martin Schoeberl (martin@jopdesign.com)
 * 
 */

package s4noc

import Chisel._
import Node._

import scala.collection.mutable.HashMap

class SimpNoc() extends Component {
  val io = new Bundle {
    val led = Bits(OUTPUT, 8)
  }
  
  var tck = new Tick();
  
  val led = Reg(resetVal = Bits(1, 8))
  val led_next = Cat(led(6, 0), led(7))
  
  when (tck.io.tick === Bits(1)) {
    led := led_next
  }
  io.led := ~led
}

/**
 * Generate a 2 Hz tick to drive the FSM input test bench.
 */
class Tick() extends Component {
  val io = new Bundle {
    val tick = Bits(OUTPUT, 1)
  }
  // BeMicro has a 16 MHz clock
  val CNT_MAX = UFix(16000000/2-1)
  
  val r1 = Reg(resetVal = UFix(0, 25))
  
  val limit = r1 === CNT_MAX
  val tick = limit
  
  r1 := r1 + UFix(1)
  when (limit) {
    r1 := UFix(0)
  }
  
  io.tick := tick
}

class SimpNocTest(s4noc: SimpNoc) extends Tester(s4noc, Array(s4noc.io)) {
  defTests {
    val ret = true
    val vars = new HashMap[Node, Node]()
    val ovars = new HashMap[Node, Node]()

    for (i <- 0 until 10) {
      vars.clear
      step(vars, ovars)
      println("iter: "+i)
      println("ovars: "+ovars)
      println("led/litVal "+ovars(c.io.led).litValue())
    }
    ret
  }
}

object SimpNocMain {
  def main(args: Array[String]): Unit = {
    chiselMainTest(args, () => new SimpNoc()) {
      f => new SimpNocTest(f)
    }

  }
}
