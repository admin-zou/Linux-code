#include <stdio.h>
#include <signal.h>
//编译时加 -O3 优化
volatile int flag=1;
int flag=1;

void handler(int sig)
{
	flag=0;
}

int main()
{
	signal(SIGQUIT,handler);
	while(flag);
//	{
//		printf("i am angery\n");
//		sleep(1);
//	}
	return 0;
}
