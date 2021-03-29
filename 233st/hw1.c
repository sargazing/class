#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

#define MINNUM 100
#define MAXNUM 300
#define BLOCK 50

void myloop(int i);
int isprime(int num);
int main()
{
	int p;

	for(int i = MINNUM; i < MAXNUM; i += 50)
	{
		p = fork();

		if(p == -1)
		{
			perror("fork()");
			exit(1);
		}
		if(p == 0)
		{
			myloop(i);
		}
	}
	for(int k = 0; k < 4; k++)
		wait(NULL);
	return 0;
}
void myloop(int i)
{
	int cnt = BLOCK;
	if(i == MAXNUM - BLOCK)
		cnt ++;
	while(cnt--)
	{
		if(isprime(i + cnt))
			printf("[%d]%d\n", getpid(), i + cnt);	
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
