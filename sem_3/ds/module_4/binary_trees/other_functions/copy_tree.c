Nodeptr copy (Nodeptr root)
{
    Nodeptr temp;

    if(root == NULL)
    return NULL;

    temp=getnode();
    temp->data=root->data;
    temp->lchild=copy(root->lchild);
    temp->rchild=copy(root->rchild);
    return temp;
}