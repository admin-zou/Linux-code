//标准I/O是缓冲的，如果标准输出到终端设备，则它是⾏行缓冲，否则它是全
//缓冲
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
const char * msg ="hehe,ni shi ge hao ren \n";
int g_val = 0;
int main()
{
   int val = 0;     
   printf("before fork:\n");
  //本来是行缓冲，但是重定向的时候变为全缓存，所以当他被重定向到文件中
  //before fork 会被打印两次 
    
   write(1,msg,strlen(msg)); //wu huan chong 
   pid_t id = fork();
   if(id < 0)
   {
       // perror("fork");
       printf("%d   %s \n",errno,strerror(errno));
       exit(1);
   }
   else if(id == 0)
   {//child
       printf("i am child pid:%d ppid:%d\n",getpid(),getppid());
       val ++;
       g_val++;
       printf("chirld:%d %d %p %p \n",val,g_val,&val,&g_val);
   }
   else
   {//father
       printf("i am father pid:%d ppid:%d\n",getpid(),getppid());
       printf("father:%d %d %p %p \n",val,g_val,&val,&g_val);
       sleep(1);
   }
   return 0;
}
