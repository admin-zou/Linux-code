#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void handler(int sig)
{
	printf("signal it already! pid: %d\n",getpid());
}

//提供一个信号处理函数,要求内核在处理该信号时切换到用户态执去执行这个处理函数,这种方式称为捕捉(Catch)一个信号。

int main()
{
	//此函数参数是SIGINT，则处理的是ctrl-c，执行时会调用handler函数，而不是正常退出，要想退出，用ctrl-\退出
	signal(SIGINT,handler);  
	while(1)
	{
		printf("this is a test\n");
		sleep(1);
	}
	return 0;
}
