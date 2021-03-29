#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int data;
	int p;
LOOP:
	printf("输入:");

	scanf("%d", &data);
	getchar();
	fflush(NULL);

	p = fork();

	if(p == -1)
	{
		perror("fork()");
	}
	if(p == 0)
	{
		for(int i = 0; i < 5; i++)
		{
			printf("%d\n", data + i);
			sleep(1);
		}
		exit(data);
	}
	wait(&data);	
	
	if(data == 0)
		exit(0);

	goto LOOP;
//	myfork(data);
}
