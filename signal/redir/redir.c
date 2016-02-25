#include <stdio.h>
#include <signal.h>
#include <errno.h>

int flag=0;
void handler(int flag)
{
	int tmp=errno;
	printf("catch a sig %d\n",flag);
	errno=tmp;
}

int main()
{
	signal(SIGINT,handler);
	while(!flag)
	{
		printf("i am living\n");
		sleep(1);
	}
	return 0;
}
