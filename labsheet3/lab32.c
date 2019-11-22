#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>   
#include<stdlib.h>

#define   MAX_COUNT  200
void Circle(float r)
{
		float area,perimeter,pi=3.14;
		 area=pi*r*r;
		 perimeter=2*pi*r;
		 printf("Area of Circle : %f\n",area); 
		 printf("Perimeter: %f\n",perimeter);
}
void  Square(float a)
{
		 float area,perimeter;
		 area=a*a;
		 perimeter=4*a;
		 printf("Area of square: %f\n",area);
		 printf("Perimeter of square: %f\n",perimeter);
}           
int  main()
{
     float a;
     printf("Enter a value : ");
     scanf("%f",&a);
       pid_t  pid;
       pid = fork();
	 if(pid==0)
	 {
		 Square(a);
	 }
	 else
	 {
		 wait(NULL);
		 pid_t pid2=vfork();
		 if(pid2==0)
			Circle(a);
		 else
			wait(NULL);
	 }
     exit(0);
}


