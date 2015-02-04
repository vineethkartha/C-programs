#include<stdio.h>
#include<stdlib.h>
#define MAX 3

struct node
{
  struct node* next;
  int data;
};

struct stack
{
  struct node* top;
  int size;
};

struct set
{
  struct stack s1;
  struct stack s2;
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
    return -1;
  else
    {
      int res;
      temp=s->top;
      s->top=(s->top)->next;
      res=temp->data;
      free(temp);
      return res;
    }
}

void pushS(struct set *s, int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->next=NULL;
  temp->data=data;
  if(s->s1.top==NULL)
    {
      s->s1.top=temp;
      s->s1.size=1;
    }
  else if(s->s1.size<MAX)
    {
      temp->next=s->s1.top;
      s->s1.top=temp;
      s->s1.size++;
    }
  else if(s->s2.top==NULL)
    {
      printf("\n In Next stack\n");
      s->s2.top=temp;
      s->s2.size=1;
    }
  else if(s->s2.size<MAX)
    {
      temp->next=s->s2.top;
      s->s2.top=temp;
      s->s2.size++;
    }
}

int popS(struct set *s)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(s->s1.top==NULL)
    return -1;
  else if(s->s2.top==NULL)
    {
      int res;
      temp=s->s1.top;
      res=temp->data;
      s->s1.top=s->s1.top->next;
      free(temp);
      s->s1.size--;
      return res;
    }
  else
    {
      int res;
      temp=s->s2.top;
      res=temp->data;
      s->s2.top=s->s2.top->next;
      free(temp);
      s->s2.size--;
      return res;
    }
}

int main()
{
  struct set s;
  s.s1.top=NULL;
  s.s1.size=0;
  s.s2.top=NULL;
  s.s2.size=0;
  pushS(&s,1);
  pushS(&s,2);
  pushS(&s,3);
  pushS(&s,4);
  pushS(&s,5);
  pushS(&s,6);
  pushS(&s,7);
  while(s.s1.top!=NULL)
    {
      printf("%d\n",popS(&s));
    }
  return 0;

}
