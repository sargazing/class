#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define MINNUM 100
#define MAXNUM 300

void myloop(int i);
int isprime(int num);
int main()
{
	int p;

	for(int i = 0; i < 3; i ++)
	{
		p = fork();

		if(p == -1)
		{
			perror("fork()");
			exit(1);
		}
		if(p == 0)
		{
			myloop(i + MINNUM);
		}
	}
	for(int k = 0; k < 3; k++)
		wait(NULL);
	return 0;
}
void myloop(int i)
{
	for(;i < MAXNUM; i += 3)
	{
		if(isprime(i))
			printf("[%d]%d\n", getpid(), i);	
	}
	exit(0);
}
int isprime(int num)
{
	for(int i = 2; i < num ;i++)
	{
		if(num % i == 0)
			return 0;
	}
	return 1;
}
