#ifndef __SEQLITE_H
#define __SEQLITE_H
typedef int (*cmp_t)(const void *a, const void *b);

typedef struct{
	void *arr;
	int size;
	int nmemb;
}seqlist_t;

seqlist_t *seqlist_int(int size);

int seqlist_add(seqlist_t *arr, const void *data);

void seqlist_travel(const seqlist_t *p,void (*show)(void *data));

void *seqlist_find(const seqlist_t *p, const void *key, cmp_t cmp);

void *seqlist_del(seqlist_t *p, const void *key, cmp_t cmp);

int seqlist_update(const seqlist_t *p, const void *key, cmp_t cmp, const void *newdata);

void seqlist_des(seqlist_t *p);

static void _revers_list();
#endif
