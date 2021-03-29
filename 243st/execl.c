#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	printf("main start\n");

	char *arr[] = {"ls", "-l", "-a", "-i", NULL};

	int p = fork();

	if(EOF == p)
	{
		perror("fork()");
		exit(1);
	}
	if(0 == p)
	{
		execlp("ls","ls", "-lia",  NULL);
	//	execv("../223st/myls", /*"../223st/myls","ls", "-a", "/", NULL*/\
				arr);
	//	execvp("ls", arr);
		perror("execl()");
		exit(1);
	}

	wait(NULL);

	printf("main end\n");

	exit(0);
}
