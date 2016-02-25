#include <stdio.h>
#include <pthread.h>

void* pthread_run(void* arg)
{
	int count=3;
	while(count)
	{
		printf("this is pthread,pid:%d,pthreadif:%u\n",getpid(),pthread_self());	
		count--;
	}

	return 0;
}

int main()
{
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, pthread_run, (void*)1);

	pthread_join(tid,NULL);//阻塞时等

	sleep(3);

	printf("this is main pthread,pid:%d,pthreadis:%u\n",getpid(),pthread_self());	

	return 0;
}
