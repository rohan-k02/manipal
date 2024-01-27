/* Write a program for computing ⌊√n ⌋ for any positive integer and analyze its time
efficiency. Besides assignment and comparison, your program may only use the
four basic arithmetic operations. */

#include<stdio.h>

void main()
{
    int num;
    float sqrt, temp;

    printf (" Enter a number to get the square root: ");  
    scanf (" %d", &num);  

    sqrt = num/2;
    temp = 0;

    while(temp!=sqrt)
    {
        temp = sqrt; // assign sqrt to temp    
        sqrt = ( num / temp + temp) / 2;  
    }
}