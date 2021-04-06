#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *test(void *arr)
{
	for(int i = 0; i < 5; i++)
	{
		write(1, "$", 1);
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid;

	pthread_create(&tid, NULL, test, NULL);

	for(int i = 0; i < 3; i++)
	{
		write(1 ,"^", 1);
		sleep(1);
	}
//	printf("\n");
	
	pthread_exit(NULL);

	return 0;
}
