#ifndef __TBF__
#define __tbf__

enum{NOSTART, STARTED};

typedef struct tbf_st
{
	int token;
	int cps;
	int max;
}tbf_t;

int tbfInit(int max, int cps);

void tbfAdd(int s);

int tbfFetch(int num, int size);

void tbfDes(int num);

void tbfReturn(int id, int ntoken);

void tbfDesAll(void);
#endif
