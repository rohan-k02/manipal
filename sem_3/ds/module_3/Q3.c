/* Finding the inorder successor of a given node in
a binary tree https://www.geeksforgeeks.org/inorder-succesor-node-binary-tree/*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node* NODEPTR;

typedef struct node
{
    int data;
    NODEPTR lchild;
    NODEPTR rchild;
}NODE;

NODEPTR inordersuccessor(NODEPTR root, NODEPTR parent, int val)
{
    if(root)
    {
        if(root->data == val)
        {
            NODEPTR temp;
            if(root->rchild)
            {
                temp = root->rchild;
                while(temp ->lchild != NULL)
                {
                    temp = temp ->lchild;
                }
                return temp;
            }

            else
            {
                return parent;
            }
        }

        NODEPTR lt = inordersuccessor(root->lchild, root, val);
        if(lt)
        {
            return lt;
        }

        else
        {
            return inordersuccessor(root->rchild, root, val);
        }
    }

}



int main()
{
    NODEPTR root, parent, in;
    root = NULL;
    parent = NULL;

    root = creater(1);

    int val;
    printf("Enter data of the node whose data you have to find: ");
    scanf("%d", &val);

    in = inordersuccessor(root, parent, val);
    printf("The inorder successor of the node %d is %d.", val, in->data);
}