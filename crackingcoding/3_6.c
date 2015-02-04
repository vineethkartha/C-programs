#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *next;
  int data;
};

struct stack
{
  struct node *top;
};

void push(struct stack *s,int data)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=NULL;
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
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(s->top==NULL)
    return -1;
  else
    {
      int res;
      temp=s->top;
      s->top=(s->top)->next;
      res=temp->data;
      //free(temp);
      return res;
    }
}
int peek(struct stack *s)
{
  if(s->top==NULL)
    return -1;
  else
    return (s->top)->data;
}
void sort(struct stack *unsorted, struct stack *sorted)
{
  int temp;
  while(unsorted->top!=NULL)
    {
      temp=pop(unsorted);
      while(temp<peek(sorted)&&peek(sorted)!=-1)
	{
	  push(unsorted,pop(sorted));
	}
	    push(sorted,temp);
    }
}
int main()
{
  struct stack s,s1;
  s.top=NULL;
  s1.top=NULL;
  push(&s,1);
  push(&s,2);
  push(&s,4);
  push(&s,3);
  sort(&s,&s1);
  /*printf("%d \n",pop(&s));
  printf("%d \n",pop(&s));
  printf("%d \n",pop(&s));*/
 printf("\n Sorted\n");
 while(s1.top!=NULL)
   printf("%d \n",pop(&s1));
  
}
