int Equal( Nodeptr root1, Nodeptr root2)
{
return ((!root1 && !root2) || (root1 && root2 && (root1→data == root2→data) && Equal( root1->lchild,root2->lchild) && Equal ( root1->rchild,root2->rchild)));
}