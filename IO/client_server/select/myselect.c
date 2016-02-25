#include <stdio.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int max_fd = 0;
	fd_set r_set;
	fd_set w_set;
	
	while(1)
	{
		FD_ZERO(&r_set);
		FD_ZERO(&w_set);
		
		FD_SET(0, &r_set);
	//	FD_SET(1, &w_set);
		
	//	max_fd = 1;	
		max_fd = 0;	
		
		struct timeval timeout={5,0};     //1.按时等待
		//struct timeval timeout={0,0};   //2.非阻塞式等待
								    	  //3.当timeout选项为NULL时为阻塞式等待
		switch(select(max_fd+1, &r_set, &w_set, NULL, &timeout))
		{
			case 0:	//timeout
			 	printf("time is out!\n");
					break;

			case -1: //error
				perror("select");
				exit(1);
					break;

			default: //success
				{//
					char buf[1024];
					memset(buf, '\0', sizeof(buf));
					
					if(FD_ISSET(0, &r_set))	
					{//read cond ready
					
						ssize_t sz = read(0, buf, sizeof(buf)-1);
					
						if(sz > 0)
						{//read success 
					
								buf[sz]='\0';
								printf("read event ready:%s\n",buf);
						
						}

					}
					else if(FD_ISSET(1, &w_set))
					{//write is ready
					
						char *msg = "this is a select test\n";
						write(1, msg, strlen(msg));
					
					}
					else
					{}
				}			
					
				break;
		}
	}

	return 0;
}
