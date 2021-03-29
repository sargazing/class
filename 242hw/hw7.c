//2
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CUBE(a) (a) * (a) * (a)
int funca(int l, int w, int h)
{
	return l * w * h;
}
int funcb(int l, int w, int h)
{
	return 2 * (l * h + h * w + l * w);
}
int sumnum(int num);
void mysort(int *data_arr, int size);
void findnum()
{
	for(int i = 100; i < 1000; i++)
		if(i == sumnum(i))
			printf("%5d", i);
}
int sumnum(int num)
{
	if(num < 10)
		return CUBE(num);
	return CUBE(num % 10) + sumnum(num / 10);
}

int main()
{
	int L, W, H;
	int arr[] = {45, 25, 58, 15, 69, 25, 25, 1 };
	printf("长,宽,高：");
	scanf("%d,%d,%d", &L, &W, &H);

	printf("%d	%d\n", funca(L, W, H), funcb(L, W, H));

	findnum();
	printf("\n");

	mysort(arr, sizeof(arr) / sizeof(int));
	for(int j = 0; j < sizeof(arr) / sizeof(int); j++)
		printf("%3d", arr[j]);
	printf("\n");
}
void mysort(int *data_arr, int size)
{
	int k = *data_arr;
	int min = 0;
	int max = size - 1;

	if(size <= 1)
		return;

	while(1)
	{
		while(data_arr[max] > k && min < max)
			max--;
		
		if(min < max)
		{
			data_arr[min] = data_arr[max];
			data_arr[max] = k;
			min ++;
		}
		else
			break;
		while(data_arr[min] < k && min < max)
			min++;
		if(min < max)
		{
			data_arr[max] = data_arr[min];
			data_arr[min] = k;
			max--;
		}
		else
			break;
	}
	mysort(data_arr, min);
	mysort(data_arr + min + 1, size - min - 1);
}


