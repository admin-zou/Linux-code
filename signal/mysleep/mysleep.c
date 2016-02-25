#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void alarm_handler()
{}

int mysleep(int seconds)
{
	struct sigaction act,oact;
	memset(&act,0,sizeof(act));
	memset(&oact,0,sizeof(oact));
	
	act.sa_handler = alarm_handler;
	sigemptyset(&act.sa_mask); //屏蔽信号全部置为0
	sigaction(SIGALRM,&act,&oact); //注册SIGALRM信号
	
	alarm(seconds); //若此时进程切出去了，但是时钟到了，但还没有被调度，则此时会存在Bug，跟系统运行的时序有关。	
	pause();
	int ret=alarm(0); //返回剩余时间
	
	sigaction(SIGALRM,&oact,NULL);  //返回注册函数之前的执行流,如果不返回，则SIGALRM函数还是自己定义的动作，若此时再次收到SIGALRM信号
	return ret;
}

int main()
{
	while(1)
	{
		mysleep(1);
		printf("i am wakeup\n");
	}

	return 0;
}
