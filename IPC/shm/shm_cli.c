#include "comm.h"

int main()
{
	 int shm_id = shm_create();
	 
	 char* addr=shm_attach(shm_id);
	 
	 while(1)
	 {
	 	printf("%s\n",addr);
	 	sleep(1);
	 } 
	 
	 shm_detach(addr);
	 
	 shm_destroy(shm_id);
	 
	 return 0;
}
