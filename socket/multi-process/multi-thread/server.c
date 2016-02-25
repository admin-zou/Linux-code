#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


static void usage()
{
	printf("Usage: ./server [ip] [port]\n");
}

int start(char* ip,short port) //duankou
{
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_fd < 0)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;  //address family
	local.sin_port = htons(port); //port : host -> net
	inet_aton(ip,&local.sin_addr); //ip:xxx:xxx:xxx
	
	if(bind(socket_fd,(struct sockaddr*)&local,sizeof(local)) == -1)
	{
		perror("bind");
		return -1;
	}

	if(listen(socket_fd, 5) < 0)  //返回一个监听socket
	{
		perror("listen");
		return -1;
	}

	return socket_fd;
}

void echo_data(int new_sock)
{
	while(1)
	{
		char buf[1024];
		memset(buf, '\0', sizeof(buf));
		ssize_t sz = read(new_sock, buf, sizeof(buf)-1);
		if(sz > 0)
		{
			buf[sz] = '\0';
			write(new_sock, buf, sizeof(buf));
			printf("%s\n",buf);
		}
		else if(sz == 0)
		{//
			printf("client is close\n");
			close(new_sock);
			break;
		}
		else
		{//error
			break;
		}
	}
}

static void *servicer(void * arg)
{
	printf("thread is create && detach success\n");
	pthread_detach(pthread_self());
	int new_sock = (int)arg;
	echo_data(new_sock);
}


int main(int argc,char* argv[])
{
    if(argc != 3)
	{
		usage(argv[0]);
		return 1;	
	}

	short port = atoi(argv[2]); //string->int
	
	int listen_sock = start(argv[1],port);
	
	if(listen_sock == -1)
	{
		return 1;
	}
	
	signal(SIGCHLD,SIG_IGN);

	while(1)
	{
		struct sockaddr_in remote;
		memset(&remote, 0 ,sizeof(remote));
		socklen_t len = sizeof(remote);
		int new_sock = accept(listen_sock, (struct sockaddr*)&remote, &len);
		
		if(new_sock < 0)
		{
			perror("accept");
		}
		else
		{
			printf("get a new client \n");
			pthread_t tid;
			int ret = pthread_create(&tid, NULL, servicer, (void*)new_sock);
			if(ret == 0)
			{//success
		
			}
			else
			{//falied
			
			}
		}
	}
	return 0;
}
