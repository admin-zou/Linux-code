#include <stdio.h>
#include <string.h>

const char* msg = "hehe,ni shi hao ren\n";

int main()
{
	 write(1,msg,strlen(msg));
	 
	 printf("hehe\n");
	 
	 printf("\n");

	 return 0;
}
