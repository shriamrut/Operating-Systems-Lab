#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	int shmid=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666);
	pid_t pid=fork();
	int *x=(int*)shmat(shmid,0,0);
	*x=0;
	if(pid==0)
	{
		int *x=shmat(shmid,0,0);
		for(int i=0;i<10000;i++)
			{
				*x=*x+1;
				printf("X in A: %d\n",*x);
				//sleep(5);
			}
		shmdt(x);
	}
	else
	{
		pid_t pid2=fork();
		if(pid2==0)
		{
			int *x=shmat(shmid,0,0);
			for(int i=0;i<10000;i++)
			{
				//sleep(1);
				*x=*x-1;
				printf("X in B  %d\n",*x);
			}
		}
		else
		{
		wait(NULL);
		wait(NULL);
		printf("Final value of X: %d\n",*x);
		}
	}
	exit(0);
	return 0;
}
