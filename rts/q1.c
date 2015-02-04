#include"vxWorks.h"
#include"ioLib.h"
#include"pipeDrv.h"
#include<semLib.h>
#include<taskLib.h>
#include<stdio.h>

#define myPipe "/pipe/mypipe"
#define MAX_MSG 10
#define MSG_LEN 100
#define MSG "Hi"

SEM_ID semM;

void reader(void);
void writer(void);
int mainq1,rdr,wrt;
q1()
{
	mainq1=taskIdSelf();
	semM=semMCreate(SEM_Q_PRIORITY);
if(pipeDevCreate(myPipe,MAX_MSG,MSG_LEN)==OK)
	printf("\n Pipe create\n");
wrt=taskSpawn("Writer",100,0x100,2000,(FUNCPTR)writer,0,0,0,0,0,0,0,0,0,0);
taskDelay(NO_WAIT);
rdr=taskSpawn("Reader",90,0x100,2000,(FUNCPTR)reader,0,0,0,0,0,0,0,0,0,0);
taskDelay(NO_WAIT);
pipeDevDelete(myPipe,FALSE);
printf("\n Pipe Deleted\n Main Ends\n");
}

void writer()
{
	int f;
	semTake(semM,WAIT_FOREVER);
	f=open(myPipe,O_RDWR,0);
	write(f,MSG,sizeof(MSG));
	close(f);
	semGive(semM);
	printf("\n Message written to pipe\n");
	taskResume(mainq1);
}

void reader()
{
	char msgbuf[20];
	int f;
	semTake(semM,WAIT_FOREVER);
	f=open(myPipe,O_RDWR,0);
	if(read(f,msgbuf,sizeof(MSG))==NULL)
	{
		printf("\nError in reading\n");
		semGive(semM);
		exit(0);
	}
	printf("\n messgae is %s",msgbuf);
	close(f);
	semGive(semM);
	taskResume(mainq1);
}