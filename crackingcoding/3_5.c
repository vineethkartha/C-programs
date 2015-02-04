#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node* next;
};

struct stack
{
  struct node* top;
  int size;
};
struct setofstacks
{
  struct stack pushStack,popStack;
};

void push(struct stack *s,int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->next=NULL;
  temp->data=data;
  if(s->top==NULL)
    {
      s->top=temp;
    }
  else
    {
      temp->next=s->top;
      s->top=temp;
    }
}

int pop(struct stack *s)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(s->top==NULL)
    {
      printf("The stack is Empty\n");
      return -1;
    }
  else
    {
      int ret;
      temp=s->top;
      s->top=(s->top)->next;
      ret=temp->data;
      //printf("The value is: %d\n",temp->data);
      free(temp);
      return ret;
    }
}

void pushQ(struct setofstacks *s, int data)
{
  push(&(s->pushStack),data);
}

int popQ(struct setofstacks *s)
{
  if(s->popStack.top==NULL)
    {
      while(s->pushStack.top!=NULL)
	{
	  push(&(s->popStack),pop(&(s->pushStack)));
	}
    }
  return pop(&(s->popStack));
}

int main()
{
  struct setofstacks s;
  s.pushStack.top=NULL;
  s.popStack.top=NULL;
  pushQ(&s,1);
  pushQ(&s,2);
  pushQ(&s,3);
  printf("%d \n", popQ(&s));
  printf("%d \n", popQ(&s));
  printf("%d \n", popQ(&s));
  printf("%d \n", popQ(&s));
  return 0;
}
