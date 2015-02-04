#include<stdio.h>

void substr(char *str,int start,int end)
{
  if(start>end)
    {
      printf("\n");
      return;
    }
  else
    {
      printf("%c",*(str+start));
      substr(str,start+1,end);
    }
} 

int main()
{
  char str[]="vineeth";
  substr(str,1,3);
  return 0;
}
