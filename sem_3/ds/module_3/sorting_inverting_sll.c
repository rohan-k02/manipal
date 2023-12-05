#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODEPTR;

typedef struct node
{
    int data;
    NODEPTR next;
}NODE;


NODEPTR *sort_list(NODEPTR start)
{
    NODEPTR ptr1, ptr2;
    int temp;
    ptr1 = start;
    while(ptr1 -> next != NULL)
    {
        ptr2 = ptr1 -> next;

        while(ptr2 != NULL)
        {
            if(ptr1 -> data > ptr2 -> data)
            {
                temp = ptr1 -> data;
                ptr1 -> data = ptr2 -> data;
                ptr2 -> data = temp;
            }
            ptr2 = ptr2 -> next;
        }

        ptr1 = ptr1 -> next;
    }
    return start; // Had to be added
}

NODEPTR invert(NODEPTR list)
{

    NODEPTR middle, trail;
    middle = NULL;
    while (list) {
        trail = middle;
        middle = list;
        list = list->next;
        middle->next = trail;
    }
    return middle;
}
