/* Q1. Write a program to perform subtraction operation on two 32-bit numbers
available in the code memory. Store the result in the data memory */

	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler

	LDR R0, =SRC1
	LDR R1, =SRC2
	LDR R2, =DST
	LDR R3, [R0]
	LDR R4, [R1]
	SUB R5, R3, R4
	STR R5, [R2]
STOP
	B STOP
SRC1 DCD 9
SRC2 DCD 3 
	AREA mydata, DATA, READWRITE
DST DCD 0 ;DST location in data memory
	END