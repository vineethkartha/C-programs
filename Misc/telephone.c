/*

Code to convert text to telephone nuber
*/

#include<stdio.h>

int main()
{
  char str[100];
  printf("Enter the string: ");
  scanf("%[^\n]s",str);
  int i;
  for(i=0;str[i]!='\0';i++)
    {
      if(str[i]<'A'||str[i]>'Z')
	{
	  printf("%c",str[i]);
	}
      else
	{
	  if(str[i]-'A'<=2)
	    printf("2");
	  else if(str[i]-'A'<=5)
	    printf("3");
	  else if(str[i]-'A'<=8)
	    printf("4");
	  else if(str[i]-'A'<=11)
	    printf("5");
	  else if(str[i]-'A'<=14)
	    printf("6");
	  else if(str[i]-'A'<=18)
	    printf("7");
	  else if(str[i]-'A'<=21)
	    printf("8");
	  else 
	    printf("9");
	}
    }
  printf("\n");
  return 0;
}
