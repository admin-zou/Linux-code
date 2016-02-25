#include <stdio.h>
#include <signal.h>
#include <string.h>

void handler(int sig)
{//可以用一个函数捕捉很多信号
	switch(sig)
	{
		case SIGINT:
			printf("catach a sig,no:%d\n",sig);
			break;
		case SIGQUIT:
			printf("catach a sig,no:%d\n",sig);
			break;
		default:
			break;
	}
}

int main()
{
	struct sigaction new_act;
	memset(&new_act,0,sizeof(new_act));
	new_act.sa_handler = handler;
	//new_act.sa_handler = SIG_IGN;//忽略
	//new_act.sa_handler = SIG_DFL;//默认

	sigemptyset(&new_act.sa_mask); 

	sigaction(SIGINT,&new_act,NULL); //用sigaction函数注册一个信号
	signal(SIGQUIT,handler);//再注册一个函数
	while(1)
	{
		printf("this is a test\n");
		sleep(1);
	}
}
