#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* next;
  int data;
};

struct list
{
  struct node*head;
  struct node*tail;
};

void push(struct list *s,int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(s->head==NULL)
    {
      printf("First element\n");
      temp->data=data;
      temp->next=NULL;
      s->head=temp;
    }
  else
    {
      temp->next=s->head;
      temp->data=data;
      s->head=temp;
    }
}

void pop(struct list *s)
{
  struct node* temp;
  if(s->head==NULL)
    {
      printf("\n Empty\n");
    }
  else
    {
      temp=s->head;
      printf("\n The data is %d\n",temp->data);
      s->head=temp->next;
      free(temp);
    }
}

void removefromstack(struct list *s,int data)
{
  struct node*temp;
  struct node* del;
  temp=(struct node*)malloc(sizeof(struct node));
  temp=s->head;
  while(temp!=NULL)
    {
      if(temp->data==data) //For the head node
	{
	  del=temp;
	  printf("\n Found first\n");
	  s->head=(temp->next);
	  if(s->head==NULL)
	    printf("\n NULL\n");
	  temp=s->head;
	  free(del);
	}
      else if((temp->next)->data==data)
	{
	  del=(temp->next);
	  temp->next=(temp->next)->next;
	  printf("\nFound\n");
	  free(del);
	}
      else
	temp=temp->next;
    }
}
int main()
{
  int i;
  struct list s1;
  s1.head=NULL;
  push(&s1,4);
  push(&s1,4);
  push(&s1,4);
  push(&s1,4);
  removefromstack(&s1,4);
  pop(&s1);
  pop(&s1);
  pop(&s1);
  pop(&s1);

  return 0;
}
