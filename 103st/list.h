#ifndef ——LIST
#define __LIST

typedef int cmp_t(void *a, void *b);

typedef struct list{
	struct list next;
	void *data;
}_list;
typedef struct{
	_list arr;
	int size;
	int nmemeb;
}head_list;

int list_init(head_list *arr, int size);

int list_add(head_list *arr, )








#endif
