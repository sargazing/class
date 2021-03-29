#include<stdlib.h>
#include"queue.h"
#include<string.h>

int queue_init(queue_t **arr, int size, int cap)
{
	queue_t *p;

	p = malloc(sizeof(queue_t));
	if(p == NULL)
		return -1;
	
	p->data = calloc(cap, size);
	p->size = size;
	p->cap = cap;
	p->key = DEQ;
	p->front = p->tail = 0;

	*arr = p;
}

int queue_full(queue_t *arr)
{
	return arr->front == arr-> tail && arr->key == ENQ;	
}

int queue_empty(queue_t *arr)
{
	return arr->front == arr->tail && arr->key == DEQ;
}

int enqueue(queue_t *arr, void *data)
{
	if(queue_full(arr))
		return -1;

	memcpy((char *)arr->data + arr->size * arr->tail, data, arr->size);

	arr->tail = ++arr->tail % arr->cap;

	arr->key = ENQ;
	
	return 0;
}

int dequeue(queue_t *arr, void *data)
{
	if(queue_empty(arr))
		return -1;

	memcpy(data, (char *)arr->data + arr->size * arr->front, arr->size);

	arr->front = (arr->front + 1) % arr->cap;

	arr->key = DEQ;
}

int queue_des(queue_t *arr)
{
	free(arr->data);
	arr->data = NULL;
	free(arr);
	arr = NULL;
}
