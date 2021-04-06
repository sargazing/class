#include<signal.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

char key = 0;
//char *str = "abcde";
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void _stop(void *s)
{
	printf("___________________\n");
}

void *show(void *s)
{
	pthread_cleanup_push(_stop, NULL);

	while(1)
	{
		pthread_mutex_lock(&lock);

		if(key == EOF)
		{
			pthread_mutex_unlock(&lock);
			pthread_exit(_stop);
		}
		write(1, (char *)s + key, 1);
		key++;
		if(key == 5)
			key = 0;
		pthread_mutex_unlock(&lock);
	}
	pthread_cleanup_pop(NULL);
}

void stop(int s)
{
	pthread_mutex_lock(&lock);

	key = -1;

	pthread_mutex_unlock(&lock);

	return;
}
int main(void)
{
	char *str = "abcde";

	pthread_t tid[5] = {};

	struct sigaction alm;

	alm.sa_handler = stop;

	sigaction(SIGALRM, &alm, NULL);

	alarm(1);

	for(int i = 0; i < 5; i++)
	{
		pthread_create(tid + i, NULL, show, (void *)str);
	}
	for(int i = 0; i < 5; i++)
	{
		pthread_join(tid[i], NULL);
	}
	
	pthread_mutex_destroy(&lock);

	return 0;
}
