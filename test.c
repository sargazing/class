/*
1	D
2	B
3	A
4	D
5	B
6	D
7	C
8	D
9	
10	B
--------------------------
1	if(c - 'a' <= 36 || c - 'A' <= 36)
2	for(i = 1; i <= 101; i++)
3	if(a[i] % 2 == 0)
4	11, 13, 1859
5	*s = src + len -2
	while(len-- != 1)
 		*d++ = *s--;
	*d++ = '\0';
------------------------
1	static修饰全局变量限制其只能在本程序被调用；
	修饰局部变量，延长其声明周期；
2	四层；
	应用层；传输层； 网络层； 数据链路层；
3
4
5
-----------------------------
1	
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char *space_del(char *arr)
{
	int i = 0, j = 0;
	while(*(arr + i) != '\0')
	{
		for(i; *(arr + i) != ' ' && *(arr + i) != '\0'; i++);
		for(j = i; *(arr + j) == ' '; j++);
		strcpy(arr + i, arr + j);
	}
}
int main()
{
	char arr[]= "he  he";
	space_del(arr);
	puts(arr);
}
*/
