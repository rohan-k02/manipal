#include <stdio.h>
#include<stdlib.h>

typedef struct 
{
    int value;
} STACK;


void stack_full(STACK* s1, int* capacity)
{
    *capacity = (*capacity)*2;
    s1 = (STACK*) realloc(s1, (*capacity)*sizeof(STACK));
}

void push(STACK* s1, int* top, int* capacity, int val)
{
    if(*top == *capacity - 1)
    {
        printf("\n STACK OVERFLOW,ALLOCATING MEMORY");
        stack_full(s1, capacity);
    }

    else
    {
        (*top)++;
        (s1 + *top)->value = val;
    }
}


int pop(STACK *s1, int* top)
{
    int val;
    if(*top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }

    else
    {
        val = (s1 + *top)->value;
        (*top)--;
        return val;
    }
}

void display(STACK* s1, int *top)
{
    int i;
    if(*top == -1)
    {
        printf("\n STACK IS EMPTY");
    }

    else
    {
        for(i=*top;i>=0;i--)
        {
            printf("\n %d",(s1+1)->value);
        }
    }
}

int peek(STACK *s1, int* top)
{
    if(*top == -1)
    {
        printf("\n STACK IS EMPTY");
        return -1;
    }

    else
    {
        return ((s1+(*top))->value);
    }
}


int main()
{
    STACK* s1 = (STACK*) malloc(sizeof(STACK));
    int top = -1;
    int capacity = -1;

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
                push(s1, &top, &capacity, val);
                break;

            case 2:
                val = pop(s1, &top);
                if(val != -1)
                    printf("\n The value deleted from stack is: %d", val);
                break;

            case 3:
                val = peek(s1, &top);
                if(val != -1)
                    printf("\n The value stored at top of stack is: %d", val);
                break;

            case 4:
                display(s1, &top);
                break;
        }
    }while(option != 5);
}