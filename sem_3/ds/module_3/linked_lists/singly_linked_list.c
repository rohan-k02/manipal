#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODEPTR;

typedef struct node
{
    int data;
    NODEPTR next;
}NODE;


//Creating a linked list and inputting data
void create(NODEPTR* list)
{
    NODEPTR newnode, temp;
    int num;

    do
    {
        printf("\n Enter data (-1 to end): ");
        scanf("%d", &num);

        newnode = (NODEPTR)malloc(sizeof(NODE));
        if(newnode = NULL)
        {
            printf("Out of memory.");
            return 0;
        }

        newnode->data = num;

        if(*list == NULL)
        {
            newnode->next = NULL;
            *list = newnode;
        }

        else
        {
            temp = *list;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = NULL;
        }
    }while(num!=-1);
}


//Traversing and displaying data
void display(NODEPTR* list)
{
    NODEPTR temp = *list;

    while (temp != NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->next;
    }  
}


//INSERTION

//Insert a node at the beginning of the list
void insert_beg(NODEPTR* list, int num)
{
    NODEPTR newnode = (NODEPTR) malloc(sizeof(NODE));
    if(newnode = NULL)
    {
        printf("Out of memory.");
        return 0;
    }

    newnode->data = num;
    newnode->next = *list;

    *list = newnode;
}


//Insert a node at the end of the list
void insert_end(NODEPTR* list, int num)
{
    NODEPTR newnode, temp;

    newnode = (NODEPTR) malloc(sizeof(NODE));
    newnode->data = num;
    newnode->next = NULL;

    temp = *list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
}

//Insert a node before a node with a given value
void insert_before(NODEPTR* list, int num, int val)
{
    NODEPTR newnode, temp, prev;

    newnode = (NODEPTR) malloc(sizeof(NODE));
    newnode->data = num;

    temp = *list;
    while (temp->data!=val)
    {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = newnode;
    newnode->next = temp;
}


//Insert a node after a node with a given value
void insert_after(NODEPTR* list, int num, int val)
{
    NODEPTR newnode, temp, prev;

    newnode = (NODEPTR) malloc(sizeof(NODE));
    newnode->data = num;

    temp = *list;
    prev = temp;

    while(prev->data != val)
    {
        prev = temp;
        temp= temp->next;
    }

    prev->next = newnode;
    newnode->next = temp;
}

//DELETION

//Delete a node at the beginning
int delete_beg(NODEPTR* list)
{
    NODEPTR temp;
    int num;

    temp = *list;
    num = temp->data;
    *list = (*list)->next;
    free(temp);

    return num;
}

//Delete a node at the end
int delete_end(NODEPTR* list)
{
    NODEPTR temp, prev;
    int num;

    temp = *list;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    num = temp->data;
    prev->next = NULL;
    free(temp);

    return num;    
}


//Delete a node before a given value
int delete_before(NODEPTR* list, int val)
{
    NODEPTR temp, prev;
    int num;

    temp = *list;
    
    while (temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    num = temp->data;

    free(temp);

    return num;
}


//Delete a node after a given value
int delete_after(NODEPTR* list, int val)
{
    NODEPTR temp, prev;
    int num;

    temp = *list;
    prev = temp;

    while(prev->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    num = temp->data;
    prev->next = temp->next;
    free(temp);

    return num;
}





//counting the number of nodes
int count(NODEPTR* list)
{
    NODEPTR temp = *list;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}


//searching for a value and returning a pointer to its node
NODEPTR search(NODEPTR* list, int val)
{
    NODEPTR pos = NULL, temp = *list;

    while (temp != NULL)
    {
        if(val == temp->data)
        {
            pos = temp;
            return pos;
        }

        else
        {
            temp = temp->next;
        }
    }
    
    return pos;
}


int main()
{
    NODEPTR list;
    // create(&list);


    return 0;
}