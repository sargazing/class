#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc, char **argv)
{
	int fd  = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}

	printf("%ld\n", lseek(fd, 0, SEEK_END));

	int key = write(fd, "HELLOWORLD", 10);
	if(key == -1)
	{
		perror("write()");
		return 1;
	}

	printf("%ld\n", lseek(fd, 50, SEEK_SET));
	
	key = write(fd, "HELLOWORLD", 10);
				
	if(key == -1)
	{
		perror("write()");
		return 1;
	}

	return 0;
}
