#ifndef _COMM_
#define _COMM_

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <string.h>

#define  G_SIZE 128
#define DATA_TYPE_SER 1
#define DATA_TYPE_CLI 2
//便于该路径下的文件查找该消息队列
#define _PATH_ "/home/admin/mychengxu/2015_11/test11_15mesg/ser_and_cli"
#define _PROJ_ID_ 0x7777 //该编号和其他ipc函数尽量不一样
//centos 下面需要自己定义该结构体，用于消息队列
typedef struct
{
	long mtype;
	char mtext[G_SIZE];
}msgbuf_t;

int msg_create(); //ser
int msg_get();   //cli
int msg_send(int msg_id, char* msg, long mytype);
int msg_recv(int msg_id, char* out_msg, int out_len, long mytype);
int msg_destroy(int msg_id);

#endif
