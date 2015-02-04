#include<stdio.h>

int main()
{
  int n;
  unsigned int mask=1;
  int count=0,i=0;
  scanf("%d",&n);
  while(mask!=0)
    {
      if(mask&n)
	count++;
      printf("\n %ud %d %d\n",mask,n,mask&n);
      mask=mask<<1;
      //i++;
    }
  printf("\n%d\n",count);
  return 0;
}
