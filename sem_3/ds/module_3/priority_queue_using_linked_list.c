#include<stdio.h>
#include<stdlib.h>

typedef struct node* NODEPTR;

typedef struct node
{
    short pid;
    short priority;
    NODEPTR next;
}NODE;


void insertpq(NODEPTR* front, short id, short pr)
{
    NODEPTR temp, prev, newnode;

    newnode = (NODEPTR) malloc(sizeof(NODE));
    newnode->pid = id;
    newnode->priority = pr;

    if(*front == NULL)
    {
        newnode->next = NULL;
        *front = newnode;
    }

    else
    {
        temp = *front;
        while((temp->next!=NULL) && (temp->priority<pr))
        {
            prev = temp;
            temp = temp->next;            
        }
        
        next->next = newnode;
        newnode->next = NULL;
    } 
}

short deleteq(NODEPTR* front)
{
    short id = (*front)->pid;

    NODEPTR temp;

    temp = *front;

    if(temp==NULL)
    {
        printf("The queue is empty.");
        return -999;
    }

    *front=(*front)->next;
    free(temp);
    return id;
}


int main()
{
    NODEPTR front = NULL;
    short ch, id, pr;

    do
    {
        printf("1. Enter process to waiting queue.\n2. Assign the process to the processor.\n3. View the waiting processes.\n0. Exit.\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the process id: ");
            scanf("%d", &id);

            printf("Enter the priority: ");
            scanf("%d", &pr);

            insertpq(&front, id, pr);
            break;

        case 2:
            id = deleteq(&front);
            printf("The job with ID %d has been removed from the process queue.", id);
            break;

        case 3:
            printf("The jobs in the queue are:\n");
            NODEPTR temp;
            temp = front;

            while (temp != NULL)
            {
                printf("ID: %d", temp->pid);
                printf("Priority: %d", temp->priority);
                temp = temp->next;
            }
            break;
        
        default:
            printf("Exiting....");
            ch = 0;
            break;
        }
    } while(ch!=0);
}