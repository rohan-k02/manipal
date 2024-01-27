/* Q2. Write an assembly program to multiply two 32-bit numbers. */

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
	LDR R1, [R0]
	LDR R0, =SRC2
	LDR R2, [R0]
	LDR R3, =DST
	UMULL R4, R5, R1, R2
	STR R4, [R3],#4
	STR R5, [R3]
STOP
	B STOP
SRC1 DCD 0x00011111
SRC2 DCD 0x33445566   
	AREA mydata, DATA, READWRITE
DST DCD 0 ;DST location in data memory
	END