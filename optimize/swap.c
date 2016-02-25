#include <stdio.h>

void swap(int* xp, int* yp)
{
	*xp = *xp + *yp;
	*yp = *xp - *yp;
	*xp = *xp - *yp;
}
int main()
{
	int a = 2;
	int b = 2;
	int c = 2;
	swap(&a,&b);
	swap(&c,&c);
	printf("a=%d b=%d c=%d\n",a,b,c);
	return 0;
}
