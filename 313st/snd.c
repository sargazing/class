#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<errno.h>

#include"proto.h"

int main(int argc, char *argv[])
{
	if (argc < 3)
		return 1;
	key_t key;
	char buf[BUFSIZE];
	int msgid;
	int flag = 1;
	msgbuf_t sd;
	
	
	key = ftok(STR, PROID);
	ERROR(key, ftok);

	msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0600);
	if(EOF == msgid)
	{
		if(errno == EEXIST)
		{
			msgid = msgget(key, 0);
			flag = 0;
		}
		else
		{
			perror("msgget()");
			exit(1);
		}
	}
	
	sd.mtype = atoi(argv[1]);
	strcpy(sd.arr, argv[2]);

	msgsnd(msgid, &sd, strlen(sd.arr) + 1, 0);

	if(flag)
		msgctl(key, IPC_RMID, NULL);

	exit(0);
}
