int height (NODEPTR root)
{
    if(root==NULL)
    return 0;

    return( 1+ max(height (root→lchild), height(root→rchild)));
}

int max(int a, int b){
if(a>b)
return a;
else
return b;
}
