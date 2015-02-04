#include<stdio.h>
#include<string.h>

int main()
{
  char str[100],temp;
  int i,j;

  printf("Enter the sentence: ");
  fgets(str,100,stdin);
  //  gets(str);
  for(i=0,j=strlen(str)-1;i<strlen(str)/2;i++,j--)
    {
      temp=str[i];
      str[i]=str[j];
      str[j]=temp;
    }
  printf("\n %s \n",str);
  return 0;
}
