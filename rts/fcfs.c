#include<stdio.h>

int main()
{
  int q_size,p_time[20],p_wait[20],turn_time[20];
  int i,j;
  printf("Enter the number of processes: ");
  scanf("%d",&q_size);
  for(i=0;i<q_size;i++)
    {
      printf("Enter the Execution time of Process %d: ",i+1);
      scanf("%d",&p_time[i]);
    }
  p_wait[0]=0;
  turn_time[0]=p_time[0];
  for(i=1;i<=q_size;i++)
    {
      p_wait[i]=turn_time[i-1];
      turn_time[i]=p_time[i]+p_wait[i];
    }
  int wait_sum=0,turn_sum=0;
  for(i=0;i<q_size;i++)
    {
      wait_sum+=p_wait[i];
      turn_sum+=turn_time[i];
    }
  printf("Process\t Wait Time\t Turn Time\n");
  for(i=0;i<q_size;i++)
    {
      printf("P%d \t %d\t\t %d \n",i+1,p_wait[i],turn_time[i]);
    }
  printf("Avg\t %f\t %f \n",(float)wait_sum/q_size,(float)turn_sum/q_size);
}
