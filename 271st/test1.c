#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *reversrSTring(const char *str);
int main()
{
	char str[] = "AbCd aBcD";

	char *str2 = reversrSTring(str);

	puts(str2);

	free(str2);

	str2 = NULL;

	return 0;
}


char *reversrSTring(const char *str)
{
	char *str2;

	str2 = calloc(strlen(str) + 1, sizeof(char));

	strcpy(str2, str);

	for(int i = 0; str2[i] != '\0'; i++)
	{
		if (str2[i] < 91 && str2[i] > 64)
			str2[i] += 32;
		else if (str2[i] < 123 && str2[i] > 96)
			str2[i] -= 32;
	}
	return str2;
}
