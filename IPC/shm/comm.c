#include"comm.h"

static int shm_create_get(int flag)
{
	 key_t _key = ftok(_PATH_, _PROJ_ID_);
 	 if(_key < 0)
	 {
 		perror("ftok");
		return -1;
 	 }
  return shmget(_key, _SIZE_, flag); //调用系统函数获取共享内存
}

int shm_create()
{//IPC_CREAT    IPC_EXCL    IPC_CREAT | IPC_EXCL | 0666 注意这三者的区别
	return shm_create_get(IPC_CREAT | IPC_EXCL | 0666);//区分flag的值的特点
}

int shm_get()
{
 	return  shm_create_get(IPC_CREAT); //返回内存号
}

void* shm_attach(int shm_id)
{
	return shmat(shm_id, NULL, 0); //连接共享内存
}

int shm_detach(const void* shmaddr)
{
	return shmdt(shmaddr); // 与共享内存断开连结
}

int shm_destroy(int shmid)
{
	return  shmctl(shmid, IPC_RMID, NULL); //删除
}
