#include  <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>   
#include <sys/wait.h>     
int main(int argc,char *argv[])
{
	/*level 1-1
	 *level 2-2,3,4
	 *level 3-5,6,7
	 *level 4-8,9
	 * */
	printf("No: P Own\n");
	printf("1 %d %d\n",getppid(),getpid());//1p
	pid_t p2=vfork();
	if(p2!=0)
		{
			pid_t p3=vfork();
			if(p3!=0)
			{
				pid_t p4=vfork();
				if(p4==0)
				{
					printf("4 %d %d\n",getppid(),getpid());//4p
					pid_t p7=vfork();
					if(p7==0)
					{
						printf("7 %d %d\n",getppid(),getpid());//7p
						pid_t p8=vfork();
						if(p8!=0)
						{
							pid_t p9=vfork();
							if(p9==0)
								printf("9 %d %d\n",getppid(),getpid());//9p
						}
						else
						{
							printf("8 %d %d\n",getppid(),getpid());//8p
						}
					}
				}
			}
			else
			{
				printf("3 %d %d\n",getppid(),getpid());//3p
				pid_t p5=vfork();//5
				if(p5!=0)
					{
						pid_t p6=vfork();
						if(p6==0)
						{
							printf("6 %d %d\n",getppid(),getpid());//6p
						}
					}
				else
					{
						printf("5 %d %d\n",getppid(),getpid());//5p
					}
			}
			
		}
	else
	{
		printf("2 %d %d\n",getppid(),getpid());//2p
	}
	exit(0);
	return 0;
}
