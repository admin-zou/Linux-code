#include <stdio.h>
int count = 0;
int fun()
{
	return count++;
}

int fun1()
{
	return fun()+fun()+fun()+fun();
}
int fun2()
{
	return 4*fun();
}
int main()
{
	printf("%d\n",fun2());
	printf("%d\n",fun1());
	return 0;
}
