#include <stdio.h>
#include <pthread.h>
#define _SIZE_ 1024

//char buf[_SIZE_];
unsigned int buf;
pthread_rwlock_t rwlock;

//读写锁用于读多 写少的情况，同时允许一个写者或多个读者

void* thread_write(void* arg)
{
	char data=0;
	int i=0;

	while(1)
	{
		if(0 == pthread_rwlock_trywrlock(&rwlock))
		{
			buf = data;
			printf("product data %u\n",data++);
			
			pthread_rwlock_unlock(&rwlock);
			
			sleep(2);	
		}
		else
		{
			printf("mybe reader is reading..\n");
		}
	}

	return (void*)1;
}

void* thread_read(void* arg)
{
	while(1)
	{
		if(0 == pthread_rwlock_tryrdlock(&rwlock))
		{
			printf("read:%u\n",buf);

			pthread_rwlock_unlock(&rwlock);
			
			sleep(2);
		}
		else
		{
			printf("mybe writer is writing\n");
		}
	}

	return (void*)1;
}

void* thread_read2(void* arg)
{
	while(1)
	{
		if(0 == pthread_rwlock_tryrdlock(&rwlock))
		{
			printf("read:%u\n",buf);

			pthread_rwlock_unlock(&rwlock);
			
			sleep(2);
		}
		else
		{
			printf("mybe writer is writing\n");
		}
	}

	return (void*)1;
}


int main()
{
	pthread_rwlock_init(&rwlock, NULL);

	pthread_t tid1,tid2,tid3;

	pthread_create(&tid1, NULL, thread_write, NULL);
	pthread_create(&tid2, NULL, thread_read, NULL);
	pthread_create(&tid3, NULL, thread_read, NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);

	pthread_rwlock_destroy(&rwlock);

	return 0;
}
