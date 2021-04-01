#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define SIZE 10

int main(int argc, char *argv[])
{
	int arr[2] = {};
	int pid;

	if(pipe(arr) == -1)
	{
		perror("pipe()");

		exit(1);
	}

	pid = fork();
	if(pid == -1)
	{
		close(arr[1]);
		close(arr[0]);
		perror("fork()");
		exit(1);
	}
	if(pid == 0)
	{
		close(arr[0]);
		write(arr[1], "hello world", 11);
		close(arr[1]);

		exit(1);
	}
	close(arr[1]);

	char buf[SIZE];
	pid = read(arr[0], buf, SIZE);

	write(1, buf, pid);

	wait(NULL);


	return 0;
}

