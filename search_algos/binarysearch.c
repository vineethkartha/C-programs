#include<stdio.h>

int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int find;
  scanf("%d",&find);
  printf("\n %d \n",binarySearch(arr,0,10,find));
  return 0;
}

int binarySearch( int arr[],int lb, int ub, int key)
{
  int index;
  while(lb<ub)
    {
      printf("%d--%d\n",lb,ub);
      index=(lb+ub)/2;
      if(arr[index]==key)
	return key;
      else if(arr[index]>key)
	{
	  ub=index-1;
	}
      else
	lb=index+1;
    }
  return 0;
}
