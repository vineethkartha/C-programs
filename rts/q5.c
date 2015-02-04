#include "vxWorks.h"
#include"taskLib.h"
#include"stdio.h"

int task1(void);
int task2(void);
int task3(void);
int task4(void);

int t1,t2,t3,t4,main;

q5()
{
	sysClkRateSet(100);
	main=taskIdSelf();
	if((t1=taskSpawn("T1",100,0x100,20000,task1,0,0,0,0,0,0,0,0,0,0))==NULL)
		printf("\nCreation of t1 failed\n");
	if((t2=taskSpawn("T2",100,0x100,2000,task2,0,0,0,0,0,0,0,0,0,0))==NULL)
		printf("\nCreation of t2 failed");
	if((t3=taskSpawn("T3",100,0x100,20000,task3,0,0,0,0,0,0,0,0,0,0))==NULL)
		printf("\nCreation of t3 failed\n");
	if((t4=taskSpawn("T4",100,0x100,2000,task4,0,0,0,0,0,0,0,0,0,0))==NULL)
		printf("\nCreation of t4 failed");
	while(taskIdVerify(t1)==OK | taskIdVerify(t2)==OK |taskIdVerify(t3)==OK | taskIdVerify(t4)==OK)
	{
		taskSuspend(taskIdSelf());
	}
	
	printf("\nmain ends\n");
}

int task1()
{
	int num=0;
	taskPriorityGet(taskIdSelf(),&num);
	printf("The task 1 has priority of %d\n",num);
	printf("Task 1 sleeps\n");
	taskDelay(5);
	taskPriorityGet(taskIdSelf(),&num);
		printf("The task 1 has priority of %d\n",num);
	printf("Task 1 ended\n");
	taskResume(main);
}

int task2()
{
	int num=0;
	taskPriorityGet(taskIdSelf(),&num);
	printf("The task 2 has priority of %d\n",num);
	printf("Task 2 sleeps\n");
	taskDelay(5);
	taskPriorityGet(taskIdSelf(),&num);
		printf("The task 2 has priority of %d\n",num);
	printf("Task 2 ended\n");
	taskResume(main);
}

int task3()
{
	int num=0;
	taskPriorityGet(t1,&num);
	printf("The task 1 has priority of %d\n",num);
	printf("new pri for t1\n");
	taskPrioritySet(t1,90);
	taskResume(main);
}

int task4()
{
	int num=0;
	taskPriorityGet(t2,&num);
	printf("The task 2 has priority of %d\n",num);
	printf("new pri for t2\n");
	taskPrioritySet(t2,90);
	taskResume(main);
}