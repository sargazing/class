#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	int k;

	pid = fork();

	if(pid == 0)
	{
//		setpgid(getpid(), getpid());

		printf("CCC:pid:%d pgid:%d\n", getpid(), getpgid(getpid()));
	
		exit(0);
	}
	k = waitpid(-1, NULL, 0);

	printf("FFF:pid:%d pgid:%d\n %d %d\n", getpid(), getpgid(getpid()), k, pid);

	exit(0);
}
