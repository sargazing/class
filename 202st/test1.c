#include<stdio.h>

int sumstep(int num, int step);
int main()
{
	printf("%d\n", sumstep(10, 3));
	return 0;
}
int sumstep(int num, int step)
{
	if (step == 1)
		return 0;
	else if(num / step == 0)
		return 1;
//	for(int i = 0; i <= num / step; i++);
	
	return 1 + sumstep(num - step, step) + sumstep(num - step, step - 1);
}
