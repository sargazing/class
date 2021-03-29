#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#define BUFSIZE 10
int main(int argc , char *argv[])
{
	if(argc < 2)
		return 1;

#if 0
	int k = open(argv[1], O_RDWR);

	if(k == -1)
	{
		printf("%d\n", errno);
		perror("open()");
	}
	printf("%d\n", k);

	return 0;
#endif

	int fd = open(argv[1], O_RDWR | O_CREAT , 0666);

	if(fd == -1)
	{
		perror("open()");
	}
	
	char buf[BUFSIZE];

	int key = read(fd, buf, BUFSIZE);
	
	while(1)
	{
		if(key == -1)
		{
			perror("read()");
//			goto LOOP;
		}
		puts(buf);

		close(fd);
	}
}
