/* Write an ARM assembly language program to transfer block of ten 32-bit
numbers from code memory to data memory when the source and destination
blocks are non-overlapping. (byte-by-byte) */

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
	LDR R0, =SRC
	LDR R1, =DST
	LDR R2, =COUNT
	
LOOP
	LDRB R3,[R0], #1
	STRB R3, [R1], #1
	
	SUB R2, #1
	BNE LOOP
	
STOP
	B STOP
SRC DCB 1,2,3,4,5,6,7,8,9,10
COUNT EQU 10
	
	AREA mydata, DATA, READWRITE
DST DCD 0
	END

