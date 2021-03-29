#include<stdio.h>

int main()
{
	int arr[5];

	for(int i = 0 ; i < 5; i++)
	{
		*(arr + i) = i;

		printf("%d\n", arr[i]);

		printf("%d\n", *(arr + i));

		printf("%ld\n", sizeof(arr) / sizeof *(arr + 1));
	
	}
}
