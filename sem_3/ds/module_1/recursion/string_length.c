#include<stdio.h>

int strlength(char str[], int index)
{
    if (str[index] == '\0')
        return 0;

    return (1 + strlength(str, index + 1));
}


void main()
{
    char arr[5];
    int length;

    printf("Enter a string: ");
    gets(arr);

    printf("Length of the string is: %d", strlength(arr, 0));
}