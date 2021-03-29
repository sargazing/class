#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **savestr(char **v);
int findmax(char **v);

int main()
{
	char **p;
	p = calloc(1, sizeof(char *));
		
	do
	{
		p = savestr(p);
	}
	while(savestr(p));

	printf("\n");

	for(int j = 0; p[j] != NULL; j++)
		puts(p[j]);
	
	printf("\n");
	
	puts(p[findmax(p)]);
	
	return 0;
}

char **savestr(char **v)
{
	int i = 0, j = 0;
	
	while(v[i] != NULL)
		i++;
	
	v = realloc(v, (i + 2) * sizeof(char *));
	v[i + 1] = NULL;
	v[i] = calloc(1, sizeof(char *));
	
	while(v[i][j - 1] != '\n')
	{	
		v[i] = realloc(v[i], (j + 1)* sizeof(char));
	
		scanf("%c", v[i] + j);
		
		j++;
	}
	v[i][j - 1] = '\0';
	
	if(*v[i] == 'e' && v[i][1] == 'x' && v[i][2] == 'i' && v[i][3] == 't')
	{
		v[i] = NULL;
		return 0;
	}
	return v;
}

int findmax(char **p)
{
	int k = 0;
	for(int j = 1; p[j] != NULL; j++)
	{
		if(strlen(p[j]) > strlen(p[j - 1]))
			k = j;
	}
	return k; 
}
