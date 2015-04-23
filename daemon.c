#include <unistd.h>
#include <stdio.h>
#include <syslog.h>

int main()
{
	daemon(0, 0);
	openlog(NULL,LOG_NOWAIT|LOG_PID,LOG_USER);
	while (89){
		
		syslog(LOG_EMERG, "Successfully started daemon\n"); 
		
	}
	closelog();
		printf("Lol\n");
}
