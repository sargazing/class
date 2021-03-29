#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

jmp_buf env;

int mydiv(int a, int b)
{
	if(b == 0)
		longjmp(env, 1);

	return a / b;
}

int main()
{


/*	int a, b;

	printf("%d %d\n", a, b);

	if(setjmp(env) == 0)
		printf("1:");
	else
		printf("2:");
	scanf("%d %d", &a, &b);

	printf("%d\n", mydiv(a, b));

	return 0;*/
}
