#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct queue
{
  struct node* head;
  struct node* tail;
};

void add(struct queue* q,int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=NULL;
  if(q->tail==NULL)
    {
      q->head=temp;
      q->tail=temp;
    }
  else
    {
      printf("\n Not first\n");
      (q->tail)->next=temp;
      q->tail=temp;
    }
}

void del(struct queue* q)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(q->head==NULL)
    printf("\n Queue is empty\n");
  else
    {
      temp=q->head;
      q->head=(q->head)->next;
      printf("Deleted : %d\n",temp->data);
      free(temp);
    }
  
}

int main()
{
  struct queue q;
  q.head=NULL;
  q.tail=NULL;
  add(&q,1);
  add(&q,2);
  add(&q,3);
  del(&q);
  del(&q);
  del(&q);
  del(&q);
  return 0;
}
