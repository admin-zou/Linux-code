#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int i=0;

	for(i=0; i<2; i++)
	{
		fork();
		printf("ppid:%d pid:%d i=%d \n",getppid(),getpid(),i);
	}
	sleep(2);
	return 0;
}
