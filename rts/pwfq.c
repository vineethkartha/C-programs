/* Author Vineeth the Kartha 
 date: 17-Oct-2013
an Implementation of preemptive Weighted Fairnesss Queue Algorithm */

#include<stdio.h>
#include<string.h>

struct server
{
  char s_name[4];
  int start_time;
  int stop_time;
  float exec_time;
  float fn;
  float u;
}servers[20];


void fnsorting (struct server s[], int size );
void enterdetails(struct server s[],int num);
int greatest(struct server s[],int size);
int smallest(struct server s[],int size);

void disp(struct server s[],int size)
{
  int i;
  for(i=0;i<size;i++)
    {
      printf("\n start time of %s is %d: ",s[i].s_name, s[i].start_time);
      printf("\n stop time of %s is %d: ",s[i].s_name,s[i].stop_time);
      printf("\n The fn of  %s : %f ",s[i].s_name,s[i].fn);
    }
}


int main()
{
  float F_N=0, U_b=0;
  int cur_time=0,T_1=0,n,i,e;
  printf("\nEnter number of servers\n");
  scanf("%d",&n);
  enterdetails(servers,n);
  printf("\n\n The largest stop time is %d\n",greatest(servers,n));
  while(cur_time<=greatest(servers,n))
    {  
      for(i=0;i<n;i++)
	{
	  if(cur_time==servers[i].start_time && cur_time==smallest(servers,n))
	    {
	      T_1=cur_time;
	      U_b+=servers[i].u;
	      servers[i].fn=servers[i].exec_time/servers[i].u;
	    }
	  if(cur_time!=smallest(servers,n)&&cur_time==servers[i].start_time)
	    {
	      F_N+=(cur_time-T_1)/U_b;
	      T_1=cur_time;
	      U_b+=servers[i].u;
	      servers[i].fn=F_N+servers[i].exec_time/servers[i].u;
	    }
	}
      //disp(servers,n);
      fnsorting(servers,n);
      printf("\nTime\t\tServer\t\tfn\t\tF_N\t\tU_b\n");
      for(i=0;i<n;i++)
	{
	  if(servers[i].fn!=0&&servers[i].stop_time>cur_time)
	    {
	      e=servers[i].exec_time;
	      printf("%d\t\t%s\t\t%0.2f\t\t%0.2f\t\t%0.2f\n",cur_time,servers[i].s_name,servers[i].fn,F_N,U_b);
	      if(cur_time<servers[i].stop_time)
		{
		  servers[i].fn+=servers[i].exec_time/servers[i].u;
		}
	      else
		{
		  F_N+=(cur_time-T_1)/U_b;
		  T_1=cur_time;
		  U_b+=servers[i].u;
		}
	      break;
	    }
	}
  //disp(servers,n);
      cur_time+=e;
    }
}

void fnsorting (struct server s[], int size )
{
  int i ,j ;
  struct server temp;
  for ( i =0; i <( size -1) ; i ++)
    {
      for ( j =0; j < size -1 - i ; j ++)
	{
	  if ( s[ j ].fn > s[j+1].fn)
	    {
	      temp = s[ j +1];
	      s[j+1]= s[j];
	      s[j]= temp ;
	    }
	}
    }
}


int smallest(struct server s[],int size)
{
  int i=0;
  int sttime=s[0].start_time;
  for(i=0;i<size;i++)
    {
      if(s[i].start_time<sttime)
	sttime=s[i].start_time;
    }
  return sttime;
}

int greatest(struct server s[],int size)
{
  int i=0;
  int stptime=0;
  for(i=0;i<size;i++)
    {
      if(s[i].stop_time>stptime)
	stptime=s[i].stop_time;
    }
  return stptime;
}

void enterdetails(struct server s[],int num)
{
  int i;
  char buf[10];
  for(i=0;i<num;i++)
    {
      sprintf(buf, "s%d", i+1);
      strcpy(s[i].s_name,buf);
      printf("\n Enter the start time of %s: ",s[i].s_name);
      scanf("%d",&s[i].start_time);
      printf("\n Enter the stop time of %s: ",s[i].s_name);
      scanf("%d",&s[i].stop_time);
      printf("\n Enter the Exec time of each job in the queue: ");
      scanf("%f",&s[i].exec_time);
      printf("\n Enter the size of %s: ",s[i].s_name);
      scanf("%f",&s[i].u);
      s[i].fn=0;
    }
}
