#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

typedef void (*app_t)(int);

void test(int k)
{
	printf("%d!\n", k);
	sleep(2);
	printf("%d!\n", k);
	write(2, "__", 5);
}

int main()
{
//	printf("%d\n", SIGSTOP);
	app_t sss;
	sss = signal(2, test);

/*	if(signal(SIGQUIT, sss) == SIG_ERR)
	{
		perror("signal()");
		exit(1);
	}*/
	while(1)
	{
		write(1, "*", 1);
		sleep(1);		
	}
}
