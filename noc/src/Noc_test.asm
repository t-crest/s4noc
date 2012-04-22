// Muvium Leros AOT Compiler
// Java Source: Noc_test
// first instruction is not executed
	nop // 
// second instruction is executed twice
// ******************************************************
// MEMORY MODEL
// ******************************************************
// Static Fields R5 to R24
// FRAME ROOT
// Local Refs R25 to R29
// Local Lits R30 to R49
// Operand Stack R50 to R65
// FRAME METHODCALL
// Local Refs R66 to R70
// Local Lits R71 to R90
// Operand Stack R91 to R106
// ******************************************************
// run()
	branch run
Start:
run:
	nop
	nop
	in 253
	out 0
	nop
	add 66
	out 255
	nop
	nop
die:	
	nop
	nop
	branch die
	nop
	nop
	
loop:
	in 254
	sub 2
	nop
	nop
	brnz loop
	nop
	nop
	in 17
	and 127
	sub 62
	nop
	out 255
	nop
	nop
	branch loop
	nop
	nop
	