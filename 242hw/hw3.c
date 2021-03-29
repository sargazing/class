#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mycmp(const char *str1, const char *str2);

int main()
{
	char *arr = "hello";
	char *arr2 = "hello";
	char *arr3 = "helll";
	char *arr4 = "helloworld";

	printf("%d\n", mycmp(arr, arr3));
	printf("%d\n", mycmp(arr3, arr));
	printf("%d\n", mycmp(arr, arr2));
	printf("%d\n", mycmp(arr4, arr));
	
	return 0;
}

int mycmp(const char *str1, const char *str2)
{
	int i;
	for(i = 0; str1[i] == str2[i] && str1[i] != '\0'; i++);
	
	if(str1[i] > str2[i])
		return 1;
	if(str2[i] > str1[i])
		return -1;
	return 0;
}
