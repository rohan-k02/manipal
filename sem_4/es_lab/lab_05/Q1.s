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

main:
    @ Initialize variables
    LDR R0, =ARR            @ Load the address of the array into r0
    ADD R1, = ARR_SIZE      @ Load the number of elements in the array into r1  
    MLA R2, R1, #4, R0      @ Load the address of the end of the array into r2
    SUB R2, R2, #4          @ Adjust r2 to point to the last element of the array

outer_loop:
    CMP R1, #1              @ Check if there's only one element left in the array
    BLE END_SORT            @ If so, the array is sorted, jump to the end

    MOV R4, R0              @ Move the address of the current minimum element into r4
    MOV R5, R0              @ Move the address of the current element into r5
    @ mov r6, r3            @ Move the size of an integer into r6

inner_loop:
    CMP R5, R2              @ Check if we've reached the end of the array
    BGE UPDATE_MIN          @ If so, update the minimum element and move to the next iteration of outer loop

    LDR R7, [R5]            @ Load the current element into r7
    LDR R8, [R4]            @ Load the current minimum element into r8
    CMP R7, R8              @ Compare the current element with the current minimum
    BGE UPDATE_MIN          @ If the current element is greater or equal, update the minimum element

    mov r4, r5           @ Update the address of the minimum element

update_min:
    ADD r5, r5, r6       @ Move to the next element in the array
    b inner_loop         @ Continue the inner loop

end_sort:
    bx lr                @ Return from subroutine

STOP B STOP
ARR_SIZE DCD 5

	AREA mydata, DATA, READWRITE
ARR DCD 4, 2, 5, 1, 3

	END