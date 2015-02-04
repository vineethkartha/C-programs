#include<stdio.h>

int main()
{
	char str[]="vineeth Loves programming";
	int start=0,end=0,i,j=0;
	while(str[j]!='\0')
	{
	i=start;
	start=j;
	while(str[start]!=' ')
	{
		start++;
	}
	end= --start;
	j=end;
	start=i;
	while(start<=end)
	{
		char a=str[start];
		str[start]=str[end];
		str[end]=a;
		start++;
		end--;
	}
}
	printf("\n %s\n",str);
	return 0;
}
