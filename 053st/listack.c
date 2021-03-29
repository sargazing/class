#include"lstack.h"

int lstack_init(head_lstack **arr, int size)
{
	return bothlist_init(size, arr);
}

int lstack_push(head_lstack *arr, void *data)
{
	return bothlist_add(arr, 0, data);
}
static int cmp(void *data, void *data2)
{
	return 0;
}

int lstack_empty(head_lstack *arr)
{
	bothlist_empty(arr);
}

void *lstack_pop(head_lstack *arr, void *data)
{
	return bothlist_fetch(arr, data, cmp);	
}

void lstack_des(head_lstack *arr)
{
	free_headlist(arr);
}
