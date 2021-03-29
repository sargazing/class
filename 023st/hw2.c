#include<stdio.h>
#include"bothlist.h"

void showint(void *data)
{
	int *a = data;

	printf("%d\n", *a);
}
int cmpint( void *a,  void *b)
{
	 int *aa = a;
	 int *bb = b;
	
	return *aa - *bb;
}

int main()
{
	head_list *arr;

	bothlist_init(sizeof(int), &arr);

	if(!bothlist_empty(arr))
		printf("空\n");

	for(int i = 0, j  = 9; i < 5; i++, j--)
	{
		bothlist_add(arr, TAIL, &i);
		bothlist_add(arr, HEAD, &j);
	}
	int k = 10;
	bothlist_del(arr, &k, cmpint);
	
	k--;
	int *s = (int *)bothlist_fetch(arr, &k, cmpint);

	printf("s: %d\n", *s);

	bothlist_traval(arr, showint);
	
	if(bothlist_empty(arr))
		printf("非空\n");

	free_headlist(arr);
}
