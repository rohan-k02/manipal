//Convert a doubly circualr linked list with header node to a chain

#include<stdio.h>
#include<stdlib.h>

typedef struct node* NODEPTR;

typedef struct node
{
    int data;
    NODEPTR prev;
    NODEPTR next;   
} NODE;

void initlist(NODEPTR* header)
{
    *header = (NODEPTR)malloc(sizeof(NODE)); 
    (*header)->prev = *header;
    (*header)->next = *header;
    (*header)->data = -999;
}

void insertrear(NODEPTR* header, int d)
{
    NODEPTR newnode = (NODEPTR)malloc(sizeof(NODE));
    newnode->data = d;

    if((*header)->next==*header||(*header)->prev==*header)
    {
        (*header)->next = newnode;
        (*header)->prev = newnode;
        newnode->next = *header;
        newnode->prev = *header;
    }        

    else
    {
        NODEPTR traverse = (*header);

        while (traverse->next!=*header)
        {
            traverse = traverse->next;
        }
        
        traverse->next = newnode;
        newnode->prev = traverse;
        newnode->next = *header;
        (*header)->prev = newnode;
    }
}


void insertfront(NODEPTR* header, int d)
{
    NODEPTR newnode = (NODEPTR)malloc(sizeof(NODE));
    newnode->data = d;

    if((*header)->next==*header||(*header)->prev==*header)
    {
        (*header)->next = newnode;
        (*header)->prev = newnode;
        newnode->next = *header;
        newnode->prev = *header;
    }        

    else
    {
        (*header)->next->prev = newnode;
        newnode->next = (*header)->next;
        newnode->prev = *header;
        (*header)->next = newnode;
    }

}


void convert(NODEPTR* header, NODEPTR* last)
{
    NODEPTR traverse = (*header);


    while (traverse->next!=(*header))
    {
        traverse = traverse->next;
    }
    

}


int main()
{
    NODEPTR header;
    initlist(&header);
    


}


//Create linked stack without header