#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int fd;

	fd = open("hello", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		
	if(fd == -1)
	{
		perror("open()");
		return 1;
	}


	dup2(fd, 1);

	printf("hello every one\n");

	close(fd);

	return 0;
}
