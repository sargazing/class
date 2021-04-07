#ifndef __TBF__
#define __TBF__
#include<pthread.h>

enum{NOSTART, STARTED};

typedef struct tbf_st
{
	int token;
	int cps;
	int max;
	pthread_mutex_t lock;
	pthread_cond_t cond;
}tbf_t;

int tbfInit(int max, int cps);

void *tbfAdd(void *s);

int tbfFetch(int num, int size);

void tbfDes(int num);

void _des(int num);

void tbfReturn(int id, int ntoken);

void tbfDesAll(void);
#endif
