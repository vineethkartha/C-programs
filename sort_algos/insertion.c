#include<stdio.h>
//#define size 10
int main()
{
  int arr[1001];
  int i,j,size;
  int cnt=0;
  scanf("%d",&size);
  for(i=0;i<size;i++)
    {
      scanf("%d",&arr[i]);
    }
  for(i=1;i<size;i++)
    {
      j=i-1;
      int num=arr[i];
      while(j>=0 && arr[j]>num)
	{
	  cnt++;
	  arr[j+1]=arr[j];
	  arr[j]=num;
	  j--;
	}
    }
  printf("%d\n",cnt);
  /*for(i=0;i<size;i++)
    {
      printf("%d\n",arr[i]);
      }*/
  return 0;
}
