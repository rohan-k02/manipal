/* Q1. Write a program to create the AVL tree by iterative insertion. */

#include <stdio.h>
#include<stdlib.h>

typedef enum {FALSE, TRUE} bool;

typedef struct node* NODEPTR;
typedef struct node
{
	int val;
	int balance;
	NODEPTR left;
	NODEPTR right;
}NODE; 

NODEPTR search(NODEPTR avl, int data)
{
    if(avl != NULL)
    {
        if(data < avl->val)
        {
            avl = search(avl->left, data);
        }

        else if(data > avl->val)
        {
            avl = search(avl->right, data);
        }
    }

    return avl;
}

NODEPTR insert(NODEPTR avl, int data, int* ht_inc)
{
    NODEPTR aptr, bptr;

    if(avl == NULL)
    {
        avl = (NODEPTR)malloc(sizeof(NODE));
        avl->val = data;
        avl->left = NULL;
        avl->right = NULL;
        avl->balance = 0;
        *ht_inc = TRUE;
        return avl;
    }

    if(data < avl->val)
    {
        avl->left = insert(avl->left, data, ht_inc);
        if(*ht_inc = TRUE)
        {
            switch (avl->balance)
            {
                case -1: /* Right heavy */
                    avl->balance = 0;
                    *ht_inc = FALSE;
                    break;

                case 0: /* Balanced */
                    avl->balance = 1;
                    break; 

                case 1: /* Left heavy */
                    aptr = avl->left;
                    if(aptr->balance == 1)
                    {
                        printf("Left to Left Rotation");
                        avl->left= aptr->right;
                        aptr->right = avl;
                        avl->balance = 0;
                        aptr->balance = 0;
                        avl = aptr;
                    }

                    else
                    {
                        printf("Left to Right Rotation");
                        bptr = aptr->right;
                        aptr->right = bptr->left;
                        bptr->left = aptr;
                        avl->left = bptr->right;
                        bptr->right = avl;

                        if/* condition */(bptr->balance == 1)
                            avl->balance = -1;
                        else
                            avl->balance = 0;

                        if(bptr->balance == -1)
                            aptr->balance = 1;
                        else
                            aptr->balance = 0;

                        bptr->balance = 0;
                        avl = bptr;
                    }
                    *ht_inc = FALSE;
            }
        }
    }

    if(data > avl->val)
    {
        avl->right = insert(avl->right, data, ht_inc);
        if(*ht_inc == TRUE)
        {
            switch(avl->balance)
            {
                case 1: /* Left heavy*/
                    avl->balance = 0;
                    *ht_inc = FALSE;
                    break;
                
                case 2: /* Balanced */
                    avl->balance = -1;
                    break;

                case -1: /* Right heavy */
                    aptr = avl->right;
                    if(aptr -> balance == -1)
                    {
                        printf("Right to Right Rotation\n");
                        avl->right=aptr->left;
                        aptr->left= avl;
                        avl->balance = 0;
                        aptr->balance=0;
                        avl = aptr;
                    }
                    
                    else
                    {
                        printf("Right to Left Rotation\n");
                        bptr = aptr->left;
                        aptr->left = bptr->right;
                        bptr->right = aptr;
                        avl->right = bptr->left;
                        bptr->left = avl;
                        if(bptr->balance == -1)
                            avl->balance = 1;
                        else
                            avl->balance = 0;
                        
                        if(bptr->balance == 1)
                            aptr->balance = -1;
                        else
                            aptr->balance = 0;
                        
                        bptr->balance=0;
                        avl = bptr;
                     }
                     *ht_inc = FALSE;
            }
        }
    }

    return avl;
}

void display(NODEPTR avl, int level)
{
    int i;
    if(avl != NULL)
    {
        display(avl->right, level+1);
        printf("\n");
        for(i = 0; i < level; i++)
        {
            printf(" ");
        }
        printf("%d", avl->val);
        display(avl->left, level+1);        
    }
}

void inorder(NODEPTR avl)
{
    if(avl != NULL)
    {
        inorder(avl->left);
        printf("%d",avl->val);
        inorder(avl->right);
    }
}

void main()
{
    bool ht_inc;
    int data, option;
    NODEPTR root = (NODEPTR)malloc(sizeof(NODE));
    root = NULL;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Quit\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d"/* condition */, &data);
                    if(search(root, data) == NULL)
                        root = insert(root, data, &ht_inc);
                    else
                        printf("Duplicate value ignored.");
                break;

            case 2:
                if(root == NULL)
                {
                    printf("Tree is empty\n");
                    continue;
                }
                printf("Tree is:\n");
                display(root, 1);
                printf("\n\n");
                printf("Inorder Traversal is: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                exit(1);
            
            default:
                printf("Wrong option\n");
        }    
    } 
}