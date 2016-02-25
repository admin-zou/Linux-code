#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define _FD_NUM_ 512
#define _FD_DEFAULT_VAL -1

typedef struct select_fd
{
	int max_fd;
	int fd_arr[_FD_NUM_];
}select_fd_t;

static void Usage(const char *proc)
{
	printf("%s [ip] []port\n",proc);
}

static void arr_read_fd(fd_set *set, select_fd_t *select_fd)
{
	select_fd->max_fd = _FD_DEFAULT_VAL;
	
	int i = 0;
	for( ; i < _FD_NUM_; ++i)
	{
		if( select_fd->fd_arr[i] != _FD_DEFAULT_VAL)
		{
			FD_SET(select_fd->fd_arr[i], set);
			if(select_fd->fd_arr[i] > select_fd->max_fd)
			{
				select_fd->max_fd = select_fd->fd_arr[i];
			}
		}
	}
}
		
static int add_new_fd(select_fd_t *select_fd, int new_fd)
{
	int i = 1;
	for( ;i < _FD_NUM_; ++i)
	{
		if( select_fd->fd_arr[i] == _FD_DEFAULT_VAL)
		{// no use
			select_fd->fd_arr[i] = new_fd;
			return 0; //success 此时不用更新最大文件描述符
		}
	}
	return 1; //failed
}

static void delete_new_fd(select_fd_t *select_fd, int fd)
{
	int i = 1;
	for( ; i < _FD_NUM_; ++i)
	{
		int cur_fd = select_fd->fd_arr[i];
		if(cur_fd == fd)
		{
			select_fd->fd_arr[i] = _FD_DEFAULT_VAL;
		}
	}
}

static void init_select_set(select_fd_t *select_fd, int listen_fd)
{
	select_fd->max_fd = listen_fd;

	select_fd->fd_arr[0] = listen_fd; //0->listen_fd
	
	int i = 1;
	for( ; i < _FD_NUM_; ++i)
	{
		select_fd->fd_arr[i] = _FD_DEFAULT_VAL;
	}
}

static int read_data_show(int new_fd)
{
	char buf[1024];
	
	ssize_t sz = 0;
	int total = 0;
	while( (sz = read(new_fd, buf+total, 64)) > 0)
	{
		total += sz;
	}
	
	if( sz == 0)
	{//read end
		buf[total] = '\0';
		printf("client data : %s\n",buf);
		return 0; //read end ,return 0
	}
	else if(sz < 0)
	{
		perror("read");
		return -1;
	}
	else
	{
		//do nothing
	}
	
}

int start(const char *ip, short port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket");
		exit(1);
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = inet_addr(ip);

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0 )
	{
		perror("blind");
		//close(sock);
		exit(1);
	}

	if(listen(sock, 5) < 0)
	{
		perror("listen");
		exit(1);
	}

	return sock;
}



int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	
	int port = atoi(argv[2]); //port
	
	int listen_sock = start(argv[1]/*ip*/, port); // listen_sock is ready
	if(listen_sock < 0)
	{
		exit(2);
	}
	
	select_fd_t select_set;
	
	init_select_set(&select_set, listen_sock);

	fd_set r_set; //read file fd set

	while(1)
	{
		FD_ZERO(&r_set); //set 0
		arr_read_fd(&r_set, &select_set); // add 向读集里添加select_set
		
		struct timeval timeout={5,0}; //非阻塞式等待
		switch(select(select_set.max_fd+1, &r_set, NULL, NULL, &timeout))
		{
			case 0:  //timeout
				perror("timeout");
					break;
			case -1: //error
				perror("select");
					break;
			default: //success
				{
					int i = 0;
					for( ;i< _FD_NUM_; ++i)
					{
							int fd = select_set.fd_arr[i];
							if(i == 0 && FD_ISSET(fd,&r_set))//new connect
							{
								struct sockaddr_in client;
								socklen_t len = sizeof(client);
								int new_fd = accept(fd,(struct sockaddr*)&client, &len);
								if(new_fd == -1)
								{
									perror("accept");
									continue;
								}

								if(0 == add_new_fd(&select_set, new_fd))
								{//add success
									// do nothing	
								}
								else
								{//add error,arr is full
									close(fd);
								}
								
								continue;
							}
							
							if(fd != _FD_DEFAULT_VAL && FD_ISSET(fd, &r_set))
							{//read
								if( 0 == read_data_show(fd) )
								{
									delete_new_fd(&select_set, fd);
									close(fd);
								}
								else
								{
										//do nothing
								}
							}
					}		
				}	
				break;
		}
	}
return 0;	


