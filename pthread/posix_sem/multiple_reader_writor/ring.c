#include "ring.h"
#include <string.h>

void init_ring(ring_ptr _r)
{
	if(NULL != _r)
	{
		_r->prev=0;
		_r->curr=0;
		_r->count=0;
		memset(_r->ring_buf, 0 , sizeof(_r->ring_buf));
	}
}

static Bool is_empty(ring_ptr _r)
{
	if(_r && _r->count == 0)
	{
		return True;
	}
	return False;
}

static Bool is_full(ring_ptr _r)
{
	if(_r && _r->count == _SIZE_)
			return True;
	return False;
}

Bool put_data(ring_ptr _r,elem_type data)
{
	if(is_full(_r))
		return False;
    _r->ring_buf[_r->curr++]=data;
    _r->count++;
	_r->count%=_SIZE_;
   return True;   
}

Bool get_data(ring_ptr _r,elem_type *data_p)
{
	if(is_empty(_r))
		return False;
	*data_p = _r->ring_buf[_r->prev++];
	_r->count--;
	_r->prev %= _SIZE_;
	return True;
}
