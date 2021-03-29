#include<stdlib.h>
#include"lstack.h"
#include<stdio.h>

int main()
{
	head_lstack *arr;
	lstack_init(&arr, sizeof(int));

	for(int i = 0; i < 10; i ++) 
	{
		lstack_push(arr, &i);
	}
	for(int j = 0; j < 10 ; j++)
	{
		printf("%d\n", *(int *)lstack_pop(arr, &j));
	}
	lstack_des(arr);
}

