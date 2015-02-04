#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *next;
};

struct list
{
  struct node*head;
  struct node*tail;
};

void add(struct list *l, int data)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->next=NULL;
  temp->data=data;
  if(l->head==NULL&&l->tail==NULL)
    {
      l->head=temp;
      l->tail=temp;
    }
  else
    {
      (l->tail)->next=temp;
      l->tail=temp;
    }
}
void display(struct list*l)
{
  struct node *temp;
  temp=l->head;
  while(temp!=NULL)
    {
      printf("%d\n",temp->data);
      temp=temp->next;
    }
}

void reverse(struct list *l)
{
  struct node *p,*q,*t;
  p=l->head;
  t=NULL;
  while(p!=NULL)
    {
      q=t;
      t=p;
      p=p->next;
      t->next=q;
    }
  l->head=t;
}
int main()
{
  struct list l1;
  l1.head=NULL;
  l1.tail=NULL;
  add(&l1,1);
  add(&l1,2);
  add(&l1,3);
  display(&l1);
  reverse(&l1);
  display(&l1);
  return 0;
}
