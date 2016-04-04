#include <stdio.h>
#include <string.h>
#include <event.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

struct event_base *base;

void onRead(int clifd, short ievent, void *arg)
{
	int ilen;
	char buf[1500];
	ilen = recv(clifd, buf,1500,0);

	if(ilen <= 0)
	{
		printf("client close\n");

		struct event *pread = (struct event*)arg;
		event_del(pread);
		delete pread;

		close(clifd);
		return ;
	}
	buf[ilen] = '\0';
	printf("Accept: %s\n",buf);
	
}

void onAccept(int sock, short ievent, void *arg)
{
	int clifd;
	struct sockaddr_in cliaddr;

	socklen_t len = sizeof(cliaddr);
	clifd = accept(sock, (struct sockaddr*)&cliaddr, &len);

	struct event *pread = new event;
	event_set(pread, clifd, EV_READ|EV_PERSIST,onRead,pread); //注册读写事件
	event_base_set(base,pread);
	event_add(pread,NULL);
}

int main()
{
	int sock;
	struct sockaddr_in saddr;

	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8080);
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sock = socket(AF_INET, SOCK_STREAM, 0);
	bind(sock, (struct sockaddr*)&saddr, sizeof(saddr));
	listen(sock,5);

	base = event_base_new(); //初始化

	//初始化一个连结事件，EV_PRESIST指定重复执行该事件
	struct event evlisten;
	event_set(&evlisten, sock, EV_READ | EV_PERSIST, onAccept, NULL);

	//设置base事件
	event_base_set(base, &evlisten);
	//添加事件
	event_add(&evlisten,NULL);
	//事件循环
	event_base_dispatch(base);
	return 0;
}
