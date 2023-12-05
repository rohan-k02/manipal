#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODEPTR;

typedef struct node
{
    int num;
    int coeff;
    NODEPTR next;
}NODE;



NODEPTR add_poly(NODEPTR start1, NODEPTR start2, NODEPTR start3)
{
    NODEPTR ptr1, ptr2;
    int sum_num, c;
    ptr1 = start1, ptr2 = start2;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 -> coeff == ptr2 -> coeff)
        {
            sum_num = ptr1 -> num + ptr2 -> num;
            start3 = add_node(start3, sum_num, ptr1 -> coeff);
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        else if(ptr1 -> coeff > ptr2 -> coeff)
        {
            start3 = add_node(start3, ptr1 -> num, ptr1 -> coeff);
            ptr1 = ptr1 -> next;
        }
        
        else if(ptr1 -> coeff < ptr2 -> coeff)
        {
            start3 = add_node(start3, ptr2 -> num, ptr2 -> coeff);
            ptr2 = ptr2 -> next;
        }
    }

    if(ptr1 == NULL)
    {
        while(ptr2 != NULL)
        {
            start3 = add_node(start3, ptr2 -> num, ptr2 -> coeff);
            ptr2 = ptr2 -> next;
        }
    }
        
    if(ptr2 == NULL)
    {
        while(ptr1 != NULL)
        {
            start3 = add_node(start3, ptr1 -> num, ptr1 -> coeff);
            ptr1 = ptr1 -> next;
        }
    }

    return start3;
}