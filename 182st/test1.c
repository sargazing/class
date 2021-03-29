#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *mysort(void *arr, int member, int size, int (*cmp)(const void *a, const void *b));
static int cmpint(const void *a, const void *b);
static int cmpchar(void *a, void *b);
static int cmpstr(void *a, void *b);

int main()
{
//	printf("%d\n", __LINE__);

	int arr[] = {17, 6, 3, 37, 15, 57, 10, 7, 67};
//	printf("%d\n", __LINE__);
	for(int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++)
		printf("%4d", arr[j]);
	printf("\n");
	mysort(arr, sizeof(arr)/ sizeof(arr[0]), sizeof(int), cmpint);
//	printf("%d\n", __LINE__);

	for(int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++)
		printf("%4d", arr[j]);
	printf("\n");

	return 0;
}

static int cmpint(const void *aa, const void *bb)
{
	const int *a = aa;
	const int *b = bb;
	return *a - *b;
}

static int cmpchar(void *aa, void *bb)
{
	char *a = aa;
	char *b = bb;
	return *a - *b;
}
static int cmpstr(void *aa, void *bb)
{
	char **a = aa;
	char **b = bb;
	return strcmp(*a, *b);
}
void *mysort(void *arr, int member, int size, int (*cmp)(const void *a, const void *b))
{
	if(member <= 1)
		return 0;
//	printf("%d\n", __LINE__);
printf("%d %d\n", member, size);
	int low, high;
	char *k = malloc(size);
//		printf("%d\n", __LINE__);

	low = 0;
	high = member - 1;
//	printf("%d\n", __LINE__);
	memcpy(k, (char*)arr + low * size, size);
//	printf("%d\n", __LINE__);
//	static int j;
	printf("K : %d\n", *k);
	int i = 1;
	while(high > low)
	{//j ++;
//		printf("%d\n", i);
		while(cmp((char*)arr + high * size, k) >= 0 && high > low)
		{
			//printf("%d\n", cmp((char *)arr + high * size, k)) ;
//			printf("%4d\n", *((char*)arr + high * size));
			high--;
		}
		printf("high: %d\n", high);
	for(int j = 0; j < member; j++)
		printf("%4d", *((char*)arr + j * size));
	printf("\n");
		if(low < high)
		{
			memcpy((char*)arr + low * size, (char*)arr + high * size, size);
			memcpy((char*)arr + high * size, k, size);
			low++;
		}
	for(int j = 0; j < member; j++)
		printf("%4d", *((char*)arr) + j * size);
	printf("\n");
	break;
		while(cmp(k, (char*)arr + low) >= 0 && high > low)
			low++;
		if(low < high)
		{
			memcpy((char*)arr + high * size, (char*)arr + low * size, size);
			memcpy((char*)arr + low * size, k, size);
			high--;
		}
	}
//	for(int j = 0; j < member; j++)
//		printf("%4d", *((char*)arr) + j * size);
//	printf("\n");
//	static int i;
//	i++;
//	printf("%d\n", i);
	mysort(arr, high, size, cmp);
	mysort(arr + high * size + size, member - high - 1, size, cmp);

	return arr;

}
