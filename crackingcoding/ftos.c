#include<stdio.h>
#include<string.h>

void rev(char* str)
{
  char temp;
  int i,j;
  for(i=0,j=strlen(str)-1;i<strlen(str)/2;i++,j--)
    {
      temp=str[i];
      str[i]=str[j];
      str[j]=temp;
    }
}
void f2s(float num,int prec)
{
  int n=(int)num,i=0,j;
  float dec=num-n;
  printf("%f\n",dec);
  char str[10];
  while(n>0)
    {
      str[i]='0'+(n%10);
      n=n/10;
      i++;
    }
  str[i]='\0';
  rev(str);
  str[i]='.';
  i++;
  str[i]='\0';
  for(j=0;j<prec;j++)
    {
      n=(int)(dec*10)%10;
      dec=dec*10;
      str[i]='0'+n;
      i++;
    }
  str[i]='\0';
  printf("%s\n",str);
  
}
int main()
{
  f2s(123.01,2);
  return 0;
}
