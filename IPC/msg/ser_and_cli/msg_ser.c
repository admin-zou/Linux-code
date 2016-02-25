#include "comm.h"

int main()
{
	int msg_id = msg_create(); //ser
	if(msg_id < 0)
	{
		return 1;
	}

	char buf[G_SIZE];
	while(1)
	{
		buf[G_SIZE - 1] = '\0';
		int ret = msg_recv(msg_id, buf, sizeof(buf)-1, DATA_TYPE_CLI);
		if(strncasecmp("quite", buf, 4) == 0)
		{ break;}

		printf("cli:> %s\n", buf);

		printf("plase Enter:");

		fflush(stdout);
		memset(buf, '\0', sizeof(buf));
		fgets(buf, sizeof(buf)-1, stdin);
		ret = msg_send(msg_id, buf, DATA_TYPE_SER);
	}
	 int ret = msg_destroy(msg_id);
	 return 0;
}
