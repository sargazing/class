#include"llist.h"
#include<stdio.h>
#include<stdlib.h>

int llist_init(head_llist **arr, int size)
{
	head_llist *brr;
	brr = malloc(sizeof(head_llist));
	
	if(brr == NULL)
		return -1;

	brr->head.next = brr->head.last = &brr->head;
	brr->size = size;
	brr->nmemb = 0;
	brr->head.data= NULL;
}
int llist_push(head_llist *arr, void *data, int way)
{
	
}

static llist_add(_llist *arr, _llist *newdata, _llist *brr)
{
	newdata->next = arr->next;
	newdata->last = brr->last;
	arr->next =  brr->last = newdata;
}
int	llist_pop(head_llist *arr, void *data, cmp_t cmp);

int llist_top(head_llist *arr, void *data, void *newdata, cmp_t cmp);

static llist_del(_llist *brr);



