/* Q3. Write a program to implement solution to partition problem using brute-force
technique and analyze its time efficiency theoretically. A partition problem takes
a set of numbers and finds two disjoint sets such that the sum of the elements in
the first set is equal to the second set. [Hint: You may generate power set] */

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n, i, sum = 0, completed = 0, r;

    printf("Enter length of array: ");
    scanf("%d",&n);
    r = n / 2;
    int* arr = (int*) malloc(n * sizeof(int));
    int* data = (int*) malloc(r * sizeof(int));
    
    for(i = 0; i < n; i++)
    {
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    if (sum % 2 != 0)
        printf("Not possible.\n");

     else
     {
        for (i = 1; i <= r; i++) 
        {
            getNCR(arr, data, 0, n - 1, 0, i, sum/2, &completed);
        }
        
        if (!completed)
            printf("Not possible.\n");
    }
}