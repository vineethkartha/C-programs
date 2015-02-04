/* To find if a string is unique*/
#include<stdio.h>
#include<string.h>
int main()
{
  char str[257];
  char check[256];
  char f=0;
  int i;
  scanf("%s",str);
  for(i=0;str[i]!='\0';i++)
    {
      if(check[str[i]]!=1)
	check[str[i]]=1;
      else
	{
	  f=1;
	  break;
	}
    }
  if(f==0)
    printf("\n %s is unique\n",str);
  else
    printf("\n %s is not unique\n",str);
  return 0;
}
