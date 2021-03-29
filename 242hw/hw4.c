//32
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void myinsert(char *s, char *t, int i);

int main()
{
	char s[] = "hello";
	char t[] = "would";

	myinsert(s, t, 4);

	puts(s);

}
void myinsert(char *s, char *t, int i)
{
	char *str;
	
	str = calloc(sizeof(s) / sizeof(*s) , sizeof(char));

	memcpy(str, s + i, strlen(s + i) + 1);	
	memcpy(s + i, t, strlen(t) * sizeof(char));
	memcpy(s + i + strlen(t), str, strlen(str) + 1);

	free(str);
	str = NULL;
}
