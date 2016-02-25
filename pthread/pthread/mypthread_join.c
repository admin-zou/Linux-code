#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *pthread1(void *val)
{
	printf("thread 1 returning...\n ");

	return (void*)1;
}

void *pthread2(void *val)
{
	printf("thread 2 exit...\n");

	pthread_exit((void*)2);
}

void *pthread3(void *val)
{
	while(1)
	{
		printf("pthread 3 is runing,wait for cancel...\n");
		sleep(1);
	}

	return NULL;
}

int main()
{
	pthread_t tid;
	void *tret;

	// thread 1 return 
	pthread_create(&tid, NULL, pthread1,NULL);
	pthread_join(tid,&tret);
	printf("thread return,thread id is:%u,return code is:%d\n",(unsigned long)tid, (int)tret);

	
	//thread 2 exit
	pthread_create(&tid, NULL, pthread2, NULL);
	pthread_join(tid,&tret);
	printf("thread exit,thread id is:%u,return code is:%d\n",(unsigned long)tid, (int)tret);


	//thread 3 cancel by other
	pthread_create(&tid, NULL, pthread3, NULL);
	sleep(3);
	pthread_cancel(tid);
	pthread_join(tid,&tret);
	printf("thread return,thread id is:%u,return code is:%d\n",(unsigned long)tid, (int)tret);


	return 0;
}




