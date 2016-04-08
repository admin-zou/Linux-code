#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "ring.h"

//pthread_mutext_t mutex1;
//pthread_mutext_t mutex2;
ring_t ring_buffer;
//这里定义为全局的原因是为了主线程和子线程共享数据，因为main函数里定义的属于main函数的主线程，子线程一般情况下不能共享。
//pthread_create()的第四个参数”可传递参数“将主线程的栈里的数据传递个子线程

sem_t product_blank_count; //资源量
sem_t consum_data_count;   //资源量

void* producter(void* arg)
{//producter
	int data = 0;
	while(1)
	{
		sem_wait(&product_blank_count); //p 操作--，可生产资源减少1
		put_data(&ring_buffer, data);//互斥是通过is_empty函数实现的，可以引入信号量实现互斥
		sem_post(&consum_data_count); // v操作++，可消费资源加上1	
	  	printf("producter data is %d \n",data);
		sleep(1);
		++data;
	}
}

void* consumer(void* arg)
{//consumer
	int tmp = 0;
	while(1)
	{
		sem_wait(&consum_data_count); //p 操作 --   可消费资源减少1
    	get_data(&ring_buffer, &tmp); //互斥是通过is_empty函数实现的，可以引入信号量实现互斥
	  	sem_post(&product_blank_count); // v操作++  可生产资源加上1
	    printf("cosumer data is:%d \n",tmp);
	  	//sleep(1);
	}
}


int main()
{
//信号量
	sem_init(&product_blank_count, 0, _SIZE_);
 	sem_init(&consum_data_count, 0 , 0);
//线程的栈空间是私有的，栈里的数据可以共享,所以将ring_buffer 定义为全局变量（在ring.c里定义）
	pthread_t tid1,tid2;
//create
	pthread_create(&tid1, NULL, producter, NULL);
	pthread_create(&tid2, NULL ,consumer, NULL);
//join
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
//destroy
	sem_destroy(&product_blank_count);
	sem_destroy(&consum_data_count);
	return 0;
}
