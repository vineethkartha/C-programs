#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node* left;
  struct node *right;
};
void insert(struct node **tree,int val)
{
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=val;
  temp->left=NULL;
  temp->right=NULL;
  if((*tree)==NULL)
    {
      *tree=temp;
    }
  else if(val>(*tree)->data)
    insert(&(*tree)->right,val);
  else if(val<(*tree)->data)
    insert(&(*tree)->left,val);
}

void display(struct node **tree)
{
  if((*tree)->left==NULL)
    {
      printf("%d\n",(*tree)->data);
      if((*tree)->right!=NULL)
	display(&(*tree)->right);
      else
	return;
    }
  else
    {
      display(&(*tree)->left);
    }
}
int main()
{
  struct node *n=NULL;
  n=(struct node*)malloc(sizeof(struct node));
  insert(&n,4);
  insert(&n,3);
  insert(&n,1);
  insert(&n,2);

  display(&n);
  return 0;
}
