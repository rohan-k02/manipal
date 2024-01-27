/* Q4. Find the sum of ‘n’ natural numbers using MLA instruction. */


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

    LDR R0, =N
    LDR R1, [R0]
    LDR R0, =SUM

    MLA R1,R1,R1,R1 ;n^2 + n
	LSR R1,#1 ; dividing by 2 to get (n^2 + n)/2
	
	STR R1,[R0]

N DCD 5;
	AREA mydata, DATA, READWRITE
SUM DCD 0;
	END