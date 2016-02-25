#include<stdio.h>

int main(int argc,char* argv[],char*env[])
{
  int i=0;
 
  while(argv[i] != NULL)
  {
  	 printf("%s \n",argv[i]);
     i++;
  }

  return 0;
}

//int main()
//{	
  //int i=0;
  //while(env[i] != NULL)
  //{
  // printf("%s\n",env[i]);
  //i++;
  //}
  //return 0;
//}

//int main()
//{
//	extern char ** environ;
//	int i=0;
//	while(environ[i]!=NULL)
//	{
//	 printf("%s \n",environ[i]);
//	 i++;
//	}
//	return 0;
//}
