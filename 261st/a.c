#include<stdio.h>

int main()
{
	char str[] = "asd";
	int arr[] = {1, 2, 3, 9};
	char *s = str;
	int *a = arr;

	char *ss, sss[20];

	char *p = str;

	int c;
	char b;

	printf("%ld\n", sizeof(c));
	printf("%ld\n", sizeof(b));

	printf("%ld\n", sizeof(a));
	printf("%ld\n", sizeof(s));
	printf("%ld\n", sizeof(*a));
	printf("%ld\n", sizeof(*s));

	printf("%p\n", s);
	printf("%p\n", s + 1);
	printf("%p\n", a);
	printf("%p\n", a + 1);

	str[0] = ' ';

	printf("%d\n", *(a + 4));

	ss = sss;

//	gets(ss);

//	puts(ss);

	printf("%c\n", 'b' - 'a');
}
