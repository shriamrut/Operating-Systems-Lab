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
	pid_t p2=fork();
	if(p2!=0)
		{
			wait(NULL);
			pid_t p3=fork();
			if(p3!=0)
			{
				wait(NULL);
				pid_t p4=fork();
				if(p4==0)
				{
					printf("4 %d %d\n",getppid(),getpid());//4p
					pid_t p7=fork();
					if(p7==0)
					{
						printf("7 %d %d\n",getppid(),getpid());//7p
						pid_t p8=fork();
						if(p8!=0)
						{
							wait(NULL);
							pid_t p9=fork();
							if(p9==0)
								printf("9 %d %d\n",getppid(),getpid());//9p
							else
							{
								wait(NULL);
							}
						}
						else
						{
							printf("8 %d %d\n",getppid(),getpid());//8p
						}
					}
					else
					{
						wait(NULL);
					}
				}
				else
				{
					wait(NULL);
				}
			}
			else
			{
				printf("3 %d %d\n",getppid(),getpid());//3p
				pid_t p5=fork();//5
				if(p5!=0)
					{
						wait(NULL);
						pid_t p6=fork();
						if(p6==0)
						{
							printf("6 %d %d\n",getppid(),getpid());//6p
						}
						else
						{
							wait(NULL);
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

