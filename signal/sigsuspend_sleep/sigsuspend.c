#include <stdio.h>
#include <signal.h>
#include <string.h>

void sig_alrm(int sig)
{}

unsigned int my_sleep(unsigned int nsecs)
{
	struct sigaction newact,oldact;
	memset(&newact,0,sizeof(newact));
	memset(&newact,0,sizeof(newact));
	
	sigset_t newmask,oldmask,suspmask;
	unsigned int unslept;

	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags=0;
	sigaction(SIGALRM,&newact,&oldact);

	sigemptyset(&newmask);
	sigaddset(&newmask,SIGALRM);
	sigprocmask(SIG_BLOCK,&newmask,&oldmask);

	alarm(nsecs);

	suspmask = oldmask;
	sigdelset(&suspmask,SIGALRM);
	sigsuspend(&suspmask);

	unslept = alarm(0);
	sigaction(SIGALRM,&oldact,NULL);

	sigprocmask(SIG_SETMASK,&oldmask,NULL);
	return (unslept);
}

int main()
{
	while(1)
	{
		my_sleep(2);
		printf("hehe i am sleeping\n");
	}
	return 0;
}
