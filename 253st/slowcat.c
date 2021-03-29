#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define CPS 10
#define MAX 100

static int key = 0;

static void test(int k)
{
	alarm(1);
	key += CPS;
	if(key > MAX)
		key = MAX;
}
static void test2(int k)
{
	;
}

int main(int argc, char **argv)
{
	if(argc < 2)
		exit(1);

	alarm(1);
	signal(14, test);

	int cnt = 0;

	cnt = open(argv[1], O_RDONLY);

	printf("wourd%d\n", cnt++);
	while(1)
	{

		while(key < CPS)
			pause();
		key -= CPS;

		printf("hello%d\n", cnt++);
	}
	exit(0);
}
