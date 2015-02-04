#include<stdio.h>	       
#include<string.h>
int main()
{
  int num,dig=0,i=0,j;
  char str[10],temp;
  printf("Enter num: ");
  scanf("%d",&num);
  while(num>0)
    {
      dig=num%10;
      num/=10;
      str[i]='0'+dig;
      i++;
    }
  str[i]='\0';
  for(i=0,j=strlen(str)-1;i<strlen(str)/2;i++,j--)
    {
      temp=str[i];
      str[i]=str[j];
      str[j]=temp;
    }
  printf("The number is %s\n",str);
  return 0;
}
