//3.如果所有指向管道读端的⽂文件描述符都关闭了(管道读端的引⽤用计数等于0),这时有进程向管道的写端write,那么该进程会收到信号SIGPIPE,通常会导致进程异常终止

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int fd[2];
    int ret	= pipe(fd);
	if(ret == -1)
	{//failed
			perror("pipe");
			exit(-1);
	}
	pid_t id = fork();
	if(id < 0)
	{
			perror("fork");
			exit(2);
	}
	else if(id == 0)
	{//child
			close(fd[0]); //write    close read
			char* msg = "hello world";
			while(1)
			{
				write(fd[1],msg, strlen(msg));
				sleep(1);
			}
	}
	else
	{//father
			close(fd[1]); //read   close write
			int count = 10;
			char buf[256];
			while(count)
			{
				memset(buf,'\0',sizeof(buf));
				ssize_t size = read(fd[0], buf, sizeof(buf)-1);
				if(size > 0)
				{	
					buf[size] = '\0';
					printf("%d:%s\n",count, buf);
				}
				count--;
			}
			close(fd[0]);  //close read，所有读端关闭了，写端收到SIGPIPE信号
			int status = 0;
			pid_t ret = waitpid(id, &status, 0);
			if(ret == id)
			{//success
			  printf("code : %d,sig: %d \n",0xff&(status>>8),0xff&status);
			}
	}
	return 0;
}
