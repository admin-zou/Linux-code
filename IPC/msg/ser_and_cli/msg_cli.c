//cli
#include "comm.h"

int main()
{
	int msg_id = msg_get(); //cli
	if(msg_id < 0)
	{return 1;}

	char buf[G_SIZE];
	int ret = 0;
	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		printf("please Enter:");
		fflush(stdout);
		fgets(buf, sizeof(buf)-1, stdin);

#ifdef _DEBUG_
	printf("%s\n",buf);
#endif
	  
   		ret = msg_send(msg_id, buf, DATA_TYPE_CLI);
	    if( strncasecmp("quit", buf, 4) == 0)
	    { break;}
	
#ifdef _DEBUG_
	printf("ret code is: %d, %s\n",ret, buf);
#endif
	
		ret = msg_recv(msg_id, buf, sizeof(buf)-1, DATA_TYPE_SER);
		printf("ser:> %s\n",buf);
	}
  return 0;
}
