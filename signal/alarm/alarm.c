#include <stdio.h>
#include <unistd.h>

int main()
{
	//alarm(3);
	//alarm(0);  //取消闹钟
	alarm(5);
	while(1)
	{
		printf("haha,come on,boy!\n");
		sleep(1);
	}
	return 0;
}
