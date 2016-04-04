#include <stdio.h>
#include <stdlib.h>
#include <event.h>
#include <unistd.h>
#include <evhttp.h>

void reHandler( struct evhttp_request *req, void *arg)
{
	struct evbuffer *buf = evbuffer_new();

	//发送响应
	evbuffer_add_printf(buf, "Thanks for request");
	evhttp_send_reply(req, HTTP_OK,"client",buf);

	evbuffer_free(buf);

	return ;
}

int main(int argc, char *argv[])
{
	short port = 8080;
	const char *ip = "127.0.0.1";
	struct evhttp * httpserver = NULL;

	event_init();
		
	//启动http服务器
	httpserver = evhttp_start(ip,port);
	
	//回调函数
	evhttp_set_gencb(httpserver, reHandler, NULL);
	printf("server start on port%d\n",port);

	event_dispatch();

	return 0;
}
