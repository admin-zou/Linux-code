#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define _CMD_ "ls -l"

int main()
{
	FILE* f_p = popen(_CMD_,"r");
	//该函数用启动管道的方式启动一个进程，并调用shell
	
	if(NULL == f_p)
	{
		perror("popen");
		exit(1);
	}
	char buf[1024];
	memset(buf, '\0', sizeof(buf));
	size_t s = fread(buf, 1, sizeof(buf)-1, f_p);
    buf[s] = '\0';
	printf("%s",buf);
	
	pclose(f_p); //用来关闭popen创建的管道
	return 0;
}
