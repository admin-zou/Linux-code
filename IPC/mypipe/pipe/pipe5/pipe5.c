//如果所有指向管道读端的⽂文件描述符都关闭了(管道读端的引⽤用计数等于0),这时有进程向管道的写端write,那么该进程会收到信号SIGPIPE,通常会导致进程异常终止

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
		int _pipe[2]; 
		int ret = pipe(_pipe); 
		if(ret == -1)
		{ 
				printf("create pipe error! errno code is : %d\n",errno); 
				return 1; 
		} 
		pid_t id = fork(); 
		if( id < 0 )
		{
				printf("fork error!"); 
				return 2; 
		}else if( id == 0 )
		{ //child 
				close(_pipe[0]); //chile close read
				int i =0; 
				char *_mesg_c=NULL; 
				while(i<20)
				{ 
					if( i < 10 )
					{ 
						_mesg_c="i am child!"; 
						write(_pipe[1], _mesg_c, strlen(_mesg_c)+1); 
						printf("id: %d \n",i);
					} 
					sleep(1); 
					i++; 
				}	   
		}
		else
		{ //father 
			close(_pipe[1]); //father close write
			char _mesg[100]; 
			int j = 0; 
			while(j<3)
			{ 
					memset(_mesg, '\0', sizeof(_mesg)); 
					int ret = read(_pipe[0], _mesg, sizeof(_mesg)); 
					printf("%s : code is : %d\n",_mesg, ret); 
					j++; 
			} 
	  		close(_pipe[0]); //关闭了管道（读写都关闭了）导致子进程中断导致子进程中断 
			sleep(5); 
			if ( waitpid(id, NULL, 0)< 0) 
			{ 
				return 3; 
			} 
		} 
	return 0; 
}
