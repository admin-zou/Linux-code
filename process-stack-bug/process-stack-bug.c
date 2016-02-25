#include <stdio.h>
#include <stdlib.h>

void bug()
{
  printf("say by by\n");
  sleep(10);
  exit(0);
}

int stack_test(int x,int y)
{
   int *p =&x;
   *(--p) = (int )bug;

  // printf("before :%x\n",y);
  // int *p =&x;
  // *(++p) = 0x5555;
  // printf("after:%x\n",y);
   
   int z = 0x3333;
   return z;
}

int main()
{
	int a = 0x1111;
 	int b = 0x2222;
 	
	int ret = stack_test(a,b);
 	
	printf("you should run here! ret:%x \n",ret);
  
	return 0;
}
