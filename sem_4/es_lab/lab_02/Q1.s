/* Write an ARM assembly language program to store data into general purpose
registers. */

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
	LDR R0, =SRC1;
	LDR R1, =SRC2;
	LDR R2, [R0];
	LDR R3, [R1];	
STOP
	B STOP;
	AREA mydata, DATA, READONLY
SRC1 DCD 48;
SRC2 DCD 65;
	END