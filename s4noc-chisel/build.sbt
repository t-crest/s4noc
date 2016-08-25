scalaVersion := "2.11.7"

libraryDependencies += "edu.berkeley.cs" %% "chisel" % "latest.release"

scalaSource in Compile <<= baseDirectory(_ / "chisel")
