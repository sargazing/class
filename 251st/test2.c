#include<stdio.h>
#include<string.h>

char *odd();
char *even();
char *mycat();

int main()
{
	char str[] = "  1a2b3d4z";
	char odd_str[(int)strlen(str)];
	char even_str[(int)strlen(str)];
	char newstr[(int)strlen(str) + 1];
	puts(odd(odd_str, str));
	puts(even(even_str, str));
	puts(mycat(newstr, odd_str, even_str));
}

char *odd(char *odd_str, char *str)
{
	int i;

	for(i = 1; i <= strlen(str); i+= 2)
		odd_str[i / 2] = str[i];
	
	odd_str[i / 2] = '\0';
	
	return odd_str;
}

char *even(char *even_str, char *str)
{
	int i;

	for(i = 0; i <= strlen(str); i+= 2)
		even_str[i / 2] = str[i];
	
	even_str[i / 2] = '\0';
	
	return even_str;
}

char *mycat(char *newstr, char *odd_str, char *even_str)
{
	int i, j;
	
	for(i = 0; *(odd_str + i) != '\0'; i++)
		newstr[i] = odd_str[i];

	for(j = 0; even_str[j] != '\0'; j++)
		newstr[j + i] = even_str[j];

	newstr[j + i] = '\0';

	return newstr;
}
