#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define SOCK_SIZE 512

int main()
{
	int fd[2];
	int ret = socketpair(AF_LOCAL, SOCK_STREAM, 0 ,fd); //int socketpair(int domain, int type, int protocol, int fd[2]) -->  domain Unix域间套接字   type在此程序选择的是面向字节流服务
	if(ret != 0)
	{
		perror("socketpair()");
		return -1;
	}

#ifdef _DEBUG_
	printf("fd[0]: %d\n",fd[0]);
	printf("fd[1]: %d\n",fd[1]);
#endif

	pid_t id=fork();
	if(id < 0 )
	{//error
		perror("fork()");
		return -1; 
	}
	else if(id == 0)
	{//child

			close(fd[0]);//use fd[1] for write and read
	
			char buf[SOCK_SIZE];
			char* msg_c="i know";

			while(1)
			{
				memset(buf, 0, sizeof(buf));
				
				//write
				write(fd[1], msg_c, strlen(msg_c)); 
	
				//read
				ssize_t sz = read(fd[1], buf, sizeof(buf)-1);
				buf[sz]='\0';

				printf("child:%d , %s\n",getpid(),buf);
				sleep(1);
			}
	}
	else if(id > 0)
	{//father
			
			close(fd[1]);//use fd[0] for write and read

			char buf[SOCK_SIZE];
			char* msg_f = "i am your father";
			
			while(1)
			{
				//read
				memset(buf, 0, sizeof(buf));
				ssize_t sz=read(fd[0], buf, sizeof(buf)-1);
				buf[sz] = '\0';

				printf("father:%d , %s\n",getpid(),buf);
			
				//write
				write(fd[0], msg_f, strlen(msg_f));
				sleep(1);
			}
	}
	else
	{}

	return 0;
}
