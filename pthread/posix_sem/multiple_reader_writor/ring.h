#ifndef _RING_
#define _RING_

#include <stdio.h>

#define _SIZE_ 1024

typedef enum {False,True}Bool;

typedef int elem_type;

typedef struct _ring
{
	elem_type ring_buf[_SIZE_];
	int prev;
	int curr;
	int count;
}ring_t,*ring_ptr;

void init_ring(ring_ptr _r);
Bool put_data(ring_ptr _r,elem_type data);
Bool get_data(ring_ptr _r,elem_type *data_p);

#endif
