#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int myatoi(const char *ptr)
{
	int data = 0;
	char tmp;
	for(int i = 0; *(ptr+i); i++)
	{
		if(*(ptr + i) < '0' || *(ptr + i) > '9')
			return -1;
		else
		{
		//	tmp = *(ptr + i);

			data = data * 10 + (*(ptr + i) - '0');
		}
	
	}
	return data;
}

void myitoa(int num, char *buf)
{
	int data = num;

	int i = 0;

	int j = 0;

	if(data < 0)
	{
		*buf = '-';
		j++;
		num = num * (-1);
		data = data * (-1);
	}
	for(; data ; data /= 10, i++);
	*(buf + i) = '\0';
	for(; i ; i--)
	{
		printf("%c\n", (char)(num % 10 + '0'));
		*(buf + i + j - 1) = (char)(num % 10 + '0');
		num /= 10;
	}
}

int mystrcmp(const char *arr, const char *brr)
{
	int i;
	for(i = 0; arr[i] != '\0' && arr[i] == brr[i]; i++);
	return arr[i] - brr[i];
}

union a_t
{
	int b;
	char c;
};
*/

char *save_arg(char *arg)
{
	int len = strlen(arg);

	char *p = malloc(len + 1);

	if(p == NULL)
		return NULL;

	char *buf = p;

	p[len] = '\0';

	while(len--)
	{
		*(p+len) = *arg++;
	}
	return buf;
}
int main(int argc, char *argv[])
{
	char buf[] = "asdf";

	const char  *p = buf;

	char *a = p;

//	*a = 'p';

/*	int num = atoi(argv[1]);
	char  buf[1024] = {0};
	int i = 0;

	for(; num ; i++, num /= 15)
	{
		buf[i] = num % 15 + '0';

		if(buf[i] > '9')
			buf[i] = buf[i] - '9' - 1 + 'A';
	}
	buf[i] = '\0';

	char *p = save_arg(buf);
*/
//	char s = 0xAA;
//	for(int i; i < 8; i++)
//		printf("%d\n", s & (0x1 << i));
//	char *p;
//	p = save_arg(argv[1]);
	printf("%s\n", p);
//	free(p);
//	p = NULL;
	return 0;
//	char arr[] = "helloadb";
//	char brr[] = "helload";
//	union a_t a;
//	a.b = 0x12345678;
//	printf("%d\n", mystrcmp(arr, brr));
//	printf("%d\n", strcmp(arr, brr));
//	printf("%#x\n", a.c);a
//	char *p = "a";
//	printf("%p\n", p);
//	printf("%d\n", myatoi(argv[1]));

//	char buf[1024];

//	myitoa(-32463, buf);

//	puts(buf);
//	printf("%d\n", !(0));
//	return 0;
}
