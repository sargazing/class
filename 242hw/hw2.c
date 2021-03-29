//30
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *mycpy(char *str2, const char * str);

int main()
{
	const char *str = "hello world";

	char *str2;

	str2 = mycpy(str2, str);

	puts(str2);

	free(str2);

	str2 = NULL;

	return 0;
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
