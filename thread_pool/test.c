#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "pthread_pool.h"

void *func(void *arg){
	printf("thread %d\n",(int)arg);
	return NULL;
}

int main(){
	if(tpool_create(5) != 0){
		printf("tpool_create failed\n");
		exit(1);
	}

	int i = 0;
	for(i=0; i< 100; ++i){
		tpool_add_work(func,(void*)i);
		sleep(1);
	}
	sleep(2);
	tpool_destroy();
	return 0;
}
