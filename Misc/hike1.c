/* Given a number print a number using same digits higher than the given number*/
#include<stdio.h>

int lengthofNum(int n)
{
    int cnt=0;
    while(n>0)
    {
        n=n/10;
        cnt++;
    }
    return cnt;
}

void sort(int **arr,int size)
{
    int min,i,j;
    for(i=0;i<size;i++)
    {
      min=i;
      for(j=i+1;j<size;j++)
	{
	  if(*arr[j]<*arr[min])
	    min=j;
	}
      int temp=*arr[min];
      *arr[min]=*arr[i];
      *arr[i]=temp;
    }
for(i=0;i<size;i++)
    {
        printf("%d ",*(arr+i));
    }
}
int main()
{
    int *a;
    int input=32051;
    int len=lengthofNum(input);
    a=(int *)malloc(sizeof(int)*lengthofNum(input));
    int i;
    for(i=0;i<len;i++)
    {
        *(a+i)=input%10;
        input=input/10;
    }
    sort(&a,lengthofNum(input));
    //sort(a,lengthofNum(input));
    for(i=0;i<len;i++)
    {
        printf("%d ",*(a+i));
    }
    return 0;
}
