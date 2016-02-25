#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


void handler(int sig)
{
	int status=0;
	pid_t id=0;
	while( (id=waitpid(-1,&status,0)) > 0)
	{
		printf("wait success, pid:%d\n",id);
		if(WIFEXITED(status))
		{
			printf("exit code is:%d\n",WEXITSTATUS(status));
		}
	}
}

int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);

	sigaction(SIGCHLD,&act,NULL);

	pid_t id= fork();
	if(id<0)
	{//
		perror("fork error");
		return 1;
	}
	else if(id==0)
	{
		printf("child:pid:%d ppid:%d\n",getpid(),getppid());
		sleep(2);
		exit(1);
	}
	else
	{
		printf("father:pid:%d ppid:%d\n",getpid(),getppid());
		while(1)
		{
			printf("i am busing\n");
			sleep(1);
		}
		pause();
	}
	return 0;
}
