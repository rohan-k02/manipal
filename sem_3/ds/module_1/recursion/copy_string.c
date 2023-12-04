#include<stdio.h>

void copy(char str1[], char str2[], int index)
{
    str2[index] = str1[index];

    if (str1[index] == '\0')
        return;
        
    copy(str1, str2, index + 1);
}

void main()
{
    char str1[10], str2[10];

    printf("Enter a string: ");
    gets(str1);

    copy(str1, str2, 0);

    printf("String copied: %s", str2);
}