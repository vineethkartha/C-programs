#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<taskLib.h>
#include<mqueue.h>
#include<string.h>

#define HI_PRIO 31
#define MSG_SIZE 16
#define MSG_Q9 "greetings"
#define n 10

#define MQ_NAME "MSGQ"

int task1_q1(int id);

mqd_t mqPXId; /* msg queue descriptor */
	char msg[MSG_SIZE]; /* msg buffer */
	int prio; /* priority of message */
	
int t1_q9,main_q9;
q9()
{
	int i;
	/* open message queue using default attributes */
		if ((mqPXId = mq_open (MQ_NAME, O_RDWR |O_CREAT|O_NONBLOCK, 0, NULL)) == (mqd_t) -1)
		{
		printf ("\nOpen failed in main\n");
		return 0;
		}
	for(i=1;i<=n;i++)
	{
		t1_q9=taskSpawn("T1",i,0x100,4000,(FUNCPTR)task1_q1,i,0,0,0,0,0,0,0,0,0);
	}
	if (mq_unlink (MQ_NAME) == -1)
	return (ERROR);
	if (mq_close (mqPXId) == -1)
	return (ERROR);
	return (OK);
}

int task1_q1(int id)
{
	if ((mqPXId = mq_open (MQ_NAME, O_RDWR|O_NONBLOCK, 0, NULL)) == (mqd_t) -1)
	{
	printf ("\nOpen failed in task1\n");
	return 0;
	}
	
	/* try reading from queue*/ 
	if (mq_receive (mqPXId, msg, MSG_SIZE, &prio) == -1)
	{
		char message[14];
		sprintf(message, "The Task is %d",id);
		/* try writing to queue */
			if (mq_send (mqPXId, message, sizeof (message), HI_PRIO) == -1)
			{
			printf ("\nSend failed\n");
			mq_close(mqPXId);
			return 0;
			}		
			else
			printf ("\nSend succeeded\n from task %d\n",id);
	}
	else
	{
	printf ("\nRead from task %d \n %s \n",id, msg);
	}
	mq_close(mqPXId);	
	
}
