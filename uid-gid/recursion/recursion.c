#include <stdio.h>

int rfact(int n)
{
  int result;
 // printf("pid:%d  ppid:%d\n",getpid(),getppid());
  if(n <= 1)
  { result = 1;}
  else
  { result = n * rfact(n-1); }
  return result;
}

int main()
{
  int n;
  scanf("%d",&n);
 printf("sum:%d\n" rfact(n));
  printf("\n");
}
