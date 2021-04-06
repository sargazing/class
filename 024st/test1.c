#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 300
#define MINSIZE 100

void *isperm(void *num)
{
	int data = (int)num;
//	printf("%d\n", data);
	for(int i = 2; i < data; i++)
	{
		if(data % i == 0)
			return (void *)1;
	}
//	printf("%d\n", data);
	return NULL;
}

int main()
{
	pthread_t  num[MAXSIZE - MINSIZE + 1];
//	pthread_t *num = malloc(sizeof(pthread_t) * 201);
	int err;
	pthread_t tid;
	void *data;

	for(int i = MINSIZE; i <= MAXSIZE; i++)
	{
//		printf("%d\n", i);
		err = pthread_create(&num[i - MINSIZE], NULL, isperm, (void *)i);
		if(err)
		{
			fprintf(stderr, "%s", strerror(err));
			return 1;
		}
//		num[i - MINSIZE] = tid;
//		pthread_join(tid , &data);
//		if(data == (void *)0)
//			printf("%d\n", i + MINSIZE);
	}
	for(int i = 0; i < MAXSIZE - MINSIZE + 1; i++)
	{
		pthread_join(num[i] , &data);
		if(data == (void *)0)
			printf("%d\n", i + MINSIZE);
	}
	return 0;
}
