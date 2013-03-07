#
# Building a Hello World Chisel without too much sbt/scala/... stuff
#
# sbt looks for default into a folder project/ for build.sdt and Build.scala
# sbt creates per default a target folder

SBT = java -Xmx1024M -Xss8M -XX:MaxPermSize=128M -jar sbt/sbt-launch.jar

MAIN=example.BlinkMain
MAIN=example.FsmMain
MAIN=s4noc.SimpNocMain

# Testing with C++ based simulator
test:
	-rm -rf generated
	$(SBT) "run-main $(MAIN) --test --compile --vcd --genHarness --targetDir generated"

# Generate Verilog
verilog:
	$(SBT) "run-main $(MAIN) --targetDir generated --backend v"
