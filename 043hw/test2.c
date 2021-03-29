/*
1	2^sizeof(int) * 8- 1
	2^sizeof(char) *8
2	0
	0
	0/1
	0/1
3	3	7
	段错误 6
4	16	30
	8	8
5
6	a=11
__________________________________________
3	101-02= 11
4 	if(c <= 122 && c >= 97)
		c -= 32;
5 	
	hello world

_________________________________________
1
void mycpy(char *a, char *b)
{
	int i = 0;
	for(i; b[i] != '\0'; i++)
		a[i] = b[i];
	a[i] = b[i];
}
*/
//2 
#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	struct list *next;
	struct list *last;
	void *data;
}_list;

typedef struct{
	_list head;
	int size;
	int nmemb;
}head_list;

typedef int (*cmp_t)(void *data1, void *data2);

enum{HEAD, TAIL};

int list_init(head_list **arr, int size)
{
	head_list *brr = malloc(sizeof(head_list));

	if(*arr == NULL)
		return -1;

	brr->head.data = malloc(size);

	if(brr->head.data == NULL)
		return -1;

	brr->head.next = brr->head.last = &(brr->head);
	brr->head.data = NULL;
	brr->size = size;
	brr->nmemb = 0;

	*arr = brr;
}

static void myadd(_list *arr, _list *newdata, _list *brr)
{
	newdata->next = arr->next;
	newdata->last = brr->last;
	brr->last = newdata;
	arr->next = newdata;
}
void list_add(head_list *arr, void *data, int way)
{
	_list *newdata = malloc(sizeof(_list));
	if(newdata ==NULL)
		return;

	 newdata->data = data;

	 if(way == HEAD)
		 myadd(&arr->head, newdata, arr->head.next);

	 if(way == TAIL)
		 myadd(arr->head.next, newdata, &arr->head);
}
static void mydel(_list *arr)
{
	arr->next->last = arr->last;
	arr->last->next - arr->next;
	free(arr->data);
	free(arr);
}	

void list_del(head_list *arr, void *data, cmp_t cmp)
{
	_list *p = arr->head.next;
	for(p; p != &arr->head; p = p->next)
	{
		if(!cmp(p->data, data))
			mydel(p);
	}
}
int list_traval(head_list *arr)
{
	int i = 1;
	_list *p = arr->head.next;
	for(;p != &arr->head; p = p->next, i++);
	return i;
}
int cmpint(void *data1, void *data2)
{
	int *a = data1;
	int *b = data2;

	return *a - *b;
}
int main()
{
	head_list *arr;

}
