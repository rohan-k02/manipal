int Search(Nodeptr root,int ele) //uses preorder traversal
{
    static int t=0;
    if(root)
    {
        if(root->data==ele)
        {
            t++;
            return t;
        }

    if (t==0) Search(root->lchild,ele);
    if (t==0) Search(root->rchild,ele);
    }
}
