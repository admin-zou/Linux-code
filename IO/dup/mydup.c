#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define OPEN_FILE "./log"

int main()
{

//	close(1);

//	int fd = open(OPEN_FILE, O_RDWR | O_CREAT, 0666 );
//	if(fd < 0)
//	{
//		perror("open");
//		return 1;
//	}
//	printf("fd: %d\n",fd);	

//	int count = 10;
//	while(count)
//	{
//		printf("hello world:%d\n",count);

//		count--;
//	}
//	fflush(stdout);
//	close(fd);

//	close(1);
//	FILE* f_p = fopen(OPEN_FILE,"w+");
//	if( f_p < 0 )
//	{
//		perror("fopen");
//		return 1;
//	}
//	
//	printf("f_p: %d\n",f_p);	
//
//	int count = 10;
//	while(count)
//	{
//		printf("hello world,%d\n",count);
//		count--;
//	}
//	fflush(stdout);
//	fclose(f_p);
 
//	int fd = open(OPEN_FILE, O_RDWR | O_CREAT, 0666 );
//	if(fd < 0)
//	{
//		perror("open");
//		return 1;
//	}
//	//fd = 3 
//	printf("dup begin: %d\n",fd);
//	close(1);
//	int new_fd = dup(fd);
//	printf("dup end: old:%d new:%d\n",fd, new_fd);
//	int count = 10;
//	while(count)
//	{
//		printf("hello world:%d\n",count);
//		count--;
//	}
//	fflush(stdout);
//	return 0;
	

	int fd = open(OPEN_FILE, O_RDWR | O_CREAT, 0666 );
	if(fd < 0)
	{
		perror("open");
		return 1;
	}
	//fd = 3 
	printf("dup2 begin:%d\n",fd);

	int new_fd = dup2(fd,1); //close(1),int new_fd = dup(fd);
	printf("dup end: old:%d,new:%d\n",fd, new_fd);

	int count = 10;
	while(count)
	{
		printf("hello world:%d\n",count);

		count--;
	}
	fflush(stdout);

	return 0;
}
