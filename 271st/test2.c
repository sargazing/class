#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *new_str();

int main()
{
	char str[] = "AbCdEfDfSvGh";

	char *str_2 = new_str(str);

	puts(str_2);

	free(str_2);

	str_2 = NULL;
	
	return 0;
}

char *new_str(char *str_1)
{
	char *str_2 = calloc(strlen(str_1) + 1, 1);
	int i = 0, j = 0;

	for(i; str_1[i] != '\0'; i++)
	{
		if(str_1[i] <= 'z' && str_1[i] >= 'a')
		{
			str_2[j] = str_1[i];

			j++;
		}
		
	}
	if (j != i)
		return realloc(str_2, j + 1);

	return str_2;
}
