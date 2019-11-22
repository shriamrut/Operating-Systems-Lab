#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>   

void  ChildProcess(void)
{
		float area,perimeter,r,pi=3.14;
    	 printf("Enter radius: ");
		 scanf("%f",&r);
		 area=pi*r*r;
		 perimeter=2*pi*r;
		 printf("Area of Circle : %f\n",area); 
		 printf("Perimeter: %f\n",perimeter);
}

void  ParentProcess(void)
{
		 float a,area,perimeter;
		 printf("Enter side: ");
		 scanf("%f",&a);
		 area=a*a;
		 perimeter=4*a;
		 printf("Area of square: %f\n",area);
		 printf("Perimeter of square: %f\n",perimeter);
}           
int  main()
{
     pid_t  pid;

     pid = fork();
     if (pid == 0) 
          {
			  ChildProcess();
		  }
     else 
          {
			  wait(NULL);
			  ParentProcess();
		  }
      exit(0);
}

