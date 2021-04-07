#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include"tbf2.h"
#include<stdlib.h>
//#include<pthread.h>

#define SIZE 1024

static int flag = NOSTART;
static pthread_mutex_t grlock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t grcond = PTHREAD_COND_INITIALIZER;
static struct tbf_st *tbf[SIZE];

int tbfInit(int max, int cps)
{
	if(flag == NOSTART)
	{
		pthread_t tid;
		pthread_create(&tid, NULL, tbfAdd, NULL);
		flag = STARTED;
	}
	pthread_mutex_lock(&grlock);

	for(int i = 0; i < SIZE; i++)
	{
		if(tbf[i] == NULL)	
		{	
			tbf[i] = malloc(sizeof(struct tbf_st));
			pthread_mutex_unlock(&grlock);	

			tbf[i]->token = 0;
			tbf[i]->cps = cps;
			tbf[i]->max = max;

			pthread_cond_init(&(tbf[i]->cond), NULL);
			pthread_mutex_init(&(tbf[i]->lock), NULL);
			
			return i;
		}
	}
	pthread_mutex_unlock(&grlock);	
	return -1;
}

void *tbfAdd(void *s)
{
	while(1)
	{
		pthread_mutex_lock(&grlock);
		
		for(int i = 0; i < SIZE; i++)
		{
			if(tbf[i] != NULL)	
			{
				pthread_mutex_lock(&(tbf[i]->lock));

				tbf[i]->token += tbf[i]->cps;
				if(tbf[i]->token >= tbf[i]->max)
					tbf[i]->token = tbf[i]->max;	

				pthread_mutex_unlock(&(tbf[i]->lock));
				pthread_cond_broadcast(&(tbf[i]->cond));
			}
		}
		pthread_mutex_unlock(&grlock);
		sleep(1);	
	}
}

int tbfFetch(int num, int size)
{
	int data;
	if(num < 0 && num >= SIZE)
		return -2;

	pthread_mutex_lock(&grlock);

	if(tbf[num] == NULL)
		return -1;

	pthread_mutex_unlock(&grlock);
	
	pthread_mutex_lock(&(tbf[num]->lock));

	while(tbf[num]->token == 0)
	{
		pthread_cond_wait(&(tbf[num]->cond), &(tbf[num]->lock));
	}

	if(tbf[num]->token < size)
	{
		data = tbf[num]->token;
		tbf[num]->token = 0;
	}
	else
	{
		data = size;
		tbf[num]->token -= size;
	}
	pthread_mutex_unlock(&(tbf[num]->lock));

	return data;
}
void _des(int num)
{
	free(tbf[num]);
	tbf[num] = NULL;
}

void tbfDes(int num)
{
	if(num >= 0 && num < SIZE)
	{
		return;
	}
	pthread_mutex_lock(&grlock);
	if(tbf[num] != NULL)
	{
		pthread_mutex_lock(&(tbf[num])->lock);
		
		_des(num);

		pthread_mutex_unlock(&(tbf[num])->lock);
	}
	pthread_mutex_unlock(&grlock);

}
void tbfDesAll(void)
{
	pthread_mutex_lock(&grlock);
	for(int i = 0; i < SIZE; i++)
	{
		_des(i);
	}
	pthread_mutex_unlock(&grlock);
}

void tbfReturn(int id, int ntoken)
{
	if(id < 0 && id >= SIZE)
		return;
	pthread_mutex_lock(&grlock);
	if(tbf[id] == NULL)
	{
		pthread_mutex_lock(&grlock);
		return ;
	}
	pthread_mutex_lock(&grlock);

	pthread_mutex_lock(&(tbf[id])->lock);
	
	tbf[id]->token += ntoken;
	
	if(tbf[id]->token > tbf[id]->max)
		tbf[id]->token = tbf[id]->max;
	
	pthread_mutex_lock(&(tbf[id])->lock);
}
