#include<stdio.h>
#include<time.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<syslog.h>
#include<errno.h>

#define SIZE 1024

int mylock(void);
int mydeamon(void);
int main()
{
	int fd;
	time_t ti;
	struct tm *buf;
	char arr[SIZE];
	int p;
	fd = open("/tmp/out", O_WRONLY | O_APPEND | O_TRUNC, 0666);
	if(fd == -1)
	{
		perror("open()");
		exit(1);
	}
	openlog(NULL, LOG_PID, LOG_CRON);
	if(mydeamon() == -1)
	{
		syslog(LOG_ERR, "%s", strerror(errno));
		exit(1);
	}
	if(mylock() == -1)
	{
		syslog(LOG_ERR, "mylock error");

		exit(1);
	}

	while(1)
	{
	p = fork();	
	if(p == 0)
	{
		time(&ti);

		buf = localtime(&ti);
		
		strftime(arr, SIZE, "%Y-%m-%d %H:%M:%S", buf);
		
//		printf("%s\n", arr);

		write(fd, arr, strlen(arr));

		write(fd, "\n", 1);

		exit(0);
	}
	sleep(1);
	}
} 
int mydeamon(void)
{
	int key = fork();
	if(key == -1)
	{
		perror("fork()");
		return -1;
	}
	if(key > 0)
	{
		exit(0);
	}
	if(setsid() == -1)
	{
		perror("strsid()");
		return -1;
	}
	chdir("/");
	umask(0);

	key = open("/dev/null", O_RDWR);
	if(key == -1)
	{
		perror("open()");
		return -1;
	}
	dup2(key, 0);
	dup2(key, 1);
	dup2(key, 2);

	if(key > 2)
		close(key);
}
int mylock(void)
{
	int fp;
	char arr[SIZE];

	fp = open("/var/run/daemon.pid", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if(fp == -1)
	{
		syslog(LOG_ERR, "%s", strerror(errno));
		
		return -1;
	}

	if(lockf(fp, F_TLOCK, 0) == -1 )
	{
		syslog(LOG_ERR, "%s", strerror(errno));
		close(fp);
		return -1;
	}

	sprintf(arr, "%d", getpid());

	puts(arr);

	write(fp, arr, strlen(arr));

	return 0;
}
