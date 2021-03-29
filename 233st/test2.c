#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void per(int i)
{
	i++;
	int p = fork();
	
	if(p == -1)
	{
		perror("fork()");
		exit(1);
	}
	if(p == 0 && i != 300)
	{
		for(int j = 2; j < i; j++)
		{
			if(i % j == 0)
				exit(0);
		}
		printf(" %d " , i);
		exit(0);
	}
	if(i <= 300)
		per(i);
		for(int j = 201; j > 0; j++)
		wait(NULL);
	exit(0);
}
int main()
{
	int i = 99;
	per(i);
}

