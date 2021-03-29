//排序数组
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

#define SWAP(num1,num2) \
	do{\
	typeof(num1) num3;\
	num3 = num1; num1 = num2; num2 = num3;\
	}while(0)
#define which(a, b) do{\
	if(a > b) a = b;\
   	else b = a;\
	a, b;\
	}while(0)	

int main()
{
	srand(getpid());
	
	int ssr = 10;
	int ur = 20;

	int sss = which (ssr, ur);
//	printf("%d", which(ssr, ur));

	int a[10];

	for(int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
		
//		for(int j = i; j > 0; j--)
//			if(a[j - 1] > a[j])
//				SWAP(a[j - 1], a[j]);
	}
	//
	/*
	for(int i = 9; i > 0; i--)
		for(int j = i - 1; j >= 0; j--)
			if(a[j] > a[i])
				SWAP(a[j], a[i]);
	*/
	//插入排序
	/*
	int t, j;
	for(int i = 1; i < 10; i++)
	{
		t = a[i];
		for(j = i - 1; j >= 0; j--)
		{
			if(a[j] > t)
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = t;	
	}
	*/
	//选择排序
	int max;
	for(int i = 0; i < 9; i++)
	{
		max = i;
		for(int j = i + 1; j < 10; j++)
		{
			max = a[max] < a[j]? max : j;
		}
		SWAP(a[max], a[i]);
	}

	for(int j = 0; j < 10; j++)
		printf("%5d", a[j]);

	printf("\n");

	return 0;

}

