#include<stdio.h>
#include"bothlist.h"
#include<stdlib.h>
#include<string.h>

int bothlist_init(int size, head_list **arr)
{
	head_list *arr2 = malloc(sizeof(head_list));

	if(arr2 == NULL)
		return -1;

	arr2 -> head.next = &arr2 -> head;
	arr2 -> head.last = &arr2 -> head;
	arr2 -> head.data = NULL;
	arr2 -> size = size;
	arr2 -> nmemb = 0;
	*arr = arr2;

	return 0;
}

int bothlist_add(head_list *arr, int way, void *data)
{
	_list *newdata;
	newdata = malloc(sizeof(_list));

	if(newdata == NULL)
		return -1;

	newdata -> data = malloc(sizeof(arr -> size));

	if(newdata -> data == NULL)
		return -1;

	memcpy(newdata -> data , data, arr -> size);

	if(way == TAIL)
	{
		newdata->last = arr->head.last;
		newdata->next = &arr->head;
		arr->head.last->next = newdata;
		arr->head.last = newdata;
	}
	else if(way == HEAD)
	{
		newdata->next = arr->head.next;
		newdata->last = &arr->head;
		arr->head.next->last = newdata;
		arr->head.next = newdata;
	}
	return 0;
}
void bothlist_traval(head_list *arr, show_t show)
{
	_list *p = arr->head.next;

	for(;p->data != NULL; p = p->next)
		show(p->data);
}
void bothlist_del(head_list *arr, void *data, cmp_t cmp)
{
	_list *p = bothlist_find(arr, data, cmp);	
	
	if(p != NULL)
	{
		p->next->last = p->last;
		p->last->next = p->next;
		free(p->data);
		free(p);
	}
}

_list *bothlist_find(head_list *arr, void *data, cmp_t cmp)
{
	_list *p = arr->head.next;
	for(;p->data != NULL && cmp(p->data, data); p = p->next);
	if(p->data == NULL)
		return NULL;
	return p;
}

void *bothlist_fetch(head_list *arr, void *data, cmp_t cmp)
{
	_list *p = bothlist_find(arr, data, cmp);
	void *s = malloc(arr->size);	
	
	if(p != NULL)
	{
		p->next->last = p->last;
		p->last->next = p->next;
		s = p->data;
		free(p);
	}
	return s;
}
int bothlist_empty(head_list *arr)
{
	return arr->head.next == arr->head.last && arr->head.next == &arr->head;
}
static int del(_list *arr)
{
	arr->next->last = arr->last;
	arr->last->next = arr->next;

	free(arr->data);
	free(arr);
}
void free_headlist(head_list *arr)
{
	struct list *n;
	
	if(!bothlist_empty(arr))
	{
		for (n = (arr->head.next)->next; ; n = n->next) 
		{
			del(n->last);
			if(n == &arr->head);
			break;
		}
	}
	free(arr);
}

