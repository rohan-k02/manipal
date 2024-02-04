/* Write a C program to find Closest Common Ancestor (CCA) in a Binary Tree.
The CCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located
farthest from the root [i.e., closest to n1 and n2]. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} Node;

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}


Node* lca (Node* root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->val > n1 && root->val > n2)
	        root = root->left;
        
        else if (root->val < n1 && root->val < n2)
            root = root->right;
        else
            break;
    }

    return root;
}

void main()
{
    Node* root = createNode(20);
    root->left = createNode(8);
    root->right = createNode(22);
    root->left->left = createNode(4);
    root->left->right = createNode(12);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(14);

    int n1 = 10, n2 = 14;
    Node* ancestor = lca(root, n1, n2);
    printf ("LCA of %d and %d is %d \n", n1, n2, ancestor->val);

    n1 = 14, n2 = 8;
    ancestor = lca (root, n1, n2);
    printf ("LCA of %d and %d is %d \n", n1, n2, ancestor->val);  
    
    n1 = 10, n2 = 22;
    ancestor = lca (root, n1, n2);
    printf ("LCA of %d and %d is %d \n", n1, n2, ancestor->val);  
    
    getchar ();
}