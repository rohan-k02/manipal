#include<stdio.h>

int mul(int m, int n) 
{
	if(m==0 || n==0)
		return 0;

	if(n==1)
		return m;
	else 
        return m + mul(m, n-1);
}

void main()
{
    int m, n, product;

    printf("Enter the first number: ");
    scanf("%d", &m);

    printf("Enter the second number: ");
    scanf("%d", &n);

    printf("The product is %d", mul(m,n));
}