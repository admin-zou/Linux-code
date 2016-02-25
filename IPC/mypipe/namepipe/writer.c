#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define _PATH_ "/home/admin/mychengxu/2015_11/test11_14namepipe/fifo.tmp" 
int main()
{
	umask(0); //对创建出来的管道的权限有影响
	char * msg = "hello";
	//S_IFIFO|0666 指明创建一个命名管道且存取权限为0666
	if (mkfifo(_PATH_, S_IFIFO | 0666) == 0)
	{//success
			int fd = open(_PATH_, O_WRONLY);//写方式打开,会阻塞到写为止
			if(fd < 0)
			{
				perror("open");
				exit(2);
			}
			int count = 10;
			while(count)
			{
				write(fd, msg, strlen(msg));
				sleep(1);
				count--;
			}
			close(fd);
		printf("success\n");
	}
	else
	{//falied
		perror("mkfifo");
		exit(1);
	}
	return 0;
}
