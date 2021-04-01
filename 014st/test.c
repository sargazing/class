#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>      
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int key, pid = 0;
	char arr;
	key = open("/tmp/out", O_RDWR | O_CREAT | O_TRUNC, 0664);
	if(key == -1)
	{
		perror("open()");
		exit(1);
	}

	write(key, "0", 4);

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
			read(key, &arr, 1);
			lseek(key, 0, SEEK_SET);
			
			pid ++;

			write(key, &arr, 1);
			close(key);
			//printf("%d\n", pid++);
			exit(0);
		}
		sleep(1);
	}
	for(int i = 0; i < 20; i++)
		wait(NULL);

	close(key);

	return 0;
}

