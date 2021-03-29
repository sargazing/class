#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
/*	int *arr = malloc(12);

	memset(arr, 3, 1);

	for(int i = 0; i < 4; i++)
	printf("%d ", *arr);
	printf("%ld \n", sizeof(arr));
*/	
	int arr2[] = {1, 2, 3};

	printf("%ld ", sizeof(arr2));

	memset(arr2, '1', 8);

	for(int i = 0; i < 3; i++)
	printf("%d ", *(arr2 + i));
}
