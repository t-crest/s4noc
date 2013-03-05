/*
 * TODO: copyright info.
 * 
 */
package tools

import scala.io.Source
import scala.collection.mutable.Map

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
 * Or we keep it simple with dots: ".x" is injection and "x." is receive.
 *
 * The mux selection is defined by the combination of two letters.
 * E.g. '.w' is the injection to the west write port,
 * 'es' is a packet that was former output at a west port and comes in
 * east routed to the south port (south port mux set to east).
 */
object GenSchedule {

  // use a map:
  // "xy", (destination port (y), mux selection (x)
  // east in comes from west, south in from north, and vica verse
  val routeMap = Map(
      "s." -> (0, 0), // north input of local (port 0)
      "e." -> (0, 1), // west input of local (port 0
      "n." -> (0, 2), // south input
      "w." -> (0, 3), // east input
      "en" -> (1, 0), // west input of north port
      "nn" -> (1, 1), // south input of north port
      "wn" -> (1, 2), // east input of north port
      ".n" -> (1, 3), // local input of north port
      "nw" -> (2, 0), // south in
      "ww" -> (2, 1), // east in
      ".w" -> (2, 2), // local in
      "sw" -> (2, 3), // north in
      "ws" -> (3, 0), // east in
      ".s" -> (3, 1), // local in
      "ss" -> (3, 2), // north in
      "es" -> (3, 3), // west in
      ".e" -> (4, 0), // local in
      "se" -> (4, 1), // north in
      "ee" -> (4, 2), // west in
      "ne" -> (4, 3) // south in
  )
  
  
  def readFile(file: String) {
    val lines = Source.fromFile(file).getLines().toList
    var schedLen = 0
    for (line <- lines)
      schedLen = schedLen.max(line.length)
    schedLen += 1
    println("Schedule length: " + schedLen)
    println("Number of lines: " + lines.length)
    val schedStrings = new Array[String](lines.length)
    var i = 0
    for (line <- lines) {
      val len = line.length + 1
      val tr = line.trim
      val s = "." * (len - tr.length) + tr + "." * (schedLen + 1 - len)
      schedStrings(i) = s
      i += 1
    }

    // Debug print
    for (s <- schedStrings)
      println(s)

    // How do we multidimensional arrays in Scala?
    val ports = new Array[Array[Array[Int]]](5) // 5 ports
    for (i <- 0 until ports.length) {
      // no muxes needed!! it is a two dimensional array ports/schedule
      val muxIn = new Array[Array[Int]](4) // 4 mux inputs
      ports(i) = muxIn
      for (j <- 0 until muxIn.length) {
        val shd = new Array[Int](schedLen)
        muxIn(j) = shd
        for (k <- 0 until shd.length)
          shd(k) = -1 // unused value for checking
      }
    }
    
    // Debug printout
    for (i <- 0 until schedLen) {
      print("Cycle " + i + " : ")
      for (s <- schedStrings) {
        val pat = s.substring(i, i + 2)
        print(pat + " ")
      }
      println()
    }

    // ports(ports)(muxes)(schedule index)
    // now find the patterns
    // Debug printout
    for (i <- 0 until schedLen) {
      print("Cycle " + i + " : ")
      for (s <- schedStrings) {
        val pat = s.substring(i, i + 2)
        print(pat + " ")
        if (routeMap.contains(pat)) {
          val (port, input) = routeMap(pat)
          if (ports(port)(input)(i)!= -1) {
            throw new Exception(port + " " + input + " at cycle " + i + " in use!")
          } else {
            ports(port)(input)(i) = 1
          }
          print(port + " " + input)      
        }
      }
      println()
    }

    // initial file print version
    var max = 0
    for (line <- Source.fromFile(file).getLines()) {
      max = line.length
      println(line.length + " " + line)
    }
    println("Max schedule: " + (max + 1))
  }

  def main(args: Array[String]): Unit = {
    println("Hello Scala")
    val N = 3
    readFile("/Users/martin/t-crest/s4noc/noc/vhdl/generated/bt" + N + "x" + N + "/bt" + N + "x" + N + ".shd")
  }

}