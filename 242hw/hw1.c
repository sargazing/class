/*

9	b, c, d : 10, 12, 120	
10	队列先进先出， 栈先进后出
11	c用宏
12	-3
13	p为指针指向5连续int类型变量的首地质地址； p为数组，成员有5个指针，各指向一个int型亮亮的地址；
	函数返回值为int * ； 函数为一个指针，返回一个int型变量
14	2， 1
15	
16
17
18	int a;
	int *a;
	int *a[];
	int a[10];
	int *a[10];
	int (*a)[10];
	int (*a)(int);
	int	*a[10](int);
19	
20	0

 */
#include<stdio.h>

int do_dup(int a[], int n);

int main()
{
	int b[4] = {1, 2, 1, 3}; 	
	printf("%d", do_dup(b, 4));
}

int do_dup(int a[], int n)
{
	int b;
	for(int i = 0; i < n; i++)
	{
		b = a[i];
		for(int j = i + 1; j < n; j++)
		{
			if(b == a[j])
			   return b;
		}
	}
}
