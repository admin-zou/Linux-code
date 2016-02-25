//消息队列的创建
#include "comm.h"

static int msg_create_and_get(int flag)
{
	key_t _key = ftok(_PATH_, _PROJ_ID_); //key值用来唯一标识消息队列
	if(_key < 0)
	{
		perror("ftok");
		return -1;
	}
	int msg_id = msgget(_key, flag); //创建一个消息队列
	if(msg_id < 0)
	{
		perror("msgget");
		return -2;
	}
	return msg_id;
}

int msg_create()
{
	int flag = IPC_CREAT | IPC_EXCL;
	return msg_create_and_get(flag | 0777);
}

int msg_get() //cli
{
	int flag = IPC_CREAT;
	return msg_create_and_get(flag|0777);
}

int msg_send(int msg_id, char* msg, long mytype)
{
	msgbuf_t _buf;
	_buf.mtype = mytype;
	memset(_buf.mtext, '\0', sizeof(_buf.mtext));
	strncpy(_buf.mtext, msg, strlen(msg)>G_SIZE?G_SIZE-1:strlen(msg));

	return msgsnd(msg_id, &_buf, sizeof(_buf.mtext), 0);
}

int msg_recv(int msg_id, char* out_msg, int out_len, long mytype)
{
	msgbuf_t msg_buf;
	memset(msg_buf.mtext, '\0', sizeof(msg_buf.mtext));
	int ret = msgrcv(msg_id, &msg_buf,sizeof(msg_buf.mtext),mytype, 0);
	if(ret >= 0)
	{//success
		int size = strlen(msg_buf.mtext)>out_len?out_len-1:strlen(msg_buf.mtext);
		strncpy(out_msg, msg_buf.mtext, size);
		out_msg[size] = '\0';
		return 0;
	}
	return 1;
}

int msg_destroy(int msg_id)
{
	int ret = msgctl(msg_id, IPC_RMID, NULL);
	if( ret == -1)
	{
		perror("msgctl");
	}
	return ret;
}
