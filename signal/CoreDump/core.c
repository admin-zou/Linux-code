#include <stdio.h>

//可以通过ulimit -a 查看，ulimit -c 更改大小
int main()
{
	int a=2;
	int b=0;
	printf("pid is:%d\n",getpid());
	int *p=0x12345;
	*p=1;

	return 0;
}
