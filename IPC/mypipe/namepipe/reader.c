#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define _SIZE 256
#define _PATH_ "/home/admin/mychengxu/2015_11/test11_14namepipe/fifo.tmp" 

int main()
{
		int fd = open(_PATH_, O_RDONLY); //以只读方式打开,会阻塞到读为止
		if(fd < 0)
		{
			perror("open");
			exit(1);
		}
		char buf[_SIZE];
		while(1)
		{
			memset(buf, '\0', strlen(buf));
			ssize_t size = read(fd, buf, sizeof(buf)-1);
			if(size == 0)
			{
				printf("reader quit\n");
				break;	
			}
			else if(size > 0)
			{
				buf[size] = '\0';
				printf("%s\n",buf);
			}
			else
			{
				perror("read");
				exit(2);
			}
		}
	    close(fd);
	return 0;
}
