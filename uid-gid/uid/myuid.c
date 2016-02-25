#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
	  if(argc != 2)
	  {
	     printf("usage: ./cmd file\n");
	     exit(1);
	  }
	
	  printf("pid=%d ppid=%d uid=%d gid=%d euid=%d egid=%d\n",getpid(),
	   		getppid(),getuid(),getgid(),getegid());
	
	  char * msg="ni shi hao ren !";
	  char * _path = argv[1];
	
	  FILE* fp = fopen(_path,"a+");
	  if(NULL == fp)
	  {
	    perror("open fialuer");
	    exit(2);
	  }
	
	  fwrite(msg,1,strlen(msg),fp); 
	
	  perror("fwrite");
	
	  fclose(fp);

	  return 0;
}


//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//
//int main()
//{
//   pid_t id = fork();
//   if(id < 0)
//   {
//   	printf("fork error\n");
//   	exit(0);
//   }
//   else if(id ==0)
//   {//chirld
//   printf("pid=%d ppid=%d uid=%d gid=%d euid=%d egid=%d\n",getpid(),
//   		getppid(),getuid(),getgid(),getegid());
//   }
//   else
//   {//father
//   printf("pid=%d ppid=%d uid=%d gid=%d euid=%d egid=%d\n",getpid(),
//   		getppid(),getuid(),getgid(),getegid());
//   } 
//   return 0;
//}
