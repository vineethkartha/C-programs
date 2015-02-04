#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
  int c;
  pid_t p;
  int i=0,n;
  printf("Enter number of children\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {  
      c=fork();
      if(c==-1)
	{
	  printf("\n Error\n");
	  perror("fork");
	  return 1;
	}
      if(c==0)
	{
	  p=getpid();
	  printf("\n I am task %d\n",p);
	  usleep(50*1000);
	  return 0;
	}
    }
while(wait(NULL)>0);
  return 0;
}
