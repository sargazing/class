#ifndef __LL
#define __LL

enum{HEAD, TAIL};

typedef struct llist{
	struct llist *next;
	struct llist *last;
	void data[0];
}_llist;

typedef struct {
	_llist head;
	int size;
	int nmemb;
}head_llist;

typedef int cmp_t(void *a, void *b);

int llist_init(head_llist **arr, int size);

int llist_push(head_llist *arr, void *data, int way);

int	llist_pop(head_llist *arr, void *data, cmp_t cmp);

int llist_top(head_llist *arr, void *data, void *newdata, cmp_t cmp);

static llist_del(_llist *brr);

static llist_add(_llist *arr, _llist *newdata, _llist *brr);
#endif
