#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <ctype.h>
#define size 20

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
	int shmid1=shmget(IPC_PRIVATE,sizeof(int)*size,IPC_CREAT|0666);
	int shmid2=shmget(IPC_PRIVATE,2,IPC_CREAT|0666);
	int shmid3=shmget(IPC_PRIVATE,2,IPC_CREAT|0666);
	int semid=semget(IPC_PRIVATE,3,IPC_CREAT|0777);
	int *front=(int*)shmat(shmid2,0,0);
	int *rear=(int*)shmat(shmid3,0,0);
	*front=*rear=-1;
	semctl(semid, 0, SETVAL,size);//empty
	semctl(semid,1,SETVAL,0);//full 
	semctl(semid,2,SETVAL,1);//mutex
	pid_t pid=fork();
	if(pid==0)
	{
		//producer
		for(int i=0;i<10;i++)
		{
			int *a=(int*)shmat(shmid1,0,0);
			int item=rand()%1000;
			int *front=(int*)shmat(shmid2,0,0);
			int *rear=(int*)shmat(shmid3,0,0);
			struct sembuf semb;
			sem_lock(0,semb,semid);	
			sem_lock(2,semb,semid);
			if(*front==-1)
			{
				a[0]=item;
				*front=*rear=0;
				printf("Produced %d at index %d \n",item,0);
			}
			else
			{
				a[*rear]=item;
				printf("Produced %d at index %d \n",item,*rear);
			}
			*rear=(*rear+1)%size;
			sem_unlock(2,semb,semid);
			sem_unlock(1,semb,semid);
		
		}	
	}
	else
	{
		//consumer
		for(int i=0;i<10;i++)
		{
			int *a=(int*)shmat(shmid1,0,0);
			int *front=(int*)shmat(shmid2,0,0);
			int *rear=(int*)shmat(shmid3,0,0);
			struct sembuf semb;
			sem_lock(1,semb,semid);	
			sem_lock(2,semb,semid);
			if(*front==size)
				*front=0;
			printf("Consumed %d at index %d\n",a[*front],*front);
			if(*front==*rear)
				*front=*rear=-1;
			else
			{
				*front=*front+1;
			}
			sem_unlock(2,semb,semid);
			sem_unlock(0,semb,semid);
		}
		
	}
	return 0;
}

