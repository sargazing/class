#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<glob.h>

void mysystem(char *arr);

int main()
{
	mysystem("pwd");
	
	printf("____________________\n");

	exit(0);
}

void mysystem(char *arr)
{
	char *buf = malloc(strlen(arr) + 1);
	char *split_buf;
	char *str;
	int cnt = 0;
	glob_t tmp;
	int pid;
	
	strcpy(buf, arr);

	str = buf;

	while(1)
	{
		split_buf = strsep(&str, " ");

		glob(split_buf, GLOB_NOCHECK | GLOB_APPEND * cnt , NULL, &tmp);
		
		cnt = 1;

		if(str == NULL)
			break;
	}
	pid = fork();

	if(pid == 0)
	{
		execvp((tmp.gl_pathv)[0], tmp.gl_pathv);
		perror("fork()");
		exit(1);
	}
	wait(NULL);
	free(buf);
	buf = NULL;
	globfree(&tmp);
	return;
}
