#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int show_pending(sigset_t *pending)
{
	if(NULL == pending)
		return 0;
	int i=1;
	int flag=0;
	for(i=1; i<32; ++i)
	{
		if(sigismember(pending,i)) //如果i是未决信号量集的成员，则成功返回1，否则失败返回0
		{
			printf("1");
			fflush(stdout);
			flag=1;
		}
		else
		{
			printf("0");
			fflush(stdout);
		}
	}
	printf("\n");
	return flag;
}

void handler(int sig)
{
	printf("2:SIGINT,catch sig,code is %d \n",sig);
	exit(1);
}
void handler2(int sig)
{
	printf("3:SIGQUIT,code is %d \n",sig);
	exit(1);
}
void handler3(int sig)
{
	printf("20:SIGTSTP!,code is %d \n",sig);
	exit(1);
}

///////////////////////////////////////////////////
int main()
{
	signal(SIGINT,handler);
	signal(3,handler2);
	signal(20,handler3);
	sigset_t new;
	sigset_t old;
	sigset_t pending;

	sigemptyset(&new);   //初始化为空
	sigemptyset(&old);   //初始化为空

	sigaddset(&new,SIGINT); //在信号量集中添加2号信号
	sigaddset(&new,3); //在信号量集中添加3号信号
	sigaddset(&new,20); //在信号量集中添加20号信号

	sigprocmask(SIG_SETMASK,&new,&old); //old保存当前阻塞信号量集，new用于替换当前阻塞信号量集，方式为mask=set
	
	while(1)
	{
		sigemptyset(&pending);
		sigpending(&pending);
		int ret=show_pending(&pending);  //读取未决信号量集表
		if(ret == 1)//成功
		{
			printf("begin unblock SIGINT\n");
			sleep(1);
			sigprocmask(SIG_SETMASK,&old,NULL); //用old代替当期阻塞信号量集,此时阻塞信号量集为空
		}
		sleep(1);
	}
	return 0;
}
