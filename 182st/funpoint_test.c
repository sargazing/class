#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortarr(void *arr, int nmemb, int size, int (*cmp)(const void *data1, const void *data2));

static int intcmp(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d2 - *d1;
}

static int charcmp(const void *data1, const void *data2)
{
	const char *c1 = data1;
	const char *c2 = data2;

	return *c1 - *c2;
}

static int stringcmp(const void *data1, const void *data2)
{
	char *const*d1 = data1;
	char *const*d2 = data2;

	return strcmp(*d2, *d1);
}

int main(void)
{
	int arr[] = {3,2,1,6,7};
	char str[] = "hello world";
	char *sarr[] = {"hello", "world", "hi", "good", "girls", "boys"};
/*
	sortarr(arr, sizeof(arr) / sizeof(*arr), sizeof(int), intcmp);
	sortarr(str, strlen(str), sizeof(char), charcmp);
2yy	sortarr(sarr, sizeof(sarr) / sizeof(*sarr), sizeof(char *), \
			stringcmp);

	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("%s\n", str);

	for (int i = 0; i < sizeof(sarr) / sizeof(*sarr); i++)
		printf("%s\n", sarr[i]);
*/
	sortarr(sarr, sizeof(sarr) / sizeof(*sarr), sizeof(char *), \
			stringcmp);
	return 0;
}

// 任意类型的数组排序
// (char *)arr + size*i
void sortarr(void *arr, int nmemb, int size, int (*cmp)(const void *data1, const void *data2)) 
{
	int i, j;
	char *tmp;
printf("%d\n", size);
	tmp = malloc(size);
	if (NULL == tmp)
		return;
	i = j = 0;
//	for (i = 0; i < nmemb-1; i++) {
//		for (j = 0; j < nmemb-i-1; j++) {
//			if (cmp((char *)arr+j*size, (char *)arr+(j+1)*size) < 0) {
				memcpy(tmp, (char *)arr+j*size, size);
			puts(tmp);	
				memcpy((char *)arr+j*size, (char *)arr+(j+1)*size, size);
				memcpy((char *)arr+(j+1)*size, tmp, size);
//			}
//		}
//	}
	free(tmp);
}


