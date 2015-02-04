//Program to reverse a string in place

#include<stdio.h>
#include<string.h>


int main()
{
  char str[100],temp;
  int i,j;
  printf("\n Enter String : ");
  scanf("%s",str);
  for(i=0,j=strlen(str)-1;i<strlen(str)/2;i++,j--)
    {
      temp=str[i];
      str[i]=str[j];
      str[j]=temp;
    }
  //str[i]='\0';
  printf("\n The string is %s\n",str);
  return 0;
}
