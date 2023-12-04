#include<stdio.h>

int fib(int n)
{
	if(n==0)
		return 0;

	if(n==1)
		return 1;

	else
		return (fib(n-1) + fib(n-2));
}

void main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The %dth fibonacci number is is %d", n, fib(n));
}