#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "ring.h"


pthread_mutex_t mutex1,mutex2;

ring_t ring_buffer;
//这里定义为全局的原因是为了主线程和子线程共享数据，因为main函数里定义的属于main函数的主线程，子线程一般情况下不能共享。
//pthread_create()的第四个参数”可传递参数“将主线程的栈里的数据传递个子线程


sem_t product_blank_count;
sem_t consum_data_count;

void* producter(void* arg)
{
	int data = 0;
	while(1)
	{
	 
	 pthread_mutex_lock(&mutex1); 
	 //虽然里面或者外面加锁结果一样，不过个人感觉外面上锁更优，体现同步，因为printf函数应该在锁范围内，才能保证同步

	 sem_wait(&product_blank_count); //p 操作 --  可生产资源减少1
	 
//	 pthread_mutex_lock(&mutex1);
		
	 	put_data(&ring_buffer, data);
			//互斥是通过is_empty函数实现的，可以引入信号量实现互斥
	
//	 pthread_mutex_unlock(&mutex1);
	 
	 sem_post(&consum_data_count); // v操作++	   可消费资源加上1
	
 		 printf("producter--1 data is %d \n",data);
	 
	 pthread_mutex_unlock(&mutex1);
	
    	sleep(1);  //如果不等待，消费者无法被执行
		++data;
	}
}

void* producter2(void* arg)
{
	int data = 0;

	while(1)
	{
	  pthread_mutex_lock(&mutex1);
	  
	  sem_wait(&product_blank_count); //p 操作 --  可生产资源减少1
	
//	  pthread_mutex_lock(&mutex1);
	
	  	  put_data(&ring_buffer, data);//互斥是通过is_empty函数实现的，可以引入信号量实现互斥

//	  pthread_mutex_unlock(&mutex1);
	
	  sem_post(&consum_data_count); // v操作++	   可消费资源加上1
		
		  printf("producter--2 data is %d \n",data);
	
	  pthread_mutex_unlock(&mutex1);
	
	    sleep(1);
		++data;
	}
}

void* consumer(void* arg)
{
	int tmp=0;
	while(1)
	{
	  pthread_mutex_lock(&mutex2);
	 
	  sem_wait(&consum_data_count); //p 操作 --   可消费资源减少1
	  	
//	  pthread_mutex_lock(&mutex2);
	
	  	  get_data(&ring_buffer, &tmp);//互斥是通过is_empty函数实现的，可以引入信号量实现互斥

//	  pthread_mutex_unlock(&mutex2);
	
	  sem_post(&product_blank_count); // v操作++  可生产资源加上1
	
  		  printf("cosumer--1 data is:%d \n",tmp);
	 
	  pthread_mutex_unlock(&mutex2);
		
	 	sleep(1);
	}
}

void* consumer2(void* arg)
{
	int tmp=0;
	while(1)
	{
	  pthread_mutex_lock(&mutex2);
	 
	  sem_wait(&consum_data_count); //p 操作 --   可消费资源减少1
	
//	  pthread_mutex_lock(&mutex2);
	
	  	  get_data(&ring_buffer, &tmp);//互斥是通过is_empty函数实现的，可以引入信号量实现互斥

//	  pthread_mutex_unlock(&mutex2);
	
	  sem_post(&product_blank_count); // v操作++  可生产资源加上1
	
  	  	  printf("cosumer--2 data is:%d \n",tmp);
	  pthread_mutex_unlock(&mutex2);
		
	 	sleep(1);
	}
}


int main()
{
//初始化互斥锁
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);

//初始化信号量
	sem_init(&product_blank_count, 0, _SIZE_);
 	sem_init(&consum_data_count, 0 , 0);


//线程的栈空间是私有的，栈里的数据可以共享,所以将ring_buffer 定义为全局变量（在ring.c里定义）
	pthread_t tid1,tid2,tid3,tid4;

	pthread_create(&tid1, NULL, producter, NULL);	
	pthread_create(&tid2, NULL ,consumer, NULL);
	pthread_create(&tid3, NULL, producter2, NULL);
	pthread_create(&tid4, NULL, consumer2, NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);

	sem_destroy(&product_blank_count);
	sem_destroy(&consum_data_count);

	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);

	return 0;
}
