#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#define SWAP(a, b) char c = a; a = b; b = c;

static ssize_t myGetline(char **str, size_t	*size, FILE *buf);
int main(int argc, char **argv)
{
	if(argc < 2)
		return 1;
	
	FILE *fp = fopen(argv[1], "r");
	char *str = NULL;
	size_t num = 10;
	if(fp == NULL)
	{
		perror("fopen()");
		return 1;
	}

	while(1)
	{
		if(myGetline(&str, &num, fp) == EOF)
		{
			if(feof(fp))
				break;
			printf("error\n");
			return 1;
		}
		printf("%s", str);
	}

	return 0;
}

static ssize_t myGetline(char **str, size_t *size, FILE *buf)
{
	ssize_t i, data;

	*str = calloc(1, 1);

	for(i = 1; i < *size; i++)
	{
		data = fgetc(buf);	

		if(data == EOF)
		{
			return -1;
		}

		*str = realloc(*str, i + 1);
		
		(*str)[i] = data;

		SWAP((*str)[i], (*str)[i - 1]);

		if(data == '\n')
			break;
		}
	return i;
}
