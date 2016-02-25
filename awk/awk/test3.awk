#!/bin/awk -f

BEGIN{
		count=0;
}


/^-/{
	count+=$5;
}

END{
	printf("total:%d",count);		
}

BEGIN{
		count=0;
}


/^-/{
	count+=$5;
}

END{
	printf("total:%d",count);		
}
