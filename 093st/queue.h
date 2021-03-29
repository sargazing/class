#ifndef __LIST
#define __LIST

enum{ENQ, DEQ};

typedef struct{
	void *data;
	int tail;
	int front;
	int size;
	int cap;
	int key;
}queue_t;

int queue_init(queue_t **arr, int size, int cap);

int queue_full(queue_t *arr);

int queue_empty(queue_t *arr);

int enqueue(queue_t *arr, void *data);

int dequeue(queue_t *arr, void *data);

int queue_des(queue_t *arr);

#endif
