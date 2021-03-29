#include<stdio.h>

int glob();
int glob2();

int main()
{
/*	int i, j;

	for(i = 1; i < 3; i ++)
		for(j = 1; j < 3; j++)
			printf("%d	%d\n", i, j);

	printf("\n");	

	//glob();
*/
	glob2();

}
	
int glob()
{
	for(int i = 1; i < 3; i ++)
		for(int j = 1; j < 3; j++)
			printf("%d	%d\n", i, j);
}

int glob2()
{
	static int i = 1, j = 1;

	for(i; i < 3; i ++)
	{
		int j = i;

		for(j ; j < 3; j++)
		{	
			printf("%d	%d\n", i, j);
		}	
//			if(i == 2)
//				break;
			
	}
	printf("%d %d\n", i, j);
}
