#include <stdio.h>

void twiddle1(int *xp, int* yp)
{
	*xp += *yp;
	*xp += *yp;
}
void twiddle2(int* xp, int* yp)
{
	*xp += 2* *yp;
}

int main()
{
	int a1 = 2,b1 = 2;
	int a2 = 2,b2 = 2;
	int a3 = 2,b3 = 2;
	twiddle1(&a1,&b1);
	twiddle2(&a2,&b2);
	twiddle1(&a3,&a3);
	twiddle2(&b3,&b3);
	printf("%d %d\n%d %d\n",a1,a2,a3,b3);
	return 0;
}
