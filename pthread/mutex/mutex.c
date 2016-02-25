#include <pthread.h>
#include <stdio.h>

int count = 0;

int flag=0;
//pthread_mutex_t  _mylock;  //创建一个mutex变量

int lock_init(pthread_mutex_t *_lock)//初始化锁
{
   //return pthread_mutex_init(_lock,NULL);
}

int lock_destroy(pthread_mutex_t *_lock)
{
	//return pthread_mutex_destroy(_lock);
}

int lock(pthread_mutex_t *_lock) // 加锁
{
	//return pthread_mutex_lock(_lock);
}

int unlock(pthread_mutex_t *_lock)//解锁
{
	//return pthread_mutex_unlock(_lock);
}


void *thread1(void* arg)
{
	int i =5000;
	while(i)
	{
		//lock(&_mylock);		
		int tmp = count;
		printf("thread1,%d\n",tmp);
		count=tmp+1;
		i--;
		//unlock(&_mylock);
	}
	return NULL;
}

void *thread2(void* arg)
{
	int i =5000;
	while(i)
	{
		//lock(&_mylock);
		int tmp = count;
		printf("thread2,%d\n",tmp);
		count=tmp+1;
		i--;
		//unlock(&_mylock);
	}
	return NULL;
}


int main()
{
	pthread_t tid1,tid2;
	//lock_init(&_mylock);
	int ret1 = pthread_create(&tid1, NULL, thread1, NULL);
	int ret2 = pthread_create(&tid2, NULL, thread2, NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("ret:%d\n",count);
	//lock_destroy(&_mylock);
	return 0;
}

