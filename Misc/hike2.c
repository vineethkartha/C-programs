#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **list,int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(*list==NULL)
        *list=temp;
    else
    {
        temp->next=*list;
        *list=temp;
    }
}

void display(struct node **list)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=*list;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void swap(struct node **list,int k)
{
    struct node *p,*q;
    p=q=*list;
    int i;
    for(i=0;i<k-1&&p!=NULL;i++)
        p=p->next;
    int temp=q->data;
    q->data=p->data;
    p->data=temp;
    q=q->next;
    k=k/2;

}
int main()
{
    struct node *list=NULL;
    insert(&list,1);
    insert(&list,2);
    insert(&list,3);
    insert(&list,4);
    insert(&list,5);
    insert(&list,6);
    display(&list);
    swap(&list,3);
    printf("\n------------\n");
    display(&list);
    return 0;
}
