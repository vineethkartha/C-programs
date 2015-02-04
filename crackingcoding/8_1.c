#include<stdio.h>

int fib(int n)
{
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  else
    {
      return fib(n-1)+fib(n-2);
    }

}

int main()
{

  int a=5;
  printf("%d\n",fib(a));
  return 0;
}
