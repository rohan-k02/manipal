void insert(Nodeptr root, char direction[], int ele) { // assume root is already created and tree exists
int i;
Nodeptr temp,cur,parent;
temp= getnode();
temp->data=ele;
temp->lchild=temp->rchild=NULL;
parent = NULL;
cur=root;
i=0;
while (cur && direction[i]) {//traverse down the tree
parent = cur;
if(direction[i]=='L' || direction[i]=='l')
cur=cur->lchild;
else
cur=cur->rchild;
i++;
}
if ((cur != NULL) || (direction[i]!='\0')) { /*node already present at specified pos/incorrect dir string */
printf("Insertion Not possible\n") ;
free(temp);
return;
}
/*Based on last character of direction string insert as a left or right child */
if(direction[i-1]=='L' || direction[i-1]=='l')
parent->lchild=temp;
else
parent->rchild=temp;
}
