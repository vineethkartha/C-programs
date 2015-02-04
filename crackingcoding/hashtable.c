#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BKT_NUM 10

struct hash *hashTable=NULL;

struct node
{
  char name[20];
  int age;
  int key;
  struct node *next;
};

struct hash
{
  struct node *head;
  int count;
};

struct hash* initializeHT(int size)
{
  int i;
  struct hash*temp;
  for(i=0;i<size;i++)
    {
      temp=(struct hash*)malloc(sizeof(struct hash));
      temp->head=NULL;
      temp->count=0;
    }
  return temp;
}

struct node* createNode(int key,char *name, int age)
{
  struct node *Node;
  Node=(struct node*)malloc(sizeof(struct node));
  Node->key=key;
  strcpy(Node->name,name);
  Node->age=age;
  Node->next=NULL;
  return Node;
}

void displayNode(struct node* node)
{
  printf("\nKey: %d",node->key);
  printf("\nName: %s",node->name);
  printf("\nAge: %d",node->age);
  printf("\n--------------------------------\n");
}

void displayTable(struct hash* HT)
{
  int i=0;
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  for(i=0;i<BKT_NUM;i++)
    {
      temp=HT[i].head;
      if(HT[i].count>0)
	{
	  printf("\nIndex %d\n",HT[i].count);
	  displayNode(temp);
	  printf("--");
	  temp=temp->next;
	}
      else
	continue;
      printf("\n");
    }
}

int insert(struct node *newnode)
{
  int index=newnode->key%BKT_NUM;
  //printf("\n %d index is:\n",index);
  if(hashTable[index].head==NULL)
    {
      printf("\n %d index is:\n",index);
      hashTable[index].head=newnode;
      hashTable[index].count=1;
      return 0;
    }
  else
    {
      newnode->next=hashTable[index].head;
      hashTable[index].head=newnode;
      hashTable[index].count++;
      return 0;
    }
}
int main()
{
  int choice=0;
  int k,a,i;
  char nam[20];
  struct node *temp;
  hashTable=initializeHT(BKT_NUM);
  struct hash*temp1;
  hashTable=(struct hash*)malloc(sizeof(struct hash)*BKT_NUM);
  for(i=0;i<BKT_NUM;i++)
    {
      hashTable[i].head=NULL;
      hashTable[i].count=0;
    }
  while(choice!=3)
    {
      printf("\n Enter Choice: ");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:
	  printf("Enter the key:");
	  scanf("%d",&k);
	  printf("Enter the name:");
	  scanf("%s",nam);
	  printf("Enter the age:");
	  scanf("%d",&a);
	  temp=createNode(k,nam,a);
	  insert(temp);
	  break;
	case 2:
	  displayTable(hashTable);
	  break;
	default:
	  break;
	}
    }
  return 0;
}
