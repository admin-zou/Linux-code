#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	sleep(3);
	printf("pid is:%d\n",getpid());
	abort();
	//	raise(SIGSEGV);
	sleep(3);
	printf("pid is:%d\n",getpid());
	return 0;
}
