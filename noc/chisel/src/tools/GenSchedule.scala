/*
 * TODO: copyright info.
 * 
 */
package tools

import scala.io.Source

/**
 * Generation of schedule table for the S4NOC multiplexers.
 * 
 * We define the ports as starting with local at index 0.
 * Continue with 1 north, 2 west, 3 south, and 4 east.
 * 
 * Each output register is connected to a 4:1 multiplexer.
 * The inputs are in increasing order according to the port index.
 * E.g. north MUX input indexes: 0 west, 1 south, 2 east, 3 local.
 * 
 * The schedule is given by link directions (nwse). E.g. nne means:
 * 1) from local to north port
 * 2) from south port to north port (former north destination becomes new south source)
 * 3) from south port to east port
 * 4) from west port to local
 * 
 * We add 'i' and 'r' for inject and receive to the schedule string.
 * 
 * The mux selection is defined by the combination of two letters.
 * E.g. 'iw' is the injection to the west write port,
 * 'es' is a packet that was former output at a west port and comes in
 * east routed to the south port (south port mux set to east).
 */
object GenSchedule {

  def readFile(file: String) {
    var max = 0
    for (line <- Source.fromFile(file).getLines()) {
      max = line.length
      println(line.length + " " + line)
    }
    println("Max schedule:"+(max+2))
  }

  def main(args: Array[String]): Unit = {
    println("Hello Scala")
    val N = 3
    readFile("/Users/martin/t-crest/s4noc/noc/vhdl/generated/bt"+N+"x"+N+"/bt"+N+"x"+N+".shd")
  }

}