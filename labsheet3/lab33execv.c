#include  <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>   
#include <sys/wait.h>     
int  main()
{
	int a;
    printf("Enter a value : ");
    scanf("%d",&a);
    char arg[50];
    char arg2[50];
    pid_t  pid,root;
    root=getpid();
    sprintf(arg, "%d", a);
	sprintf(arg2, "%d", root);
	printf("Parent id: %d\n",root);
    pid = fork();
	if(pid==0)
	 {
		 char *args[]={"./SQUARE",arg,arg2,NULL}; 
         execv(args[0],args); 
	 }
	 else
	 {
		 wait(NULL);
		 pid_t pid2=fork();
		 if(pid2==0)
			{
				//printf("C");
				char *args[]={"./CIRCLE",arg,arg2,NULL}; 
				execv(args[0],args); 
			}
		wait(NULL);
	 }
    exit(0);
}


