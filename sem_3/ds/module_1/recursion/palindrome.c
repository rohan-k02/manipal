#include<stdio.h>
#include<string.h>

int isPalindrome(char *inputString, int leftIndex, int rightIndex)
{
    if(leftIndex >= rightIndex)
        return 1;

    if(inputString[leftIndex] == inputString[rightIndex])
    {
        return isPalindrome(inputString, leftIndex + 1, rightIndex - 1);      // Recursive function call.
    }

    return 0;
}

int main()
{
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);

    if(isPalindrome(inputString, 0, strlen(inputString) - 1))
        printf("%s is a Palindrome \n", inputString);

    else 
        printf("%s is not a Palindrome \n", inputString);

    return 0;
}

