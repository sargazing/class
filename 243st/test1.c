#include<stdio.h>
#include<string.h>
#include<glob.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   	size_t size = 0;
	int pid;
	char *str;
	int k;
	char *brr;
	glob_t myglob;
	int cnt = 0;
	setenv("PWD", "~/work/243st", 1);

	while(1)
	{
		printf("[%s]$", getenv("PWD"));
		fflush(stdout);
		k = getline(&str, &size, stdin);
		if(strncmp("exit", str, strlen("exit")) == 0)
		{
			free(str);
			str = NULL;
			globfree(&myglob);
			exit(0);
		}
		if(k == -1)
		{
			if(ferror(stdin))
				perror("getline");
		}
		for(k = 0;  str[k] != '\n'; k++);
		str[k] = '\0';

		while(1)
		{
			brr = strsep(&str, " ");
			if(cnt == 0)
			{
				glob(brr, GLOB_NOCHECK, NULL, &myglob);
			}
			else
				glob(brr, GLOB_APPEND | GLOB_NOCHECK, NULL, &myglob);
			cnt ++;
			if(str == NULL)
				break;
		}
		pid = fork();
		
		if(pid == EOF)
		{
			perror("fork()");
			exit(1);
		}
		
		if(pid == 0)
		{
			execvp((myglob.gl_pathv)[0], myglob.gl_pathv);
			perror("execvp()");
			exit(1);
		}
//		free(str);
//		free(brr);
//		str = NULL;
//		brr = NULL;
//		globfree(&myglob);
	//	glob_t myglob;
	//	wait(NULL);
	//	exit(0);
		wait(NULL);
		cnt = 0;
	//	memset(str, '\0', sizeof(str));
	}
}

