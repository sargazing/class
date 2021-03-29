#ifndef __LIST
#define __LIST

typedef struct list{
	void *data;
	struct list *next;
	struct list *last;
}_list;

typedef struct {
	_list head;
	int size;
	int nmemb;
}head_list;

enum{HEAD, TAIL};

typedef int cmp_t(void *a, void *b);
typedef void show_t(void *a);

static int del(_list *arr);

int bothlist_init(int size, head_list **arr);

int bothlist_add(head_list *arr, int way, void *data);

void bothlist_traval(head_list *arr, show_t show);

void bothlist_del(head_list *arr, void *data, cmp_t cmp);

_list *bothlist_find(head_list *arr, void *data, cmp_t cmp);

void *bothlist_fetch(head_list *arr, void *data, cmp_t cmp);
int bothlist_empty(head_list *arr);
void free_headlist(head_list *arr);
#endif
