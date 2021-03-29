#include<stdio.h>
#include<string.h>

void *mysorting(int *arr);

int main()
{	
	int arr2[] = {1, 2, 3};
	void *arr;
	arr = arr2;
	mysorting(arr2);	
	printf("%ld\n", sizeof(arr) / sizeof(typeof(arr[0])));	

	for(int i = 0; i < sizeof(arr) / sizeof(typeof (*arr)); i++)
		printf("%d\n",*((char *)arr + i));
//*/
}

void *mysorting(int *arr)
{
	size_t size = sizeof(arr) / sizeof(typeof(*arr));
	int i, j, num;

	printf("%ld\n", sizeof(arr) / sizeof(typeof(arr[0])));	
	if(sizeof(*arr) == 1)
		size--;

//	j = arr[i];
	for(i = 2; i < size; i++)
	{	
		num  = arr[i];
		for(j = i - 1; j >= 0; j--)
		{
			if(num < arr[j])
			{
				num = arr[j];
				arr[j] = arr[j - 1];
			}
			arr[0] = num;
		}
	}
}
