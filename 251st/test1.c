#include<stdio.h>

char *mydel();

int main()
{
	char str[] = "     asddfvawefadsv   ";

	puts(mydel(str));
	
	printf("\n");

	return 0;
}

char *mydel( char *str)
{
	int i = 0, j = 0;

	while(1)
	{
		if(str[i] != ' ')
			break;
		i++;
	}
	while(1)
	{
		str[j] = str[j + i];

		if(str[j + i] == ' ')
			break;
		j++;
	}
	str[j] = '\0';
	return str;
}
