#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"tbf2.h"
#define BUFSIZE 10

void *handler(void *s)
{
	int id = tbfInit(10, 1000);
	printf("%d\n", id);
	int cnt;
	while(1)
	{
		cnt = tbfFetch(id, BUFSIZE);

		write(1, "___________", cnt);
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return 1;

	int k = tbfInit(10, 1000);
	printf("%d\n", k);
	int cnt = 0;
	
	int fd = open(argv[1], O_RDONLY);

	char buf[10];

	pthread_t tid;

	pthread_create(&tid, NULL, handler, NULL);
	while(1)
	{
		cnt = tbfFetch(k, BUFSIZE);

		cnt = read(fd, buf, cnt);
		if(cnt == 0)
			return 0;

		write(1, buf, cnt);

	}
}
