//客户端A
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <error.h>

#define N 64
#define TYPEA 100
#define TYPEB 200

typedef struct
{
	long mtype;
	char mtext[N];
}MSG;

int main()
{
	key_t key;

	pid_t pid;

	int msgid;

	MSG buf;

	memset(buf.mtext, 0, N);

	if((key = ftok("/",1) == -1))
	{
		perror("get key");
		return -1;
	}

	if((msgid = msgget(key, 0666|IPC_CREAT))==-1)
	{
		perror("megget");
		return -1;
	}

	if((pid = fork()) == -1)
	{
		perror("fork");
		return -1;
	}

	if(pid == 0)
	{
		while(1)
		{
			if(-1 == msgrcv(msgid,&buf,N,TYPEA,0))
			{
				perror("msgrcv");
				return -1;
			}
			printf("rcv---%s",buf.mtext);

			if(strncmp(buf.mtext,"quit",4)==0)
			{
				kill(getpid(),SIGKILL);

				if(-1 == msgctl(msgid, IPC_RMID, NULL)) //删除消息队列
				 {
					perror("msg rm");
					exit(0);
				 }
			}
		}
	}
	else /*父进程向消息队列发送TYPEB类型的消息*/
	{
		buf.mtype = TYPEB;  
	    while (1)	
		{
	    	fgets(buf.mtext, N, stdin);
			
			if(-1 == msgsnd(msgid, &buf, strlen(buf.mtext)+1, 0))
			 {//发送的是正文段的大小，而不是结构体的大小
		        perror("msgsnd");
				return -1;
	         }
			if (strncmp(buf.mtext, "quit", 4) == 0)
	         {
	            kill(pid, SIGKILL); //杀死子进程
		        exit(0);
			 }
        }
    }

  return 0;
}
