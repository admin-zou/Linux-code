#include<stdio.h>
int main(int argc,char *argv[])
{
   int i=0;

   printf("the number of argc is %d\n:",argc);

   for(;i < argc; i++)
   {
	     printf("%s\n",argv[i]);
   }

 return 0;
}
