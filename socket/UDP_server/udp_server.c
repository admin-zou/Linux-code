#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

static void Usage(const char* msg)
{
		if(NULL != msg )
		{
			printf("%s [ip] [port] \n");
		}
}

//if success ,return new sock
//else return -1
int start(const char* const ip, short port)  
{
	int sock =socket(AF_INET, SOCK_DGRAM, 0);
	if(sock == -1)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = inet_addr(ip);

	if( bind(sock,(struct sockaddr*)&local,sizeof(local)) == -1) //success ,return 0
	{
		perror("bind");
		return -1;
	}
	
	//udp不许要链接
	
	return sock;
}

int main(int argc ,char* argv[])
{
	if(argc != 3)
	{
		Usage(argv[1]);
		return 1;
	}
	
	const char * ip = argv[1];
	int port = atoi(argv[2]); //string -> short
	
	int sock = start(ip,port); //start udp socket
	
	char buf[1024];

	if( sock > 0)  //文件描述符
	{
		while(1)
		{
			struct sockaddr_in client;
			socklen_t len = 0;
			memset(buf, '\0', sizeof(buf));
			
			recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr*)&client, &len);
			printf("client:%s \n",buf);
			
			sendto(sock, buf, sizeof(buf)-1, 0 ,(struct sockaddr*)&client, len);

		}
	}
	
	return 0;
}
