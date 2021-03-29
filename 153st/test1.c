#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#define SIZE 1024

int main(int argc, char **argv)
{
	if(argc < 3)
		return 1;

	int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

	if(fd == -1)
	{
		perror("open()");

		goto OPERROR;
	}

	int fd2 = open(argv[1], O_RDONLY, 0666);

	if(fd2 == -1)
	{
		perror("read()");
		goto OPERROR2;
	}

	int key, cnt;
	char buf[SIZE];
	while(1)
	{
		cnt = read(fd2, buf, SIZE);

		if(cnt  == -1)
		{
			perror("read()");
			goto RDERROR;
		}
		if(cnt == 0)
		{
			break;
		}
		key = write(fd, buf, cnt);
		if(key == -1)
		{
			perror("write()");
			return 1;
		}
	}
	close(fd);
	close(fd2);
RDERROR:
	close(fd2);
OPERROR2:
	close(fd);
OPERROR:
	return 1;
}
