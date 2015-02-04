#include "vxWorks.h"
#include "msgQLib.h"
#include"taskLib.h"
#include"stdio.h"
#include"string.h"


#define MAX 20  //maximum number of messages
#define MSG_LEN 80 //Lenght of each message

#define MESSAGE1 "One"
#define MESSAGE2 "Two"

int Child_Task(void);

int i=0;

MSG_Q_ID msgq;

int ctask,main;

q7()
{
	main=taskIdSelf();
	i=0; //resetting Counter for the receiver task
	if ((msgq = msgQCreate (MAX, MSG_LEN, MSG_Q_PRIORITY))== NULL)
	{
		printf("\nMessage Q not created\n");
		return (ERROR);
	}
	
	if((ctask=taskSpawn("Child_Task",100,0x100,20000,Child_Task,0,0,0,0,0,0,0,0,0,0))==NULL)
		printf("\nCreation of sender failed\n");
	while(taskIdVerify(ctask)==OK)
		{
		if (msgQSend (msgq, MESSAGE1, sizeof (MESSAGE1), WAIT_FOREVER,MSG_PRI_NORMAL) == ERROR)
			return (ERROR);
		taskDelay(NO_WAIT);
		if (msgQSend (msgq, MESSAGE2, sizeof (MESSAGE2), WAIT_FOREVER,MSG_PRI_NORMAL) == ERROR)
			return (ERROR);
		taskDelay(NO_WAIT);
		if (msgQSend (msgq, MESSAGE1, sizeof (MESSAGE1), WAIT_FOREVER,MSG_PRI_NORMAL) == ERROR)
			return (ERROR);
		taskDelay(NO_WAIT);
		if (msgQSend (msgq, "TASKDELETE", sizeof ("TASKDELETE"), WAIT_FOREVER,MSG_PRI_NORMAL) == ERROR)
			return (ERROR);
		taskDelay(NO_WAIT);
	}
	if(msgQDelete(msgq)==OK)
		printf("\n Message Q deleted\n");
	
	printf("\nmain ends\n");
}

int Child_Task()
{
	char msgBuf[MSG_LEN];
	/* get message from queue; if necessary wait until msg is available */
	while (msgQReceive(msgq, msgBuf, MSG_LEN, WAIT_FOREVER) != ERROR)
	{
		if(strcmp(msgBuf,"TASKDELETE")==0)
		{
			printf("\n Task deleted\n");
			if(taskDelete(taskIdSelf())==ERROR)
				printf("\n Receiver Task not deleted\n");
		}
		else
		{
			printf ("\n %s\n", msgBuf);
			taskResume(main);
		}
		
	}
}