#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
	sleep(4);
	printf("begin\n");
	kill(getpid(),SIGINT);  //给一个进程发送信号
	printf("bug\n");
	sleep(10);
}
