#include <stdio.h> //文件描述符fd 是以文件指针数组的形式实现
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

//#define _DEBUG_
const char *msg = "change world\n";

int main()
{
   int i = 100;
   char buf[2048];
   memset(buf,'\0',sizeof(buf));   
   int fd = open("./log", O_RDWR|O_CREAT, 0755);
   if(fd < 0)
   {//falied
       perror("open");
       exit(1);
   }
#ifdef _DEBUG_
   printf("fd:%d\n",fd);
#endif
  while(i--)
  {
  	//write(fd,msg,strlen(msg)+1);//后面会加上^@
  	write(fd,msg,strlen(msg));
  }
   
 //  ssize_t ret;
 //  do
 //  {
 //   ret = read(fd,buf,sizeof(buf)-1);
 //   buf[ret] = '\0';
 //   printf("%s",buf);
 //  }while(ret>0);
 //  fflush(stdout);
 //  close(fd);
   return 0;
}
