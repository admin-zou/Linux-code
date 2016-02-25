#ifndef _SEM_LOCK_
#define _SEM_LOCK_

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


#define _PATH_ "."
#define _PROJ_ID_ 0x520 //每次写函数时工程号换一下

typedef union _semnu //在centos中需要手动定义该结构
{
	int				 val;
	struct semid_ds *buf;
	unsigned short  *array;
	struct seminfo  *_buf;
}semun_t;

int sem_create(int nsems); //创建
int sem_init(int sem_id, int sem, int val); //初始化
int sem_get(int nsems); //获取信号量
int sem_p(int sem_id, int sem); //p操作
int sem_v(int sem_id, int sem); //v操作
int sem_destroy(int sem_id); //销毁

#endif
