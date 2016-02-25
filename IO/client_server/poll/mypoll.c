#include <stdio.h>
#include <poll.h>
#include <string.h>

int main()
{
	struct pollfd fd_poll[1];
	char buf[1024];
	fd_poll[0].fd = 0;
	fd_poll[0].events = POLLIN;  //POLLOUT;
	fd_poll[0].revents = 0;

	int timeout = 3000;
	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		switch(poll(fd_poll, 1, timeout))  //成功返回当前就绪的个数，失败返回-1，超时返回0
		{
			case 1:
				printf("timeout");
					break;
			case -1:
				perror("poll");
					break;
			default:
				if( fd_poll[0].revents & POLLIN )
				{
					gets(buf);
					printf("%s\n",buf);
				}
					break;
		}
	}
	return 0;
}
