int count_leafnodes( Nodeptr root){
static int count = 0;
if(root!=NULL){
if(root->lchild==NULL && root->rchild==NULL)
count++;
count_leafnodes(root->lchild);
count_leafnodes(root->rchild);
}
return count;
}