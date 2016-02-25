#include<stdio.h>

int main()
{
 extern char** environ;
 int i=0;
for(;environ[i] != NULL;i++)
{
 printf("%S\n",environ[i]);
}
return 0;
}

/*
int main(int argc,char* argv[],char* env[])
{
  printf("argc : %d\n",argc);
  int i=0;
  for(;i<argc;i++)
  {
   printf("%s\n",argv[i]);
} 
 for(i=0;env[i]!=NULL;i++)
{
 printf("%s\n",env[i]);
}
 return 0;
}
*/
