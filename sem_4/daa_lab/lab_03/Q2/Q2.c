/* Q2. Write a program to implement brute-force string matching. Analyze its time efficiency*/

#include<stdio.h>
#include<string.h>


void main()
{
    int l_str, l_substr, i, index, count = 0;
    char str[50], substr[50];

    printf("Enter the string: ");
    gets(str);
    l_str = strlen(str);

    printf("Enter the substring to find: ");
    gets(substr);
    l_substr = strlen(substr);

    for(i = 0; i < l_str - l_substr + 1; i++)
    {
        for(index = 0; index < l_substr; index++)
        {
            if(substr[index] != str[i+index])
            {
                count++;
                break;
            }
        }

        if(index == l_substr)
        {
            count++;
            break;
        }
    }

    if(index == l_substr)
    {
        printf("Substring found at index %d. Count: %d", i, count);
    }

    else
    {
        printf("Substring not found. Count: %d", count);
    }
}