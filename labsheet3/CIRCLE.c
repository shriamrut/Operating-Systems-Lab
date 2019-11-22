#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argv,char *argc[])
{
	int a=atoi(argc[1]);
	int pid=atoi(argc[2]);
	if(getppid()!=pid)
		{
		printf("I'm an orphan process,as wait is not called, init is the parent : %d \n",getppid());
		}
	else
		{
		printf("I'm not an orphan process\n");
		}
	printf("from Circle,My id is %d \n",getpid());
	printf("from Circle,My parent id is %d\n",getppid());
	printf("Area: %f\n",3.14*a*a);
	printf("Perimeter: %f\n",2*3.14*a);
	return 0;
}

