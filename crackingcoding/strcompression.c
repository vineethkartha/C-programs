/* if i/p= aabbbccccd op should be a2b3c4d1*/

#include<stdio.h>

int main()
{
  char strin[20], strout[20];
  printf("Enter the string : ");
  scanf("%s",strin);
  int i=0,k=0,count=1;
  char c;
  c=strin[0]; //First character
  //strout[0]=c; //First character of input goes to the output also
  for(i=1;strin[i]!='\0';i++)
    {
      printf("%c==%c\n",strin[i],c);
      if(strin[i]==c)
	{
	  count++;
	}
      else
	{
	  printf("\n count %d\n",count);
	  strout[k]=c;
	  k++;
	  strout[k]=('0'+count);
	  k++;
	  c=strin[i];
	  count=1;
	}
    }
  strout[k]=c;
  k++;
  strout[k]=('0'+count);
  k++;
  strout[k]='\0';
  printf("\n the out put is %s\n",strout);
  return 0;
}
