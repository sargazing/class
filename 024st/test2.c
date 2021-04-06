#include<stdio.h>
#include<stdlib.h>

char *my(char *dest, const char *src)
{
	char *save = dest;

	int i = 0;
	while(*dest++ = *src++)
		printf("%d\n", i++);
	return save;
}
int main()
{
	const char arr[6] = "world";

	char *arr2 = malloc(6);

	int a = 1, b = 2;

	 ++b+--a;

	arr2 = my(arr2, arr);
	puts(arr2);

}
