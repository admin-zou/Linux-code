#include <unistd.h>
#include <stdlib.h>
#include "sem_lock.h"

int main()
{
	int sem_id  = sem_create(1); //需要创建的信号量集的数目
	printf("%d \n",sem_id);
//若sem_id值为-1，信号量创建失败。说明sem_lock.h的project_num需要更换，需要生成新的key值


	sem_init(sem_id, 0, 1); //将0号信号量设置为1

	pid_t id = fork();
	if(id < 0)
	{
		exit(-1);
	}
	else if(id == 0)
	{
		while(1)
		{
			sem_p(sem_id, 0); //对0号信号量进行p操作
			printf("A");
			fflush(stdout);

			sleep(3);
			printf("A");
			fflush(stdout);

			sleep(2);
			sem_v(sem_id, 0);//对0号信号量进行v操作
		}

		exit(1);
	}
	else
	{
		while(1)
		{
			sem_p(sem_id, 0); //对0号信号量进行p操作
			printf("B");
			fflush(stdout);
			sleep(1);

			printf("B");
			fflush(stdout);
			sleep(1);
			
			sem_v(sem_id, 0); //对0号信号量进行v操作
		}	
	}

	return 0;
}
