#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>

#define STRSIZE 10
struct msg
{
	int mflag;
	char str[STRSIZE];
};

int main(int argc, char *argv[])
{
	struct msg buf;
	int msgid;

	msgid = msgget(IPC_PRIVATE, IPC_CREAT | IPC_EXCL | 0600);
	if(msgid == -1)
	{
		if(errno == EEXIST)
		{
			msgid = msgget(IPC_PRIVATE, 0);
		}
		else
		{
			perror("msgset()");
			exit(1);
		}
	}
	int pid = fork();
	if(pid == -1)
	{
		perror("fork()");
		exit(1);	
	}
	if(pid == 0)
	{
		buf.mflag = 1;
		strncpy(buf.str, argv[1], STRSIZE - 1);
		msgsnd(msgid, &buf, STRSIZE, 0);	
		exit(0);
	}

	wait(NULL);

	msgrcv(msgid, &buf, STRSIZE, 0, 0);

	puts(buf.str);

	exit(0);

}
