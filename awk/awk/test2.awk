#!/bin/awk -f

BEGIN{
	a_n=0;
	b_n=0;
	c_n=0;
}


/^a.*n$/{a_n++;}
/^b.*n$/{b_n++;}
/^c.*n$/{c_n++;}


END{
	printf("/^a.*n$/:%d\n",a_n);		
	printf("/^b.*n$/:%d\n",b_n);		
	printf("/^c.*n$/:%d\n",c_n);		
}
