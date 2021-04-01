#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc, char *argv[])
{
	int shmid;
	char *data;
	int pid;

	shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | IPC_EXCL | 0600);

	if(EOF == shmid)
	{
		if(errno == EEXIST)
		{			
			shmid = shmget(IPC_PRIVATE, 1024, 0);
		}
		else
		{
			perror("shmget()");

			exit(1);
		}
	}
	pid = fork();
	if(pid == EOF)
	{
		shmctl(shmid, IPC_RMID, NULL);
		
		perror("fork()");
		
		exit(1);
	}
	if(0 == pid)
	{
		data = shmat(shmid, NULL, 0);
		
/*		if((void *)EOF == data);
		{
			perror("shmat()");
			exit(1);
		}
*/		strcpy(data, argv[1]);
		
		if(shmdt(data) == -1)
		{
			perror("shmdt()");
			exit(1);
		}
		exit(0);	
	}
	wait(NULL);

	data = shmat(shmid, NULL, 0);

/*	if((void *)EOF == data);
	{
		perror("shmat()");
		exit(1);
	}*/
	puts(data);

	if(shmdt(data) == -1)
	{
		perror("shmdt()");
		exit(1);
	}
//	exit(0);	

	exit(0);
}
