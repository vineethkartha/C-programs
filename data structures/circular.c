#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define true 1
#define false 0
struct node
{
  int data;
  struct node *next;
};

struct queue
{
  struct node *rear;
  struct node *front;
};


int pop(struct queue *q)
{
  struct node *n;
  n=q->front;
  if(n==NULL)
    return false;
  else
    {
      q->front=n->next;
      q->rear->next=n->next;
      printf("%d is removed\n",n->data);
      free(n);
      n=q->front;
      return true;
    }
}

int push(struct queue *q,int data)
{
  struct node *newnode;
  newnode=malloc(sizeof(struct node));
  if(newnode!=NULL)
    {
      newnode->data=data;
      newnode->next=NULL;
      if(q->rear==NULL&&q->front==NULL)
	{
	  q->rear=newnode;
	  q->front=newnode;
	}
      else
	{
	  (q->rear)->next=newnode;
	  newnode->next=q->front;
	  q->rear=newnode;
	}
      return 0;
    }
  else
    {
      printf("\n No memroy\n");
      return 1;
    }
}

int display(struct queue *q)
{
  struct node *n;
  n=q->front;
  while(n!=NULL)
    {
      printf("%d\t",n->data);
      n=n->next;       
    }  
  return 0;
}
int main()
{
  struct queue busyq,mainq,*q,*q1;
  int data;
  int choice=0;
  q=&busyq;
  q->front=NULL;
    q->rear=NULL;
    while(true)
    {
      printf("\nOptions\n------------------\n1)Push\n2)Pop\n3)Display\n4)Exit\nEnter Option : ");
      
      scanf("%d",&choice);
      if(choice==1)
	{
	  printf("Enter the data\n");
	  scanf("%d",&data);
	  push(q,data);
	}
      else if(choice==2)
	{
	  if(!pop(q))
	    printf("\n Empty queue\n");
	}
      else if(choice==3)
	{
	  printf("\n Elements are \n");
	  display(q);
	}
      else if(choice==4)
	{
	  exit(0);
	}
    }

  return 0;
}
