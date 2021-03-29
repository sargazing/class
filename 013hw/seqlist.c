#include"seqlist.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

seqlist_t *seqlist_int(int size)
{
	seqlist_t *p;

	p = malloc(sizeof(seqlist_t));

	p -> size = size;

	p -> arr = NULL;

	p -> nmemb = 0;

	return p;
}

int seqlist_add(seqlist_t *p, const void *data)
{
	p -> arr = realloc(p -> arr, p -> size * (p -> nmemb + 1));

	if(p -> arr == NULL)
		return -1;

	memcpy((char *)p -> arr + p -> size * p -> nmemb, data, p -> size);

	p -> nmemb ++;

	return 0;
}

void seqlist_travel(const seqlist_t *p,void (*show)(void *data))
{ 
	for(int i = 0; i < p -> nmemb; i++)
		show((char *)p -> arr + i * p -> size);
}
void *seqlist_find(const seqlist_t *p, const void *key, cmp_t cmp)
{
	for(int i = 0; i < p -> nmemb; i++)
		if(cmp((char *)p -> arr + i * p -> size, key))
			return (char *)p -> arr + i * p -> size;
	return NULL;
}

void *seqlist_del(seqlist_t *p, const void *key, cmp_t cmp)
{
	char *k = seqlist_find (p, key, cmp);

	if(k == (char *)p -> arr + p -> size * (p-> nmemb - 1))
	{
		p -> arr = realloc(p -> arr , p -> size * (p -> nmemb - 1));
	
		p -> nmemb --;

		return p;
	}
	if(k)
	{
		memcpy(k, k + p -> size, (char *)p -> arr + p -> size * (p -> nmemb - 1) - k);
		
		p -> arr= realloc(p -> arr , p -> size * (p -> nmemb - 1));

		p -> nmemb --;
	}
	return p;
}
int seqlist_update(const seqlist_t *p, const void *key, cmp_t cmp, const void *newdata)
{
	char *k = seqlist_find (p, key, cmp);

	if(k)
	{
		memcpy(k, newdata, p -> size);
	
		return 1;
	}
	return 0;
}
void seqlist_des(seqlist_t *p)
{
	free(p -> arr);
	p -> arr = NULL;
	free(p);
	p =NULL;	
}

