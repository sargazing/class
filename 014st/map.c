#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<unistd.h>

#define SIZE 1024

int main()
{
	int pid;
	char *buf;
	
	buf = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,\
		   	MAP_ANONYMOUS | MAP_SHARED, -1, 0);

	if(buf == MAP_FAILED)
	{
		perror("mmap()");
		exit(1);
	}
	pid = fork();
	if(pid == -1)
	{
		goto ERROR;
	}
	if(pid == 0)
	{
		strcpy(buf, "hello WORLd");
		exit(0);
	}
	wait(NULL);

	puts(buf);

	munmap(buf, SIZE);

	exit(0);

ERROR:
	munmap(buf, SIZE);
	
	exit(1);
}
