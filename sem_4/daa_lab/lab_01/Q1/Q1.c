/* 1). Write a program to construct a binary tree to support the following operations.
Assume no duplicate elements while constructing the tree.
i. Given a key, perform a search in the binary search tree. If the key is found
then display “key found” else insert the key in the binary search tree.
ii. Display the tree using inorder, preorder and post order traversal methods */

#include<stdio.h>
#include<stdlib.h>

typedef struct node* NODEPTR;
typedef struct node
{
    NODEPTR left;
    NODEPTR right;
    int value;
} NODE;


NODEPTR createnode(int x)
{
    NODEPTR newnode = (NODEPTR)malloc(sizeof(NODE));
    newnode->value = x;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

void insertBST(NODEPTR* tree,int x)
{
    NODEPTR iter = (NODEPTR) malloc(sizeof(NODE));
    NODEPTR prev = (NODEPTR) malloc(sizeof(NODE));
    NODEPTR newnode = (NODEPTR) malloc(sizeof(NODE));
    
    newnode = createnode(x);
    prev = NULL;
    iter = *tree;

    while(iter != NULL)
    {
        prev = iter;

        if(iter->value > x)
        {
            iter = iter->left;
        }
        
        else if(iter->value == x)
        {
        	printf("Key found\n");
        	return;
        }
        
        else
        {
            iter = iter->right;
        }
    }

    if (prev == NULL)
    { 
        *tree = newnode;
    }

    else if (x < prev->value) 
    {
        prev->left = newnode;
    }

    else 
    { 
        prev->right = newnode;
    }    
}

void preorder(NODEPTR tree)
{
	if (tree != NULL)
    {
		printf("%d ",tree->value);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(NODEPTR tree)
{
	if (tree != NULL)
    {
		inorder(tree->left);
		printf("%d ",tree->value);
		inorder(tree->right);
	}
}

void postorder(NODEPTR tree)
{
	if (tree != NULL)
    {
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ",tree->value);
	}
}

void main()
{
	int x;
	NODEPTR tree = (NODEPTR) malloc(sizeof(NODE));
	tree = NULL;

    printf("Enter BST elements\nType -1 to exit.\n\n");

	do{
	    printf("Enter element: ");
		scanf("%d",&x);
		if (x < 0)
		{
            break;
        } 
		insertBST(&tree,x);
	}while(x != -1);

	printf("\nPreorder: ");
	preorder(tree);
	printf("\nInorder: ");
	inorder(tree);
	printf("\nPostorder: ");
	postorder(tree);
	printf("\n");
}