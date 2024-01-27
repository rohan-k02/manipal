/* 2). Write a program to implement the following graph representations and display them.
i. Adjacency list
ii. Adjacency matrix */

#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODEPTR;
typedef struct node 
{
	NODEPTR next;
	int value;
} NODE;

void display(NODEPTR list)
{
	while(list != NULL)
    {
		printf("Vertex %d -> ", list->value);
		list = list -> next;
	}
	printf("Vertex %d\n", list->value);
}

void insertlast(NODEPTR* list, int x)
{
	NODEPTR newnode = (NODEPTR) malloc(sizeof(NODE));
	NODEPTR iter = (NODEPTR) malloc(sizeof(NODE));
	iter = *list;
	while (iter->next != NULL)
    {
		iter = iter->next;
    }
    newnode->value = x;
	newnode->next = NULL;
	iter->next = newnode;
}



void main()
{
	int v,x,i,j;

	printf("Enter the number of vertices ");
	scanf("%d",&v);

	int** adjMat = (int**) calloc(v,sizeof(int*)); 
	NODEPTR* adjLists = (NODEPTR*) calloc(v,sizeof(NODEPTR));
	
    for(i=0;i<v;i++)
    {
		adjMat[i] = (int *) calloc(v,sizeof(int));
		adjLists[i] = (NODEPTR) malloc(sizeof(NODE));
		adjLists[i]->value = i+1;
		adjLists[i]->next = NULL;
	}

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if (i==j) 
				adjMat[i][i] = 0;
			else
			{
				if (adjMat[i][j] != 1 && adjMat[i][j] != -1)
				{
					printf("Is vertex %d connected to vertex %d ? Type 1 if yes, 0 if no ", (i+1), (j+1));
					scanf("%d",&x);

					if (x == 1)
					{
						insertlast(&(adjLists[i]),(j+1));
						insertlast(&(adjLists[j]),(i+1));
						adjMat[i][j] = 1;
						adjMat[j][i] = 1;
					}

					else
					{
						adjMat[i][j] = -1;
						adjMat[j][i] = -1;
					}
				}
			}
		}
	}
	printf("Adjacency Lists:\n");
	// for(i=0;i<v;i++) {
	// 	printf("\nVertex %d -> ",(i+1));
	// 	for(j=0;j<v;j++) {
	// 		if (adjMat[i][j] == 1)
	// 			printf("Vertex %d -> ",(j+1));
	// 	}
	// }
	for(i=0;i<v;i++)
		display(adjLists[i]);

	printf("\nAdjacency Matrix is:\n");
	
	for(i=0;i<v;i++) {
		for(j=0;j<v;j++) {
			if (adjMat[i][j] == -1)
				adjMat[i][j] = 0;
			printf("%d ", adjMat[i][j]);
		}
		printf("\n");
	}
}