///???????????????
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <errno.h>

const char* msg = "hello world \n";

int main()
{
	 close(1);
	 //close(2);
	 int fd = open("./log",O_CREAT|O_RDWR,0666);
	 
	 //int fd1 = open("./log1",O_CREAT|O_RDWR,0666);
	 //int fd2 = open("./log2",O_CREAT|O_RDWR,0666);
	 //int fd3 = open("./log3",O_CREAT|O_RDWR,0666);
	 if(fd < 0 )
	 {
	    exit(-1);
	 }

	 printf("%d\n",fd);
	 int i = 10;
	 //printf("%d\n",fd1);
	 //printf("%d\n",fd2);
	 //printf("%d\n",fd3);

	 while(i)
	 {
	   i--;
	   write(fd,msg,strlen(msg));
	 }

	 close(fd);
	 //close(fd1);
	 //close(fd2);
	 //close(fd3);

	 return 0;
}
