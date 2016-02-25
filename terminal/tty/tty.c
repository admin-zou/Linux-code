#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("0 -> %s\n",ttyname(0));
	printf("1 -> %s\n",ttyname(1));
	printf("2 -> %s\n",ttyname(2));
	return 0;
}
