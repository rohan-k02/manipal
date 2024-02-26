/* Write an assembly program to sort an array using selection sort */

	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler

    LDR R0, =ARR
    LDR R1, =ARR_SIZE
    LDR R2, [R1]        @ Load the size of the array
    MOV R3, #0          @ Counter for the first loop
    MOV R1, R0

LOOP_1
    CMP R3, R2
    BGE STOP

    LDR R4, R1, #4    @ Load the value of the minimum element
    ADD R5, R3, #1      @ Update the value of loop_2 counter (j=i+1)
    LDR R6, R1          @ Pointer to arr[j]
    ADD R3, #1          @ Increment the loop_1 counter


LOOP_2
    CMP R5, R2
    BGE LOOP_1

    LDR R7, [R6]
    CMP R7, R4
    BLT UPDATE_MIN

    ADD R6, R6, #1
    ADD R5, R5, #1
    B LOOP_2

UPDATE_MIN
    R4 

    ADD R5, R5, #1
    ADD R6, R6, #1
    B LOOP_2


ARR_SIZE DCD 5
STOP B STOP

    AREA mydata, DATA, READWRITE
ARR DCD 5,4,3,2,1
END


REGISTERS
R0 -> ARR
R1 -> ARR
R2 -> value of ARR_SIZE
R3 -> counter for loop 1
R4 -> Minimum element
R5 -> Counter of loop_2
R6 -> pointer to the  Current element being compared
R7 - > value of the current element