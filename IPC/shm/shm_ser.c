#include "comm.h"

int main()
{
 	int shm_id = shm_get();
	printf("%d\n",shm_id);
 	char* addr=shm_attach(shm_id);
	printf("%d  %p\n",sizeof(addr),addr);
	int i = 0;
	char msg ='A';
	
	for(;i < 26; i++)
	{
		addr[i] = msg++;
		addr[i+1] = '\0';
		sleep(1);
    }
 	
	shm_detach(addr);
 
	return 0;
}
