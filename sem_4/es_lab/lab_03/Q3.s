/* Q3. Write an assembly language program to implement division by repetitive
subtraction. */

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

	LDR R0, =DIVIDEND
	LDR R1, [R0]
	LDR R0, =DIVISOR
	LDR R2, [R0]
	
	MOV R3, #0
DIV_BY_SUB	

	CMP R1, R2
	BCC END
	SUB R1, R1, R2      ; Subtract divisor from dividend
    ADD R3, R3, #1      ; Increment quotient
	B DIV_BY_SUB
	
END
	LDR R0, =QUO
	STR R3, [R0]
	
	LDR R0, =REM
	STR R1, [R0]
STOP
	B STOP

DIVIDEND DCD 10
DIVISOR DCD 3   
	AREA mydata, DATA, READWRITE
QUO DCD 0 ;DST location in data memory
REM DCD 0 
	END