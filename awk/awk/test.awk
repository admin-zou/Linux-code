#!/bin/awk -f

BEGIN{
	count1=0;
	count2=0;
	printf("i am coming!\n");
}


END{
		printf("count1:%d,count2:%d\n",count1,count2);
}




#BEGIN{printf("bad boy\n");}
#END{printf("but, I like him!\n");}
