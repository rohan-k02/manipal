#include <stdio.h>

#define MAX 3

typedef struct 
{
    int value;
} STACK;

STACK s1[MAX];
int top = -1;

void push(int val)
{
    if(top == MAX - 1)
    {
        printf("\n STACK OVERFLOW");
    }

    else
    {
        s1[++top].value = val;
    }
}

int pop()
{
    int val;
    if(top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }

    else
    {
        return s1[top--].value;
    }
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("\n STACK IS EMPTY");
    }

    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n %d",s1[i].value);
        }
    }
}

int peek()
{
    if(top == -1)
    {
        printf("\n STACK IS EMPTY");
        return -1;
    }

    else
    {
        return (s1[top].value);
    }
}


int main()
{
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                val = pop();
                if(val != -1)
                    printf("\n The value deleted from stack is: %d", val);
                break;

            case 3:
                val = peek();
                if(val != -1)
                    printf("\n The value stored at top of stack is: %d", val);
                break;

            case 4:
                display();
                break;
        }
    }while(option != 5);
}