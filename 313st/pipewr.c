#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define SIZE 10

void capsLock(char **buf);

int main(int argc, char **argv)
{
	if(argc < 2)
		exit(1);

	int fd[2] = {};
//	char buf[SIZE] = {};a
	char *buf = malloc(SIZE);
	int key;
	int rdfd;

	rdfd = open(argv[1], O_RDONLY);
	if(rdfd == EOF)
	{
		perror("open()");
		exit(1);
	}

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
		wait(NULL);
		close(fd[1]);
		while(1)
		{
			key = read(fd[0], buf, SIZE - 1);

			if(key == 0)
				break;
			capsLock(&buf);

			write(1, buf, key);
			
		}
		close(fd[0]);
		exit(0);
	}
	
	close(fd[0]);
	while(1)
	{
		key = read(rdfd, buf, SIZE - 1);
		if(key == -1)
		{
			close(fd[1]);
			close(rdfd);
			perror("read()");
			exit(1);
		}
		if(key == 0)
			break;
		write(fd[1], buf, key);

	}
	close(fd[1]);

	return 0;
}
void capsLock(char **buf)
{
	for(int i = 0; *((*buf) + i) != '\0'; i++)
	{
		if(*((*buf) + i) <= 'Z' && *((*buf) + i) >= 'A')
			*((*buf) + i) += 'a' - 'A';	
		else if(*((*buf) + i) <= 'z' && *((*buf) + i) >= 'a')
			*((*buf) + i) -= 'a' - 'A';
	}

}
