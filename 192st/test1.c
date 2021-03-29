/*
	malloc(size_t size）开辟size字节的连续存储空间，成功返回空间首地质，失败返回NULL，空间内数据未初始化。
	calloc(size_t nmember, size_t size)
	nmenmber成员数，size单成员所占字节，开辟nmember个size字节的存储空间，空间内数据初始化为0，成功返回空间首地质，失败返回NULL
	realloc(void *ptr , size_t size)开辟size字节存储空间，将ptr指向的数据复制到新空间，新空间比ptr空间小会丢失数据，，新空间比原空间大会填充未初始化，数据成功后释放ptr所占空间，返回新空间首地质，失败返回NULL
	free（void *ptr）释放ptr所指空间，ptr所指空间必须是上述方式开辟的空间
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **sep_str(const char *p, char ch);
int main(void)
{	
	const char a[]= {"hello    wolid    HELLO    worLD"};
	char **b;
	char ch = ' ';
	b = sep_str(a, ' ');
	for(int i = 0; *b[i] != '\0'; i ++)
	puts(b[i]);
}
char **sep_str(const char *p, char ch)
{
	char **str;
	int i = 0, sta, z = 0, size = 0;
	str = malloc(sizeof(char *));
	while(p[i] != '\0')
	{
		size = 0;
		sta = i;
		while(p[i] != ch && p[i] != '\0')
		{
			i++;
			size++;
		}
		str = realloc(str, sizeof(char *) * (z + 1));
		str[z] = calloc(size + 1, sizeof(char));
		strncpy(str[z], p + sta, size);
		z++;
		while(p[i] != '\0' && p[i] == ch)
			i++;
	}
		str = realloc(str, sizeof(char *) * (z + 1));
		str[z] = calloc(size + 1, sizeof(char));
		
	return str;
}
