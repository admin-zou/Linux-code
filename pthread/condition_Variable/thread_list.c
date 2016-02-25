#include "thread_list.h"


static node_ptr _buynode(elem_type data)
{
	node_ptr s=(node_ptr)malloc(sizeof(node_t)*1);
	assert(NULL != s);
	s->_data = data;
	s->_next = NULL;
	return s;
}

void init_list(node_pptr head)
{
	*head = _buynode(0);
}

int push_front(node_ptr head,elem_type data)
{
	if(NULL != head)
	{
		node_ptr cur = _buynode(data);
		cur->_next = head->_next;
		head->_next = cur;
		return True;
	}
	return False;
}
int push_back(node_ptr head,elem_type data)
{
	if(NULL != head)
	{
		node_ptr tail = _buynode(data);
		node_ptr cur = head->_next;
		while(NULL != cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = tail;
		return True;
	}
	return False;
}

int pop_front(node_ptr head, elem_type* data)
{
	if(NULL == head || NULL == head->_next)
		return False;
	node_ptr tmp = head->_next;
	head->_next = tmp->_next;
	*data = tmp->_data;
	tmp->_next = NULL;
	free(tmp);
	return *data;
}
int pop_back(node_ptr head, elem_type* data)
{
	if(NULL == head || NULL == head->_next)
		return False;
	node_ptr prev = head;
	node_ptr cur = head->_next;

	while(NULL != cur->_next)
	{
		prev = cur;
		cur = cur->_next;
	}
	*data = cur->_data;
	prev->_next = NULL;
	free(cur);
	return True;
}

void show_list(node_ptr head)
{
	if(NULL == head || NULL==head->_next)
		return ;
	node_ptr cur = head->_next;
	while(NULL != cur)
	{
		printf("%d ",cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


int is_empty(node_ptr head)
{
	if(head && head->_next == NULL)
		return True;
	return False;
}

