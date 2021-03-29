#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int num = 99;

	int p = vfork();

	if(-1 == p)
	{
		perror("vfork()");
		exit(1);
	}
	if(0 == p)
	{
		printf("[%d]%d\n", getpid(), ++num);
		sleep(1);
		_exit(0);
	}
	
	printf("[%d]%d\n", getpid(), ++num);
	exit(0);
}
