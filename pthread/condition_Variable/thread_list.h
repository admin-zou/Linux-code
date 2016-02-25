#ifndef _LIST_
#define _LIST_

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int elem_type;

enum Bool{False,True};

typedef struct _node
{
	elem_type _data;
	struct _node *_next;
}node_t,*node_ptr,**node_pptr;

void init_list(node_pptr head);

int push_front(node_ptr head,elem_type data);
int push_back(node_ptr head,elem_type data);

int pop_front(node_ptr head, elem_type* data);
int pop_back(node_ptr head, elem_type* data);

void show_list(node_ptr head);

int is_empty(node_ptr head);
#endif
