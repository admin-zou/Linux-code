#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
	int sock =socket(AF_INET, SOCK_DGRAM, 0);	
	if(sock == -1)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in remote;
	remote.sin_family = AF_INET;
	remote.sin_port = htons(8080);
	remote.sin_addr.s_addr = inet_addr("192.168.0.189");

	char buf[1024];

	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		printf("please enter:>");
		fflush(stdout);
		gets(buf);
		socklen_t len = sizeof(remote);

		sendto(sock, buf, sizeof(buf)-1, 0,(struct sockaddr*)&remote, sizeof(remote));

		recvfrom(sock , buf, sizeof(buf)-1, 0, (struct sockaddr*)&remote, &len);
		
		printf("echo %s",buf);
	}

	return 0;
}
