#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define FILE_NAME "log"
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		exit(1);
	}
	else if(id == 0)
	{
	//	char * my_env[]=
	//	{
	//	 "PATH=/home/admin/mychengxu/2015_10/test10_31/wait",NULL
	//	};
		sleep(3);
		//execl("/bin/ls","ls","-i",NULL);
		//execl("/bin/touch","touch",FILE_NAME,NULL);
		//execlp("ls","ls","-l",NULL);//添加绝对路径
		//execlp("10_31","10_31",NULL);//添加绝对路径
		//execle("10_31","10_31",NULL,my_env);
		char *my_arg[]={
			"10_31",
			NULL
		};
		//execv("/bin/ls",my_arg);
		execvp("10_31",my_arg);
		printf("you should not \n");
		exit(0);
	}
	else
	{
		printf("father is begin wait...\n");
		pid_t child_id = waitpid(id,NULL,0);
		if(child_id == id)
		{
			printf("wait success\n");
		}
		else
		{
			printf("wait failed\n");
		}
	}

	return 0;
}
