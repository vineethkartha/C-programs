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


int main()
{
  int arr[]={10,9,8,7,6,5,4,3,2,1};
  int i,j,min=0;
  int gap;
  for(gap=size/2;gap>0;gap/=2)
    {
      for(i=gap;i<size;i++)
	{
	  min=arr[i];
	  for(j=i;j>=gap&&min<arr[j-gap];j-=gap)
	    {
	      arr[j]=arr[j-gap];
	    }
	  arr[j]=min;
	}
    }
  printArray(arr,size);
  return 0;
}
