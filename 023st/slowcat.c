#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"tbf.h"

int main(int argc, char **argv)
{
	if(argc < 2)
		return 1;

	int k = tbfInit(10, 1000);

	int cnt = 0;
	
	FILE *fp = fopen(argv[1], "r");

	char buf[11];

	while(1)
	{
		buf

		pause();

		printf("%d %d\n", tbfFetch(k, 10), cnt++);
	}
	exit(0);
}
