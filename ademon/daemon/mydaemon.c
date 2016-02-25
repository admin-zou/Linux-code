//#include <stdio.h>
//#include <stdlib.h>
//#include <signal.h>
//#include <unistd.h>
//
//int mydaemon()
//{
//	umask(0);
//	pid_t id = fork();
//	if(id > 0)
//	{//father
//		exit(0);
//	}
//	
//	signal(SIGCHLD,SIG_IGN);
//
//	setsid();
//	
//	if(fork()>0)
//	{
//		exit(0);
//	}
//
//	close(0); 
//	close(1);
//	close(2);
//
//	chdir("/");
//	return 0;
//}
//
//int main()
//{
//	mydaemon();
//	while(1)
//	{
//		sleep(1);
//	}
//return 0;
//}


//调用接口函数来创建 daemon 进程
#include <stdio.h>
#include <unistd.h>

int main()
{
	daemon(0,0);
	while(1)
	{
		sleep(1);
	}
	return 0;
}
