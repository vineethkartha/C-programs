#include<stdio.h>

int main()
{
  char str[20];
  int result=0,i,digit;
  printf("Enter the number: ");
  scanf("%[[0-9]^\n]s",str);
  printf("%s Is what I entered\n",str);
  for(i=0;str[i]!='\0';i++)
    {
      digit=str[i]-'0';
      if(i>0)
	result=result*10+digit;
      else
	result=digit;
    }
  printf("\nNumber is : %d\n",result);
  return 0;
}
