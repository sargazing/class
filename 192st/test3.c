#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *maxmin(char **str, int n);

int main(int argc, char **argv)
{
	char *arr;
	arr = maxmin(argv, argc);
	puts(arr);
}

char *maxmin(char **str, int n)
{
	int i = 0;
	char *arr;

	arr = malloc(strlen(str[i]) + 1);
	strcpy(arr, str[i]);
	
	for(;i < n; i++)
	{
		if(strlen(str[i]) < strlen(arr))
		{
			arr = malloc(strlen(str[i]) + 1);
			strcpy(arr, str[i]);
		}
	}
	return arr;
}
