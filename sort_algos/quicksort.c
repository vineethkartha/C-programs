#include<stdio.h>

#define size 10

void printArray(int arr[],int len)
{
  int i;
  for(i=0;i<size;i++)
    {
      printf("%d\n",arr[i]);
    }
}

int part(int A[],int left,int right)
{
  int P=A[left],i=left,j=right+1;
  while(1)
    {
      while(A[++i]<P)
	if(i>=right)
	  break;
      while(A[--j]>P)
	if(j<=left)
	  break;
	else
	  {
	    int temp=A[i];
	    A[i]=A[j];
	    A[j]=temp;
	  }
    }
  if(j==left)
    return j;
  int temp=A[left];
  A[left]=A[j];
  A[j]=temp;
  return j;
	    
}
void qsort(int A[],int left,int right)
{
  int q;
  if(right>left)
    {
      q=part(A,left,right);
      qsort(A,left,q-1);
      qsort(A,q+1,right);
    }
}

int main()
{
  int arr[]={10,9,8,7,6,5,4,3,2,1};
  int i,j,min=0;
  qsort(arr,0,size-1);
  //printArray(arr,size);
  return 0;
}
