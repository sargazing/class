#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include"tbf.h"
#include<stdlib.h>

#define SIZE 1024

static int flag = NOSTART;

static struct tbf_st *tbf[SIZE];

int tbfInit(int max, int cps)
{
	if(flag == NOSTART)
	{
		signal(SIGALRM, tbfAdd);
		alarm(1);
		flag = STARTED;
	}
	for(int i = 0; i < SIZE; i++)
	{
		if(tbf[i] == NULL)	
		{	
			tbf[i] = malloc(sizeof(struct tbf_st));
			tbf[i]->token = 0;
			tbf[i]->cps = cps;
			tbf[i]->max = max;
		}	
		return i;
	}
	return -1;
}

void tbfAdd(int s)
{
	alarm(1);
	for(int i = 0; i < SIZE; i++)
	{
		if(tbf[i] != NULL)	
		{
			tbf[i]->token += tbf[i]->cps;
			if(tbf[i]->token >= tbf[i]->max)
				tbf[i]->token = tbf[i]->max;	
		}
	}	

}

int tbfFetch(int num, int size)
{
	int data;
	if(num < 0 && num >= SIZE)
		return -2;
	
	if(tbf[num] != NULL && tbf[num]->token >= size)
	{
		tbf[num]->token -= size;
		
		return size;
	}
	else if(tbf[num] != NULL)
	{
		data = tbf[num]->token;
		
		tbf[num] = 0;
		
		return data;
	}
	return -1;
}

void tbfDes(int num)
{
	if(num >= 0 && num < SIZE && tbf[num] != NULL)
		free(tbf[num]);
		tbf[num] = NULL;
}
void tbfDesAll(void)
{
	for(int i = 0; i < SIZE; i++)
	{
		tbfDes(i);
	}
}

void tbfReturn(int id, int ntoken)
{
	if(id < 0 && id >= SIZE)
		return;
	tbf[id]->token += ntoken;

	if(tbf[id]->token > tbf[id]->max)
		tbf[id]->token = tbf[id]->max;
}
