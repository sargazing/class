#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int p;
	p = fork();
	if(p == 0)
	{
		for(int i = 0; i < 50; i++)
			printf("son\n");
		exit(0);
	}
	p = fork();
	if(p == 0)
	{
		for(int i = 0; i < 50; i++)
			printf("daughter\n");
		exit(0);
	}	
	for(int i = 0; i < 100; i++)
		printf("father\n");
	exit(1);
}
