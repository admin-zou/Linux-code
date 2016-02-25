#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t id = fork();
	if(id < 0 )
	{
		perror("fork");
		exit(1);
	}
	else if(id == 0)
	{//子进程
		printf("这是子进程 id:%d  ppid:%d\n",getpid(),getppid());
		sleep(5);
		exit(255);
	}
	else
	{//父进程
	   printf("这是父进程 id:%d  ppid:%d\n",getpid(),getppid());
	   int status = 0;

	   pid_t ret = wait(&status);
	   if(ret < 0 )
	   {
	  		 perror("wait");
	   }
	   else
	   {
	   		printf("wait success!,wait pid is:%d\n",ret);
	   		printf("child quite info:%d\n",0xff & (status>>8)); //次低八位为子进程的退出码
	   		printf("child get signal no:%d\n",0xff & status);  //信号，可以说明正常退出或异常退出 
	   }
	}
	  
	printf("this proc is quite, id %d\n",getpid());
	  
	exit(8);
	
	return 0;
}

