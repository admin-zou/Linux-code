#include<stdio.h>
int main()
{
	int common =123;

	int pid = fork();
	if(pid == 0)
	{
		  printf("this is child,pid=%d  ppid=%d\n",getpid(),getppid());
		  printf("add:%p val:%d\n",&common,common);
	}
	else if(pid >0)
	{
		 printf("this is father,pid=%d  ppid=%d\n",getpid(),getppid());
		 common = 321; 
		 printf("add:%p val:%d\n",&common,common);
    	      sleep(1);
	}
	else
	{}

   	return 0;
}
