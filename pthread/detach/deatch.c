#include <stdio.h>
#include <pthread.h>

void *thread_run(void* arg)
{
	//pthread_detach(pthread_self());
	//while(1)
	//{
		printf("this is pthread run\n");
	//	sleep(1);
	//}
	pthread_cancel(pthread_self());
	sleep(10);
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread_run, NULL);
	sleep(3);
	printf("main pthread run\n");
	pthread_detach(tid);
	printf("main pthread set detach done...\n");
  
	
	//cnacel? 
	/*printf("begin cancle\n");
	sleep(1);
	int ret = pthread_cancel(tid);
	if(ret != 0)
	{
		printf("error:%d,%s\n",ret,strerror(ret));
		return 1;
	}
    */
    /*
	//join 这样做不允许,只要线程分离了，就不能再join了
	printf("begin join");
	sleep(2);
	int ret = pthread_join(tid, NULL);
	if(ret != 0)
	{
		printf("%d: %s\n",ret, strerror(ret));
		return 1;
	}
    */	
	//printf("main pthread end\n");
	return 0;
}
