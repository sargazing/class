//3
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mysort(int *data_arr, int size);
char *str_func(const char *s, int c);
char *mycpy(char *str2, const char *str);

int main()
{
	int arr[] = {10, 2, 5, 12, 34 ,1 ,5 ,7 ,32};
	char str[] = "hello";
	char *str2 = calloc(2, sizeof(char));

	mysort(arr, 9);

	for(int i = 0; i < 9; i++)
		printf("%3d", arr[i]);
	printf("\n");

	str2 = str_func(str, 'l');
	if(*str2)
		puts(str2);

	str2 = mycpy(str2, str);
	puts(str2);
}

void mysort(int *data_arr, int size)
{
	int k = *data_arr;
	int min = 0;
	int max = size - 1;

	if(size <= 1)
		return;

	while(1)
	{
		while(data_arr[max] > k && min < max)
			max--;
		
		if(min < max)
		{
			data_arr[min] = data_arr[max];
			data_arr[max] = k;
			min ++;
		}
		else
			break;
		while(data_arr[min] < k && min < max)
			min++;
		if(min < max)
		{
			data_arr[max] = data_arr[min];
			data_arr[min] = k;
			max--;
		}
		else
			break;
	}
	mysort(data_arr, min);
	mysort(data_arr + min + 1, size - min - 1);
}

char *str_func(const char *s, int c)
{
	char *str = calloc(2, sizeof(char));

	for(int i = 0; s[i] != '\0'; i++)
	{
		if(c == s[i])
		{
			memcpy(str, s + i, sizeof(char));
			return str;
		}
	}
	return NULL;
}
char *mycpy(char *str2, const char *str)
{
	str2 = malloc(sizeof(str) * sizeof(char));
	int i;
	for(i = 0; str[i] != '\0'; i++)
	{
		str2[i] = str[i];
	}
	str2[i] = '\0';

	return str2;
}
