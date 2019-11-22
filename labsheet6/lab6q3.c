#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <semaphore.h>
#define NS 20 // size of each name
#define MAXS 50//size of buffer
void sem_lock(int semno,struct sembuf semb,int sem_id)
{
	semb.sem_num=semno;
	semb.sem_op=-1;
	semb.sem_flg=0;
	semop(sem_id,&semb,1);
}
void sem_unlock(int semno,struct sembuf semb,int sem_id)
{
	semb.sem_num=semno;
	semb.sem_op=1;
	semb.sem_flg=0;
	semop(sem_id,&semb,1);
}
int main()
{
	int semid=semget(IPC_PRIVATE,4,0777|IPC_CREAT);
	int shmid=shmget(IPC_PRIVATE,2,IPC_CREAT|0666);
	int *c=(int*)shmat(shmid,0,0);
	*c=50;
	semctl(semid,0,SETVAL,1);//event occured or not
	semctl(semid,1,SETVAL,1);//mutex
	semctl(semid,2,SETVAL,50);//empty spaces
	semctl(semid,3,SETVAL,0);//full spaces
	printf("Event A : Book a Seat, A\n");
	printf("Event B : Cancel Registration, B\n");
	do
	 {
		struct sembuf semb;
		sem_lock(0,semb,semid);
		printf("Enter Event: ");
		char ch=getchar();
		if(ch=='\n')
			ch=getchar();
		if(ch=='A')
		{
			pid_t pid=fork();
			if(pid==0)
			{
				int x=semctl(semid,2,GETVAL);
				if(x==0)
					sem_unlock(0,semb,semid);
				sem_lock(2,semb,semid);
				sem_lock(1,semb,semid);
				int *c=(int*)shmat(shmid,0,0);
				char str[20];
				printf("Enter name: ");
				scanf("%s",str);
				printf("Hello %s,your registration is confirmed \n",str);
				*c=*c-1;
				printf("Counter: %d\n",*c);
				sem_unlock(3,semb,semid);
				sem_unlock(1,semb,semid);
				sem_unlock(0,semb,semid);
			}
		}
		else if(ch=='B')
		{
			pid_t pid=fork();
			if(pid==0)
			{
				int *c=(int*) shmat(shmid,0,0);
				int x=semctl(semid,3,GETVAL);
				if(x==0)
					sem_unlock(0,semb,semid);
				sem_lock(3,semb,semid);
				sem_lock(1,semb,semid);
				char str[20];
				printf("Enter name: ");
				scanf("%s",str);
				printf("You are Deregisterd\n");
				*c=*c+1;
				printf("Counter: %d\n",*c);
				sem_unlock(2,semb,semid);
				sem_unlock(1,semb,semid);
				sem_unlock(0,semb,semid);
			}
		}
		else
		{
			sem_unlock(0,semb,semid);
		}
	 }while(1);
	return 0;
}
