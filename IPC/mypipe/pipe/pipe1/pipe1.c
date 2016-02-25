//1. 如果所有指向管道写端的⽂文件描述符都关闭了(管道写端的引⽤用计数等于0),⽽而仍然有进程 从管道的读端读数据,那么管道中剩余的数据都被读取后,再次read会返回0,就像读到⽂文件末尾一样。


#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
		int _pipe[2]; 
		int ret = pipe(_pipe); 
		if(ret == -1){ 
				printf("create pipe error! errno code is : %d\n",errno); 
				return 1;
		} 
		pid_t id = fork(); 
		if( id < 0 ){ 
				printf("fork error!"); 
				return 2; 
		}
		else if( id == 0 )
		{ //child 
				close(_pipe[0]); //close read
				int i =0; 
				char *_mesg_c=NULL; 
				while(i<10)
				{ 
					_mesg_c="i am child!"; 
					write(_pipe[1], _mesg_c, strlen(_mesg_c)+1); 
					sleep(1); 
					i++; 
				} 
				close(_pipe[1]); //close write 
		}
		else
		{ //father 
				close(_pipe[1]); //close write 
				char _mesg[100]; 
				int j = 0;
			    sleep(3);	
				while(j<100)
				{ 
						memset(_mesg, '\0', sizeof(_mesg)); 
						int ret = read(_pipe[0], _mesg, 10); 
						printf("%s : code is : %d\n",_mesg, ret); 
						j++; 
				} 
				if (waitpid(id, NULL, 0)< 0) 
				{ 
						return 3; 
				} 
			} 
		return 0; 
}





/*
//////////////////////////////////////////////////////////////////////////////////////////
// chhild write,father read 子进程写完后为什么计入死循环，父进程无法调度？
//////////////////////////////////////////////////////////////////////////////////////////
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
			exit(1);
		} 
		pid_t id = fork();
		if( id < 0 )//falied
		{ 
				printf("fork error!"); 
				exit(2);
		}
		else if( id == 0 )
		{ //child write 
				close(_pipe[0]);  //close read 
				int i =0; 
				char *_mesg_c = "i am child!"; 
				printf("child begn\n");
				while(i < 15)
				{ 
					if( i < 10 )
					{ 
							write(_pipe[1], _mesg_c, strlen(_mesg_c)); 
							printf("child is write:%d \n",i);
					} 
					sleep(1); 
					i++; 
				} 
				printf("child end\n");
				//sleep(1);
				close(_pipe[1]); //close write 
				exit(0);
		}
		else
		{ //father read 
				close(_pipe[1]); //close write
				char _mesg[100]; 
				int j = 0;
				printf("father begin read \n");
				sleep(1);
				while(j<20)
				{ 
				   memset(_mesg, '\0', sizeof(_mesg) + 1);
				   	   
				   int ret = read(_pipe[0], _mesg, sizeof(_mesg));
				   if(ret < 0)
				   {
					 	perror("read");
						exit(-1);
				   } 
				   printf("no:%d msg:%s : code is : %d\n",j, _mesg, ret); 
				   sleep(1);	
				   j++; 
				} 
				if ( waitpid(id, NULL, 0) < 0) 
				{ 
						perror("wait");
					   exit(3);	
				}
			   exit(0);	
		} 
		return 0; 
}

*/
