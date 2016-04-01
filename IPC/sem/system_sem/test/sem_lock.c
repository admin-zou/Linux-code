#include "sem_lock.h"

int sem_create_get(int nsems, int flags)
{//nsems表示信号量的数目，flags表示打开的权限
	key_t _key = ftok(_PATH_, _PROJ_ID_);//床将key值
	if(_key < 0)
	{
		perror("ftok");
		return -1;
	}
	return semget(_key, nsems, flags);//调用系统semget函数
}

int sem_init(int sem_id, int sem, int val)
{//sem表示信号量的下表，意思是要对哪个信号量操作
	semun_t semval;
	semval.val = val;
	return semctl(sem_id, sem, SETVAL, semval);	//对信号量初始化,一般是三个参数，第四个参数若有一定是semun结构体
}

int sem_create(int nsems)
{
	return sem_create_get(nsems, IPC_CREAT | IPC_EXCL | 0777);
}

int sem_get(int nsems)
{
   return sem_create_get(nsems, IPC_CREAT);
}

static int my_sem_op(int sem_id, int sem, int op)
{//p操作和v操作都是通过这个函数来实现
	struct sembuf _op;
	_op.sem_num = sem;  //信号量的下标
	_op.sem_op = op;  
	_op.sem_flg = 0; //SEM_UNDO
	return semop(sem_id, &_op, 1);
}
int sem_p(int sem_id, int sem)
{
	return my_sem_op(sem_id, sem, -1); //p
}

int sem_v(int sem_id, int sem)
{
	return my_sem_op(sem_id, sem, 1); //v
}

int sem_destroy(int sem_id)
{
	return semctl(sem_id, 0, IPC_RMID);
}

#ifdef _DEBUG_

int main()
{
	int nsems=1;
	int sem_id =sem_create(nsems)
	sleep(20);
	sem_init(sem_id, 0, 1);
	sem_p(sem_id, 0);
	sleep(1);
	sem_v(sem_id, 0);
	sem_detroy(sem_id);
	return 0;
}

#endif

