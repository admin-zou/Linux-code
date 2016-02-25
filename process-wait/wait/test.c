//非阻塞式等待
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>

int main()
{
	pid_t  id = fork();
	pid_t  childid;
	if(id < 0)
	{
		perror("fork");
		exit(0);
	}
	else if(id == 0)
	{
		printf("this is child:pid%d :ppid:%d\n",getpid(),getppid());
		//sleep(100);
		sleep(5);
		exit(5);
	}
	else
	{
		printf("this is father:pid:%d ppid:%d\n",getpid(),getppid());
		int status = 0;
		//childid = waitpid(id, &status, 0);
	  do{//非阻塞式等待
			childid = waitpid(id, &status, WNOHANG);
			sleep(1);
			printf("father is wait\n");
		}while(childid <= 0);
		printf("wait success,pid is:%d\n",childid);
		printf("exit code,%d\n",0xff&(status>>8));
		  //printf("exit code,%d\n",WEXITSTATUS(status));
		  //printf("signal no,%d\n",status&0xff);
		//printf("signal no,%d\n",WSTOPSIG(status)); //返回是否异常退出
		//printf("signal no,%d\n",WIFSIGNAKED(status));
		printf("signal no,%d\n",WTERMSIG(status));//返回异常退出的信号量编号
		//if(childid >= 0)
		//	{
		//		printf("wait success,pid is:%d\n",childid);
		//		printf("exit code,%d\n",0xff&(status>>8));
		//		printf("signal no,%d\n",status&0xff);
		//	}
		//	else
		//	{
		//		perror("wait failed\n");
		//	}
	//	childid= wait(&status);
	//	if(childid < 0)
	//	{
	//		perror("wait failed\n");
	//	}
	//	else
	//	{
	//		printf("success,%d\n",childid);
	//		printf("exit code,%d\n",0xff&(status>>8));
	//		printf("signal no,%d\n",status&0xff);
	//	}
	}
	return 0;
}
