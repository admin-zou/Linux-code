//客户端B
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <errno.h>

#define N 64
#define TYPEA 100
#define TYPEB 200

typedef struct
{
    long mtype;   //消息类型
    char mtext[N];  //正文段
}MSG;

int main()
{
	key_t key;

	pid_t pid;

	int msgid;

	MSG buf;

	memset(buf.mtext, 0, N); //先将正文段初始化
   
	if ((key = ftok("/", 1)) == -1) 
    {
		  perror("get key"); 
		  return -1;
    }

	if((msgid = msgget(key, 0666 | IPC_CREAT)) == -1) 
    {
		  perror("msgget"); 
		  return -1;
    }

	if ((pid = fork()) == -1) 
    {
		  perror("fork"); 
		  return -1;
    }

	if(pid == 0) /*child process receive message TYPEA*/
    {
		 while (1)
	     {
		    if(-1 == msgrcv(msgid, &buf, N, TYPEB, 0))							
			{
				perror("msgrcv");
				exit(-1);																			
			}
		   
			printf("rcv----%s", buf.mtext);

			if (strncmp(buf.mtext, "quit", 4) == 0)			
			{
				kill(getppid(), SIGKILL);
				if (-1 == msgctl(msgid, IPC_RMID, NULL))
				{
					 perror("msg rm");
					 exit(-1);
				}			
				exit(0);
			}
		 }
	 }
	 else  /*parent process send message TYPEA*/
	 {
	      buf.mtype = TYPEA;   
		  while (1)
		  {
		       fgets(buf.mtext, N, stdin);
		       if (-1 ==msgsnd(msgid, &buf, strlen(buf.mtext)+1, 0)) 
	           {
			        perror("msgsnd");
					return -1;
	           }		
			   if (strncmp(buf.mtext, "quit", 4) == 0)
			   {				
					kill(pid, SIGKILL);
				    exit(0);
			   }
	      }
     }
  
	 return 0;
}
