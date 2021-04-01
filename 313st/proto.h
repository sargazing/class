#ifndef __PROTO_H
#define __PROTO_H

#define BUFSIZE 10
#define PROID 1
#define STR "/etc/passwd"

#define ERROR(key, stat) if(EOF == key) {perror("stat()"); exit(1);}

typedef struct msgbuf
{
	long mtype;
	char arr[BUFSIZE];
}msgbuf_t;

#endif
