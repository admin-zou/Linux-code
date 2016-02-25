#ifndef _SEM_LOCK_
#define _SEM_LOCK_

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define _PATH_ "."
#define _PROJ_ID_ 0x6666

typedef union _semnu
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
}semun_t;

int sem_create(int nsems);
int sem_init(int sem_id, int sem, int val);
int sem_get(int nsems);
int sem_p(int sem_id, int sem);
int sem_v(int sem_id, int sem);
int sem_destroy(int sem_id);

#endif
