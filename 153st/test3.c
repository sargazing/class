#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>


int main(int argc, char **argv)
{
	if(argc < 2)
		return -1;
	int key;

	int rfd = open(argv[1], O_RDONLY);
	if(rfd == -1)
	{
		perror("open()");
	}

	int i = lseek(rfd, 0, SEEK_SET);

	read(rfd, &key, 1);

	int j = lseek(rfd, 0, SEEK_CUR);
	printf("%d   %d\n", i, j);
}
