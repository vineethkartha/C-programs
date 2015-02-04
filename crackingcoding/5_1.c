#include<stdio.h>

int main()
{
  int M,N,i,j;
  M=2;
  N=9;
  i=0;
  j=1;
  int max=~0;
  int left=max-((1<<j)-1);
  int right=(1<<i)-1;
  int mask=left|right;
  printf("\n%d\n",(N&mask)|M);
  return 0;
}
