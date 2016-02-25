#include<stdio.h>
#include<stdlib.h>
int a;
int b=0;
void fun()
{
 printf("this is a test\n");
}
int main()
{
 int *p=(int *)malloc(sizeof(int));
 printf("ox%x\n",fun);
 printf("ox%x\n",&a);
 printf("ox%x\n",&b);
 printf("ox%X\n",p);
 printf("ox%x\n",&p);

 return 0;
}

