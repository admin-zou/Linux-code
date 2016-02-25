#include <stdio.h>

int main()
{
  int i=0;
  int j=0;
  for(i=0; i< 3; i++)
  {
      int id = fork();
      if(id == 0)
      {
	     printf("i am child:%d\n",j);
      }
      else
      {
	      j++;
	      printf("i am father:%d\n",j);
      }
  }
  sleep(2);
  return 0;
}
