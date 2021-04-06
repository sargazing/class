#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>      
#include<fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

#define SIZE 10

static int semid;
static int P(void);
static int V(void);
int main()
{
	int key, pid = 0;
	char arr[SIZE];

	key = open("/tmp/out", O_RDWR | O_CREAT | O_TRUNC, 0664);
	if(key == -1)
	{
		perror("open()");
		exit(1);
	}

	write(key, "0", 1);

	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0600);

	if(semid == -1)
	{
		if(EEXIST == errno)
			semid = semget(IPC_PRIVATE, 1, 0);
		else
		{
			perror("semid()");
			close(key);
			exit(1);
		}
	}

	pid = semctl(semid, 0, SETVAL , 1);

	//if error

	for(int i = 0 ; i < 20; i++)
	{
		pid = fork();
		
		if(pid == -1)
		{
			close(key);
			perror("fork()");
			exit(1);
		}
		if(pid == 0)
		{
			P();
			lseek(key, 0, SEEK_SET);
			

			read(key, &arr, 2);
			
			//puts(arr);

			snprintf(arr, SIZE, "%d", atoi(arr) + 1);

			lseek(key, 0, SEEK_SET);
			
			write(key, arr, strlen(arr));

			V();

			close(key);

			exit(0);
		}
	}
	for(int i = 0; i < 20; i++)
		wait(NULL);

	close(key);

	return 0;
}
static int P(void)
{
	 struct sembuf buf;

	 buf.sem_num = 0;
	 buf.sem_op = -1;
	 buf.sem_flg = 0;

	 if(semop(semid, &buf, 1) == -1)
	 {
	 	return -errno;
	 }
	 return 0;

}
static int V(void)
{
	 struct sembuf buf;

	 buf.sem_num = 0;
	 buf.sem_op = 1;
	 buf.sem_flg = 0;

	 if(semop(semid, &buf, 1) == -1)
	 {
	 	return -errno;
	 }
	 return 0;
}
