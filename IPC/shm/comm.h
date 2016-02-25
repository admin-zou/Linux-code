#ifndef _COMM_SHM_
#define _COMM_SHM_

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>

#define _PATH_ "."
#define _PROJ_ID_ 0x6666
#define _SIZE_ 4096  //共享内存的大小

int shm_create();  //创建
int shm_get();  //取得该内存编号
void* shm_attach(int shm_id);  //连结到共享内存上
int shm_detach(const void* shmaddr); //与共享内存断开连结
int shm_destroy(int shmid);  //销毁共享内存

#endif
