#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*CMP)(const void *aa, const void *bb);

void *maxmin(void *arr, int member, int size, CMP cmp);
static int findmax_int(const void *aa, const void *bb);
static int findmax_char(const void *aa, const void *bb);
static int findmax_str(const void *aa, const void *bb);
static int findmin_int(const void *aa, const void *bb);
static int findmin_char(const void *aa, const void *bb);
static int findmin_str(const void *aa, const void *bb);

int main()
{
	int arr[] = {1, 2, 3, 5};
	char str[] = {"helloword"};
	char *arr2[] = {"hellow", "helloh", "xould"};
	
//	char *j;

	//j = malloc(sizeof(arr[0]));
	
	maxmin(arr2, sizeof(arr2) / sizeof(*arr2), sizeof(char *), findmax_str);

//	printf("%c\n", *(j + 1));
//	puts(arr2[0]);

	return 0;
}
static int findmax_int(const void *aa, const void *bb)
{
	const int *a = (int*)aa;
	const int *b = (int*)bb;
	return *a - *b;
}
static int findmax_char(const void *aa, const void *bb)
{
	const char *a = (char*)aa;
	const char *b = (char*)bb;
	return *a - *b;
}
static int findmax_str(const void *aa, const void *bb)
{
	 char *const*a = (char**)aa;
	 char *const*b = (char**)bb;
	 return strcmp(*a, *b);
}	
static int findmin_int(const void *aa, const void *bb)
{
	const int *a = (int*)aa;
	const int *b = (int*)bb;
	return *b - *a;
}
static int findmin_char(const void *aa, const void *bb)
{
	const char *a = (char*)aa;
	const char *b = (char*)bb;
	return *b - *a;
}
static int findmin_str(const void *aa, const void *bb)
{
	 char *const*a = (char**)aa;
	 char *const*b = (char**)bb;
	 return strcmp(*b, *a);
}	
void *maxmin(void *arr, int member, int size, CMP cmp)
{
	char *k;
printf("%d", size);

	k = malloc(size);

	memcpy(k, (char*)arr + size, size);
//	puts(k);

printf("%d\n", __LINE__);
	for(int i = 1; i < member; i++)
	{
//		puts((char *)arr + size * i);	
		if(cmp((char*)arr + size * i, (char *)arr) > 0)
		{
printf("%d\n", __LINE__);
			memcpy(k, (char *)arr + size * i, size);
	
			
printf("%d\n", __LINE__);
		} 
	}
}
