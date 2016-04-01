#include <stdio.h>
#include <stdlib.h>

int g_val=0;

int main()
{
	 int val = 0;
	//  pid_t id = fork();
	 pid_t id = vfork();
	 //vfork创建的子进程是在父进程的空间上进行操作，如果不exit则会破坏父进程的
	 //栈空间，出现段错误或者死循环
	 if(id < 0)
	 { 
	   printf("error\n");
	   exit(0);
	 }
	 else if(id ==0)
	 {
	 	printf("child val:%d g_val:%d\n",val,g_val);
	 	sleep(1);
		++val;
		++g_val;

//我的机器上如果调用return 0，则会无限循环，而有的机器上会直接挂掉，遇到这两种情况不要迟疑，因为main函数的栈被破坏了，所以程序可能挂了，也可能无限循环。---》原因是return会释放栈，清理资源（想想C++中调用return后会调用析构函数），而exit不会（他不是系统调用）

	  //exit(0); //子进程必须调用exec或exit后父进程才可能被调度
	  //return 0;  
	 }
	 else
	 {
		g_val++;
	 	printf("father val:%d g_val:%d\n",val,g_val);
		sleep(1);
	 } 
	 return 0;
}


//#include <stdio.h>
//#include <unistd.h>
//int main()
//{
// while(1)
// {
//  printf("hehe\n");
//  fork();
//  sleep(1);
//  } 
// return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//char * msg = "hello\n";
//int main()
//{
// // printf("world \n");
// // write(1,msg,strlen(msg));
// // fwrite(msg,1,strlen(msg),stdout);
//  sleep(3);
//}
