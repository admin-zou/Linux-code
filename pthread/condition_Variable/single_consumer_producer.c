//单消费者，单生产者
#include <pthread.h>
#include "thread_list.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//初始化lock 互斥锁
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; //初始化cond 条件变量

node_ptr head = NULL;

void* producer(void* arg)
{
	int data = 0;
	while(1)
	{
			pthread_mutex_lock(&mutex); //1.lock
			push_front(head, data++);
			printf("product data:%d \n",data);
			pthread_mutex_unlock(&mutex); //2.unlock
			printf("you can consume now\n");
			pthread_cond_signal(&cond); // 3. 唤醒等待队列上的一个等待线程,pthread_cond_wait(&cond,&mutex)成功并返回;
		  //pthread_mutex_unlock(&mutex);//放到此处和上面的地方都可以
		sleep(1);
	}
}

void* consumer(void* arg)
{
	elem_type data;
	
	while(1)
	{
			pthread_mutex_lock(&mutex);  //上锁,保证wait操作的原子性
			while(is_empty(head))
			{//
				printf("data is empty,wait cond...\n");
				pthread_cond_wait(&cond,&mutex);//效果相当于unlock（mutex），只有cond条件满足时唤醒，该函数将调用线程放入等待队列，然后解锁，成功返回后mutex又会锁上
				printf("product done...,call consume...\n");
			}
			//int ret = pop_front(head,&data);
			int ret = pop_back(head,&data);
			if(ret != False)
			{
				printf("consume data:%d \n",data);
			}
			else 
			{
				printf("no data to consume\n");
			}
			pthread_mutex_unlock(&mutex);  //开锁
			sleep(2);
	}
}

int main()
{
	init_list(&head);
	pthread_t tid1,tid2;

	pthread_create(&tid1, NULL, producer, NULL);
	pthread_create(&tid2, NULL, consumer, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

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
    return 1;
}
*/
