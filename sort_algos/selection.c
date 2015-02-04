#include<stdio.h>

#define size 10
int main()
{
  int arr[]={10,9,8,7,6,5,4,3,2,1};
  int i,j,min=0;
  for(i=0;i<size;i++)
    {
      min=i;
      for(j=i+1;j<size;j++)
	{
	  if(arr[j]<arr[min])
	    min=j;
	}
      int temp=arr[min];
      arr[min]=arr[i];
      arr[i]=temp;
    }

  for(i=0;i<size;i++)
    {
      printf("%d\n",arr[i]);
    }
  return 0;
}
