/*6	ABCBCC
7	CDABC
8	Afgd
9	100, 8, 8, 8, 8
10	       12
11	3
12	434  239
13	4
14	8, 17
15	6
16	3600
17	hELLO!
18	xycdBCD
19	 1, -1, 1
	16
20	2	
21	7 4 
22	-4
23	4
24	6
25		6
		5
		5
		6
		5
		8
		16
		4		
		8
26	2 3
27	6
1	string[11]
2




























#include<stdio.h>

void aaa(char str[100])
{
	printf("%ld\n", sizeof(str));
}
int main()
{
	char arr[100];

	printf("%ld\n", sizeof(arr));

	aaa(arr);
}

