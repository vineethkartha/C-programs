#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* next;
  int data;
};

struct stack
{
  struct node*top;
};

void push(struct stack *s,int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(s->top==NULL)
    {
      printf("First element\n");
      temp->data=data;
      temp->next=NULL;
      s->top=temp;
    }
  else
    {
      temp->next=s->top;
      temp->data=data;
      s->top=temp;
    }
}

void pop(struct stack *s)
{
  struct node* temp;
  if(s->top==NULL)
    {
      printf("\n Empty\n");
    }
  else
    {
      temp=s->top;
      printf("\n The data is %d\n",temp->data);
      s->top=temp->next;
      free(temp);
    }
}

void removefromstack(struct stack *s,int data)
{
  struct node*temp;
  struct node* del;
  temp=(struct node*)malloc(sizeof(struct node));
  // del=(struct node*)malloc(sizeof(struct node));
  temp=s->top;
  while((temp->next)->next!=NULL||temp->next!=NULL)
    {
      if((temp->next)->data==data)
	{
	  // del=(temp->next);
	  temp->next=(temp->next)->next;
	  printf("\nFound\n");
	  //free(del);
	}
      else
	temp=temp->next;
    }
}
int main()
{
  int i;
  struct stack s1;
  s1.top=NULL;
  push(&s1,1);
  push(&s1,2);
  push(&s1,10);
  push(&s1,5);
  removefromstack(&s1,8);
  pop(&s1);
  pop(&s1);
  pop(&s1);
  pop(&s1);

  return 0;
}
