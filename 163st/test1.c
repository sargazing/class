#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char **argv)
{
	int i, j;
	char arr[5] = ">>>>";
	
//	if(argc > 2 && !strcmp(arr, argv[1]))
//	{
	int k = open("asdgfqwe", O_WRONLY);
		int fd = open("asd", O_WRONLY/* | O_CREAT | O_TRUNC*/, 0666);
		dup2(3, 2);
		printf("%d\n", fd);
		if(k == -1)
		{
			perror("open()");
			return 1;
		}

//		dup2(fd, 1);
//	}

	for(i = 0; i < 10; i++)
	{
		for(j = 10 - i; j > 0; j--)
			printf(" ");
		for(j = i; j > 0; j--)
			printf(" *");
		printf("\n");
	}
	return 0;
}
