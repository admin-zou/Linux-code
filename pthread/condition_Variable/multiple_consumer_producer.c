//多生产者，多消费者
#include <pthread.h>
#include "thread_list.h"

int data = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//lock 互斥锁
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; //cond 条件变量

node_ptr head = NULL;


//每两个个消费者或生产者的工作是相同的，所以代码也完全相同

void* producer1(void* arg)
{
	//int data = 0;
	while(1)
	{
		pthread_mutex_lock(&mutex);  //上锁，同步
		
			push_front(head, data++);
			printf("1 product data:%d \n",data);
		
		pthread_mutex_unlock(&mutex); //开锁
			
			printf("1 you can consume now\n");
		
		pthread_cond_signal(&cond); //条件成熟，唤醒cond，可以消费了

			sleep(1);
	}
}

void* producer2(void* arg)
{
	//int data = 0;
	while(1)
	{
		pthread_mutex_lock(&mutex);
	
			push_front(head, data++);
			printf("2 product data:%d \n",data);
	
		pthread_mutex_unlock(&mutex);
	
			printf("2 you can consume now\n");
	
		pthread_cond_signal(&cond); //条件成熟，唤醒cond
			sleep(1);
	}
}

void* consumer1(void* arg)
{
	elem_type data;
	while(1)
	{
		pthread_mutex_lock(&mutex);   //先上锁
		
			while(is_empty(head))
			{//
				printf("1 data is empty,wait cond...\n");
		
		pthread_cond_wait(&cond,&mutex); 
			//效果相当于unlock（mutex），只有cond条件满足时唤醒,被调用可以说明生产者已经完成生产工作了，产生了可用产品
			
				printf("1 product done...,call consume...\n");
			}
	
			int ret = pop_front(head,&data);
				//int ret = pop_back(head,&data);
			if(ret != False)
			{
				printf("1 consume data:%d \n",data);
			}
			else 
			{
				printf("1 no data to consume\n");
			}
			
		pthread_mutex_unlock(&mutex);  //开锁
		
			sleep(2);
	}
}

void* consumer2(void* arg)
{
	elem_type data;

		while(1)
		{
	
			pthread_mutex_lock(&mutex);
		
				while(is_empty(head))
				{//
					printf("2 data is empty,wait cond...\n");
			
			pthread_cond_wait(&cond,&mutex);
		   		//同上
			
					printf("2 product done...,call consume...\n");
				}

				int ret = pop_front(head,&data);
				//int ret = pop_back(head,&data);
				if(ret != False)
				{
					printf("2 consume data:%d \n",data);
				}
				else 
				{
					printf("2 no data to consume\n");
				}
		
			pthread_mutex_unlock(&mutex);
			
				sleep(2);
	}
}


void* consumer3(void* arg)
{
	elem_type data;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		
			while(is_empty(head))
			{//
				printf("3 data is empty,wait cond...\n");
				
			pthread_cond_wait(&cond,&mutex); 
				//同上
				
				printf("3 product done...,call consume...\n");
			}
	
			int ret = pop_front(head,&data);
			//int ret = pop_back(head,&data);
			if(ret != False)
			{
				printf("2 consume data:%d \n",data);
			}
			else 
			{
				printf("3 no data to consume \n");
			}

		pthread_mutex_unlock(&mutex);
			
			sleep(2);
	}
}

int main()
{
	init_list(&head);
	pthread_t tid1,tid2,tid3,tid4,tid5;

//分别为每个生产者和消费者创建线程，执行相应的功能
	pthread_create(&tid1, NULL, producer1, NULL);
	pthread_create(&tid2, NULL, consumer1, NULL);
	pthread_create(&tid3, NULL, producer2, NULL);
	pthread_create(&tid4, NULL, consumer2, NULL);
	pthread_create(&tid5, NULL, consumer3, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	pthread_join(tid5, NULL);
	
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	
	return 0;
}

/*
int main()
{
    node_ptr head;
    init_list(&head);
    push_front(head,1);
    show_list(head);
    push_front(head,2);
    show_list(head);
    push_front(head,3);
    show_list(head);
    push_front(head,4);
    show_list(head);
    push_front(head,5);
    show_list(head);
    return 0;
}
*/
