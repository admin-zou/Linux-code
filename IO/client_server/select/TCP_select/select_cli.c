#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

static void Usage(const char *proc)
{
	printf("%s [ip] [port]\n");
}	

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		Usage(argv[0]);
		return 1;
	}

	int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
	{
   		perror("socket");
		return 1;
    }	   
		
	int port = atoi(argv[2]);
	const char *ip = argv[1];
	
	struct sockaddr_in remote;
	remote.sin_family = AF_INET;
	remote.sin_port = htons(port);
	remote.sin_addr.s_addr = inet_addr(ip);
	
		if( connect(sock, (struct sockaddr*)&remote, sizeof(remote)) < 0)
		{
			perror("connect");
			exit(1);
		}
	
	while(1)
	{
		char buf[1024];
		memset(buf, '\0', sizeof(buf));	
		printf("please enter :");
		fflush(stdout);
		gets(buf);

		write(sock, buf, strlen(buf));
		close(sock);
	}

	return 0;
}
