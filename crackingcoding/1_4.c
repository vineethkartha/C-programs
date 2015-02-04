#include<stdio.h>
#include<string.h>
int main()
{
  char str[20];
  int i=0,count=0,length,len;
  printf("Enter the string: ");
  scanf("%[^\n]s",str);
  length=strlen(str);
  while(str[i]!='\0')
    {
      if(str[i]==' ')
	count++;
      i++;
    }
  len=length+count*2;
  for(i=length;i>0;i--)
    {
      if(str[i]!=' ')
	{
	  str[i+count*2]=str[i];
	}
      else
	{
	  str[i+count*2]='0';
	  str[i-1+count*2]='2';
	  str[i-2+count*2]='%';
	  i-=3;
	}
    }

  printf("\n%s\n",str);
  return 0;
}
