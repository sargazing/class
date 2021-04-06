#include<stdio.h>
#include<string.h>

int *test(int *arr, int size)
{
	int data;
	for(int i = 1; i < size; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(*(arr+j) > *(arr + j -1))
			{
				data = *(arr + j);
				*(arr + j) = *(arr + j - 1);
				*(arr + j -1) = data;
			}
		}
	}
	return arr;
}

int main()
{
	int arr[] = {1,4,6,8,2,9,3,6,9};

	int *brr = test(arr, sizeof(arr) / sizeof(int));

	for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%2d", brr[i]);
	}	
	char *str = "\ta\017bc";
   printf("%ld\n", strlen(str))	;
}
