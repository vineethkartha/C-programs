#include<stdio.h>

void printunsign(int num)
{
  int to=8*num;
  to=((1<<(to-1))-1)+(1<<(to-1));
  printf("Size is from 0 to %d\n",to);
}

void printsign(int num)
{
  int from ;
  int to=8*num;
  from=-(1<<(to-1));
  to=(1<<(to-1))-1;
  printf("Size is from %d to %d\n",from,to);
}
int main()
{
  printunsign(sizeof(char));
  return 0;
}
