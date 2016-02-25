#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <string.h>
#include <fcntl.h>

#define EVENT_SIZE 64

void Usage(const char* proc)
{
	printf("Usage :%s [ip] [port]\n",proc);
}

//if 0 read success .and write success and remote close
static int _read_write_data(int fd)
{
	char buf[10240];
	int len = sizeof(buf)-1;
	ssize_t sz=0;
	int total = 0 ;
	while( (sz = recv(fd, buf+total, len, 0)) > 0 )
	{
		total+=sz;

		if(sz <len)
		{
			break;
		}
	}
	if(total > 0)
	{
		buf[total] = '\0';
		printf("%s \n",buf);
		sprintf(buf, "HTTP/1.1 200 ok\r\nContent-Lenth:%d\r\nhello world ^_^",13);

		send(fd, buf, strlen(buf), 0);

	}
	return 0;
}

static void set_noblock(int new_sock)
{
	int fl  = fcntl(new_sock, F_GETFL);
	if(fl < 0)
	{
		perror("fcntl");
		exit(1);
	}
	fcntl(new_sock, F_SETFL, fl | O_NONBLOCK);
}

int start(const char* ip, short port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	if(sock < 0)
	{
		perror("sock");
		return -1;
	}

	int flag = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = inet_addr(ip);

	if( bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
	{//failed
		perror("bind");
		return -1;
	}

	if( listen(sock ,5) < 0 )
	{
		perror("listen");
		return -1;
	}

	return sock;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		Usage("argv[1]");
		return 1;
	}

	const char* ip = argv[1];
	int port = atoi(argv[2]);
	int listen_sock = start(ip, port);

	int epfd = epoll_create(250);
	if(epfd < 0 )
	{
		perror("epoll_create");
		exit(1);
	}


	struct epoll_event  _event;
	_event.events = EPOLLIN;
	if(	epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &_event) < 0 )
	{
		perror("epoll_ctl");
		exit(1);
	}

	struct epoll_event _ready_event[EVENT_SIZE];
	int _ready_event_size = EVENT_SIZE;
	int timeout=3000;
	int _ready_num = 0;
	while(1)
	{//accept
		switch( _ready_num =  epoll_wait(epfd, _ready_event, _ready_event_size, timeout) )
		{
			case 0: //timeout
				printf("timeout");
					break;
			case 1: //error
				perror("epoll");
					break;
			default://success,fd event,
				{
						int i = 0;
						for(; i < _ready_num; ++i)
						{
							int fd = _ready_event[i].data.fd;
							if( fd == listen_sock && _ready_event[i].events & EPOLLIN ) 	
							{//listen sock
									struct sockaddr_in client;
									socklen_t len = sizeof(client);
									int new_sock  = accept( fd,(struct sockaddr*)&client, &len);
									if( new_sock < 0)
									{
										perror("accept");
										continue;
									}
								
									set_noblock(new_sock);
									//accept data
									_event.events = EPOLLIN | EPOLLOUT | EPOLLET;
									if(	epoll_ctl(epfd, EPOLL_CTL_ADD, new_sock, &_event) < 0 )
									{
										perror("epoll_ctl");
										close(new_sock);
										continue;
									}
							}
							else if( ( _ready_event[i].events & EPOLLIN) && (_ready_event[i].events & EPOLLOUT)  ) 	
							{// 
									if(_read_write_data(fd) == 0)
									{// read suceess and client 
										close(fd);
										epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
									}
							}
						}
				}
				break;
		}

	}

	return 0;
}
