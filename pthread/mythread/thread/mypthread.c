#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * thread_run(void* arg)
{
   
//	printf("arg : %d\n",(int)arg); //参数
	while(1)
	{
		printf("threadid:%u this is thread run,pid:%d\n",pthread_self(),getpid());
		sleep(2);
	}

//终止线程,调用exit退出
//	sleep(2);
//	exit(1);

}

void * thread_exit(void* arg)
{
	
//case 1 线程调用return退出
//	int count=3;
//	while(count)
//	{
//		printf("thread is run\n");
//		sleep(1);
//		count--;
//	}
//	return (void*)1;

//case 2 
 
	int count=3;
	while(count)
	{
		printf("thread is run\n");
		sleep(1);
		count--;
	}

	pthread_exit(arg); 
  
//	pthread_cancel((pthread_t)arg);
}



int main()
{
	pthread_t tid;
	
	int ret = pthread_create(&tid, NULL, thread_run, (void*)1);//if success return 0

	int rret = pthread_create(&tid, NULL, thread_exit, (void*)1);//if success return 0

	sleep(3);

//	printf("new threadid:%u\n",tid);
//	while(1)
//	{
//		printf("threadid:%u this is main thread run,pid:%d\n",pthread_self(),getpid());
//		sleep(1);
//	}

	while(1)
	{
		printf("this is main thread run,pid:%d\n",getpid());
		sleep(1);
	}

   	return 0;
}
