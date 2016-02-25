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

	if(socket_fd == -1)
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

	if(listen(socket_fd, 5) == -1)  //返回一个监听socket
	{
		perror("listen");
		return -1;
	}

	return socket_fd;
}

void recycle(int sig)
{
	pid_t id;
	while((id=waitpid(-1, NULL, WNOHANG)) > 0)
	{
		printf("wait child success ,pid:%d:\n",id);
	}
}

int main(int argc,char* argv[])
{
    if(argc != 3)
	{
		usage();
		return 1;	
	}

	short port = atoi(argv[2]); //string->int
	
	int listen_sock = start(argv[1],port);
	
	if(listen_sock == -1)
	{
		return 1;
	}

	signal(SIGCHLD,recycle);

	while(1)
	{
		struct sockaddr_in remote;
		memset(&remote, 0 ,sizeof(remote));
		socklen_t len = sizeof(remote);
		int new_sock = accept(listen_sock, (struct sockaddr*)&remote, &len);
		
		if(new_sock == -1)
		{
			perror("accept");
		}
		else
		{
			printf("server:get a new client \n");
			pid_t id =fork();

			if(id == 0)
			{//chirld
					close(listen_sock);
					while(1)
					{
						char buf[1024];
						memset(buf, '\0',sizeof(buf));
						ssize_t sz = read(new_sock, buf , sizeof(buf)-1);
						if(sz > 0)
						{//read data and remote is exit ...
							buf[sz] = '\0';
							write(new_sock, buf, strlen(buf)); //回写
							printf("server:%s \n",buf);
						}
						else if(sz == 0)
						{//read the end
							printf("client is close\n");
							close(new_sock);
							break;
						}
						else
						{
							//do nothing
							break;
						}
					}
					exit(0);
			}
			else
			{//father
				//close();
			}
		}
	}
	return 0;
}
