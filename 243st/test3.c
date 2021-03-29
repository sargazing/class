#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *arr = malloc(12);

	strcpy(arr, "hello world");

	char *buf = arr;

	printf("%p\n", arr);
	char *str = strtok(arr, " ");
	puts(arr);
	puts(str);
	printf("%p\n", arr);

//	free(buf);
//	puts(arr - 12);
//	if(arr == NULL)
//		puts(buf);
}
