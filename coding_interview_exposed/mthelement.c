/* C code to find the mth element from the end in a linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void insert(struct node **list,int val)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=val;
  temp->next=NULL;

  if(*list==NULL)
    {
      *list=temp;
    }
  else
    {
      temp->next=*list;
      *list=temp;
    }
}

void del(struct node **list)
{

}

void display(struct node **list)
{
  struct node *cur=*list;
  while(cur!=NULL)
    {
      printf("%d\n",cur->data);
      cur=cur->next;
    }
}

void find(struct node **list,int m)
{
  struct node *fast,*slow;
  fast=*list;
  slow=*list;
  int i;
  for(i=0;i<m;i++)
    {
      if(fast->next!=NULL)
	fast=fast->next;
      else
	{
	  //printf("mth element is %d\n",slow->data);
	  return;
	}
    }
  while(fast->next!=NULL)
    {
      slow=slow->next;
      fast=fast->next;
    }
  printf("Mth element is %d\n\n",slow->data);
}
int main()
{
  struct node *head=NULL;
  int i;
  for(i=0;i<10;i++)
    {
      insert(&head,i);
    }
  find(&head,3);
  display(&head);
  return 0;
}
