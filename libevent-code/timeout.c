#include <stdio.h>
#include <event.h>

void Ontime(int sock, short event, void *arg)
{
	printf("Game over\n");

	struct timeval tv;
	tv.tv_sec = 1;
	tv.tv_usec = 0;

	//事件执行后，默认被删除，需要重新add，是它重复执行
	event_add( (struct event*)arg,&tv );
}

int main()
{
	event_init();

	//设置定时器回调函数
	struct event evTime;
	evtimer_set(&evTime, Ontime, &evTime);

	struct timeval tv;  //ls后执行
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	
	//添加事件
	event_add(&evTime,&tv);
	
	//循环派发事件
	event_dispatch();
	return 0;
}
