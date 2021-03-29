#ifndef __LLIST
#define __LLIST
#include<bothlist.h>

//aypedef _list _lstack;
typedef head_list head_lstack;

int lstack_init(head_lstack **arr, int size);

int lstack_push(head_lstack *arr, void *data);

int lstack_empty(head_lstack *arr);

void *lstack_pop(head_lstack *arr, void *data);

void lstack_des(head_lstack *arr);

static int cmp(void *data, void *data2);
#endif
