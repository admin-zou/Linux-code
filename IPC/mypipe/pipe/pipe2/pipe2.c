//2.如果有指向管道写端的⽂文件描述符没关闭(管道写端的引⽤用计数⼤大于0),⽽而持有管道写端的 进程也没有向管道中写数据,这时有进程从管道读端读数据,那么管道中剩余的数据都被读取后,再次read会阻塞,直到管道中有数据可读了才读取数据并返回


#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
int main()
{//father write, child read
 int fd[2];
 int ret  = pipe(fd); 
 if(ret < 0)
 {//failed
 	perror("pipe");
	exit(1);
 }
#ifdef _DEBUG_
 printf("pipe success,fd[0]:%d, fd[1]:%d\n":fd[0],fd[1]);
#endif
 pid_t id = fork();
 if(id <0)
 {//
		 perror("fork");
		 close(fd[0]);
		 close(fd[1]);
		 exit(2);
 }
 else if(id == 0)
 {//child
	close(fd[1]);  //关闭写，子进程读文件		 
#define _SIZE 1024 
	char buf[_SIZE];
 	memset(buf,0,sizeof(buf));
	unsigned int count = 0;
	int i = 10;
//	sleep(10);
	while(i)
	{
		ssize_t s = read(fd[0], buf, sizeof(buf)-1);
		if(s > 0)
		{
			buf[s] = '\0';
			printf("child pid:%d ,%s %d\n", getpid(), buf, count++);
		}
		else if(s == 0)
		{
			printf("writer stop writing,close(fd[1])\n");
			break;
		}
		i--;
	}
	close(fd[0]);
	exit(0);
 }
 else
 {//father
 	close(fd[0]); //关闭读，父进程写文件
 	printf("father: %d\n",getpid());
	char * msg = "you are a good man";
	int i = 10;
	unsigned int count = 0;
//	while(i)
//	{
//		write(fd[1], msg, strlen(msg));
//		printf("i am write...%d \n",count++);
//		sleep(1);
//		i--;
//	}
	while(i)
	{
		write(fd[1], msg, strlen(msg));
		usleep(1000);
		printf("i am write...%d \n",count++);
		if(i == 5)
		{
			sleep(10);
		}
		sleep(1);
		i--;
	}
	close(fd[1]);
 	int ret = waitpid(id, NULL, 0);
 	if(ret == id)
	{//success
		printf("wait success\n");
	}
	else
	{
		perror("waitpid");
		exit(3);
	}
 }
 return 0;
}

