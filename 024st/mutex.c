#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THRNR	4
#define START	100
#define END		300

/*
 job > 0所发放的任务
 job == 0 任务已经被取走
 job == -1 所有任务发放完成
 */
static int job = 0; // 临界区
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int isprime(int s)
{	for(int i = 2; i < s; i++)
	{
		if(s % i == 0)
			return 0;
	}
	return 1;
}

static void *thr_job(void *s)
{
	int data;
	while(1)
	{
		pthread_mutex_lock(&mut);
		while(job == 0)
		{
			pthread_cond_broadcast(&cond);
			pthread_cond_wait(&cond, &mut);
			
		//	sched_yield();
			
		//	continue;
		}
		if(job == EOF)
		{
			pthread_mutex_unlock(&mut);
			pthread_cond_broadcast(&cond);
			pthread_exit(NULL);
		}

		data = job;
		job = 0;
		pthread_mutex_unlock(&mut);
		pthread_cond_broadcast(&cond);
		if(isprime(data))
			printf("%d\n", data);
	}

}

int main(void)
{
	pthread_t tids[THRNR] = {};
	int i;

	for (i = 0; i < THRNR; i++)	{
		pthread_create(tids+i, NULL, thr_job, NULL);
		// if error
	}
	for (i = START; i <= END; i++) {
		pthread_mutex_lock(&mut);
		while (job != 0) {
		pthread_cond_broadcast(&cond);
		pthread_cond_wait(&cond, &mut);
		}
		job = i;
		pthread_mutex_unlock(&mut);
		pthread_cond_broadcast(&cond);
	}
	pthread_mutex_lock(&mut);
	while (job > 0) {
		pthread_cond_broadcast(&cond);
		pthread_cond_wait(&cond, &mut);
	}
	job = -1;
	pthread_mutex_unlock(&mut);

	for (i = 0; i < THRNR; i++)
		pthread_join(tids[i], NULL);

	pthread_mutex_destroy(&mut);

	exit(0);
}







