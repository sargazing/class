#include<stdio.h>
#include<queue.h>

int main()
{
	queue_t *arr;

	queue_init(&arr, sizeof(int), 5);

	int i, j, k;

	for(i = 0; i < 6; i++)
	{
		enqueue(arr, &i);
	}
	for(j = 0, k; j < 6; j++)
	{
		dequeue(arr, &k);

		printf("%d\n", k);
	}
//	queue_des(arr);
	for(int i = 10; i < 16; i++)
	{
		enqueue(arr, &i);
	}
	for(int j = 0, k; j < 6; j++)
	{
		dequeue(arr, &k);

		printf("%d\n", k);
	}
	queue_des(arr);


	return 0;
}
