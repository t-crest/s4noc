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
	// Read core ID
	in 253
	nop
	nop
	brnz ncz
	nop
	nop
	// Core zero
cz:
	in 17 // Read the receive register
	nop
	add 1 // If the receive register has the desired value the result of the addition should be zero
	nop
	brnz cz
	nop
	nop
complete:
	load 65
	out 255
	nop
	nop
	branch complete
	nop
	nop
	
	
ncz:
	// All other cores than core zero
	// Writes their core ID to all other cores than core zero
	out 1
	out 2
	out 3
	out 4
	out 5
	out 6
	out 7
	out 8
	out 9
	out 10
	out 11
	out 12
	out 13
	out 14
	out 15
	nop
	nop
wait:
	nop
	in 17 // Read the Receive register
	nop
	add 2 // If the receive register has the desired value the result of the addition should be zero
	nop
	brnz wait
	nop
	nop
	load 31
	out 0
	nop
	nop
die:	
	nop
	nop
	branch die
	nop
	nop
	