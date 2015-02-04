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

void add(struct list *s,int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  if(s->head==NULL&&s->tail==NULL)
    {
      printf("First element\n");
      temp->data=data;
      temp->next=NULL;
      s->head=temp;
      s->tail=temp;
    }
  else
    {
      temp->next=NULL;
      temp->data=data;
      (s->tail)->next=temp;
      s->tail=temp;
    }
}
void rem(struct list *s)
{
  if(s->head==NULL)
    {
      printf("\n Empty\n");
    }
  else
    {
      
    }
}
int get(struct list *s,int pos)
{
  int i=0;
  struct node* temp;
  temp=s->head;
  while(temp!=NULL)
    {
      if(i==pos)
	{
	  return temp->data;
	}
      temp=temp->next;
      i++;
    }
}
int main()
{
  int i;
  int res,carry=0;
  struct list l1,l2,l3;
  l1.head=NULL;
  l1.tail=NULL;
  l2.head=NULL;
  l2.tail=NULL;
  l3.head=NULL;
  l3.tail=NULL;
  
  add(&l1,3);
  add(&l1,1);
  add(&l1,5);

  add(&l2,5);
  add(&l2,9);
  add(&l2,2);
  for(i=0;i<3;i++)
    {
      res=(get(&l1,i)+get(&l2,i))<10?(get(&l1,i)+get(&l2,i)):(get(&l1,i)+get(&l2,i))%10;
      res+=carry;
      add(&l3,res);
      //printf("\n%d+%d+%d=%d\n",get(&l1,i),get(&l2,i),carry,res);
      carry=(get(&l1,i)+get(&l2,i)+carry)/10;
      
    }
  printf("\n%d%d%d\n",get(&l3,0),get(&l3,1),get(&l3,2));
  return 0;

}
