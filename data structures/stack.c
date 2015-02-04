#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct node
{
  int data;
  struct node *next;
};

struct stack
{
  int size;
  struct node *top;
};


int push(struct stack *s,int data)
{
  struct node *n;
  n=(struct node *)malloc(sizeof(struct node));
  if(n!=NULL)
    {
      n->data=data;
      n->next=NULL;
      if(s->top==NULL)
	{
	  s->top=n;
	}
      else
	{
	  n->next=s->top;
	  s->top=n;
	}
      return 1;
    }
  else
    return 0;
}  
int pop(struct stack *s)
{
  struct node *n;
  if(s->top==NULL)
    {
      printf("\nEmpty Stack\n");
      return 0;
    }
  else
    {
      n=s->top;
      printf("\n %d deleted \n",n->data);
      s->top=n->next;
      free(n);
      return 1;
    }
}

void display(struct stack *s)
{
  struct node *n;
  n=s->top;
  while(n!=NULL)
    {
      printf("%d\t",n->data);
      n=n->next;
    }
  printf("\n");
}

int main()
{
  struct stack s1,s2;
  int data;
  int choice;
  s1.top=NULL;
  s2.top=NULL;
  while(1)
    {
      printf("\nOptions\n------------------\n1)Push\n2)Pop\n3)Display\n4)Exit\nEnter Option : ");
      
      scanf("%d",&choice);
      if(choice==1)
	{
	  printf("Enter the data\n");
	  scanf("%d",&data);
	  push(&s1,data);
	}
      else if(choice==2)
	{
	  if(!pop(&s1))
	    printf("\n Empty queue\n");
	}
      else if(choice==3)
	{
	  printf("\n Elements are \n");
	  display(&s1);
	}
      else if(choice==4)
	{
	  exit(0);
	}
    }

  return 0;
}
