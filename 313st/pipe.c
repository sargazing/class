#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#define SIZE 100

int main(void)
{
	int fd[2] = {};
	char buf[SIZE] = {};
	int key;

	if(pipe(fd) == EOF)
	{
		perror("pipe()");
		exit(1);
	}

	key = fork();

	if(key == -1)
	{
		close(fd[1]);
		close(fd[0]);
		perror("fork()");
		exit(1);
	}

	if(key == 0)
	{
		sleep(1);
		close(fd[0]);
		write(fd[1], "hello world", 11);
		close(fd[1]);
	}
	
	close(fd[1]);
	read(fd[0], buf, SIZE);
	close(fd[0]);
	puts(buf);

	wait(NULL);
	
	return 0;
}
