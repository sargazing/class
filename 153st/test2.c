#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>


int main(int argc, char **argv)
{
	if(argc < 3)
		return -1;

	int rfd = open(argv[1], O_RDONLY);
	if(rfd == -1)
	{
		perror("open()");
		goto RDERR1;
	}

	int wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	if(wfd == -1)
	{
		perror("open()");
		goto RDERR2;
	}
	char buf[1];
	int cnt, key;

	int i = lseek(rfd, -1, SEEK_END);
	if(i == -1)
	{
		return -1;
	}

	while(1)
	{
		cnt = read(rfd, buf, 1);
		if(cnt == -1)
		{
			perror("read()");
			goto RDERR;
		}

		key = write(wfd, buf, 1);
		if(key == -1)
		{
			perror("write()");
			goto RDERR;
		}
		if(i == 0)
			break;

		i = lseek(rfd, -2, SEEK_CUR);
	}
	
	close(wfd);
	close(rfd);
	return 0;

RDERR:
	close(wfd);
RDERR2:
	close(rfd);
RDERR1:
	return -1;
}
