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
	load 32
	out 255
	in 1
	in 1
	out 255
	in 2
	in 2
	out 255
	in 3
	in 3
	out 255
	in 4
	in 4
	out 255
	in 5
	in 5
	out 255
	in 6
	in 6
	out 255
	in 7
	in 7
	out 255
	in 8
	in 8
	out 255
	in 9
	in 9
	out 255
	in 10
	in 10
	out 255
	in 11
	in 11
	out 255
	in 12
	in 12
	out 255
	in 13
	in 13
	out 255
	in 14
	in 14
	out 255
complete:
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
	nop // The core has received the core ID from all other cores
	nop
	in 253
	sub 1
	brz H
	nop
	nop
	sub 1
	brz E
	nop
	nop
	sub 1
	brz L
	nop
	nop
	sub 1
	brz L
	nop
	nop
	sub 1
	brz O
	nop
	nop
	sub 1
	brz space
	nop
	nop
	sub 1
	brz T
	nop
	nop
	sub 1
	brz dash
	nop
	nop
	sub 1
	brz C
	nop
	nop
	sub 1
	brz R
	nop
	nop
	sub 1
	brz E
	nop
	nop
	sub 1
	brz S
	nop
	nop
	sub 1
	brz T
	nop
	nop
	sub 1
	brz exclamation
	nop
	nop	
	load 31
	out 0
	nop
	nop
H:
	load 72
	out 0
	branch die
	nop
	nop
E:
	load 69
	out 0
	branch die
	nop
	nop
L:
	load 76
	out 0
	branch die
	nop
	nop
O:
	load 79
	out 0
	branch die
	nop
	nop
space:
	load 32
	out 0
	branch die
	nop
	nop
T:
	load 84
	out 0
	branch die
	nop
	nop
dash:
	load 45
	out 0
	branch die
	nop
	nop
C:
	load 67
	out 0
	branch die
	nop
	nop
R:
	load 82
	out 0
	branch die
	nop
	nop
S:
	load 83
	out 0
	branch die
	nop
	nop
T:
	load 84
	out 0
	branch die
	nop
	nop
exclamation:
	load 33
	out 0
die:	
	nop
	nop
	branch die
	nop
	nop
	