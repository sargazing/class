//成绩分类
#include<stdio.h>

#define TEN 10
#define ONE 1
#define ZERO 0
#define ELE 11

int display();

int main()
{
	int arr[TEN], count[ELE];
	int num;

	for(int i = ZERO; i < ELE; i++)
		count[i] = 0;

	for(int i = ZERO; i < TEN; i++)
	{	
		LOOP:
			printf("请输入第%d个学生的成绩：", i + ONE);
	
			scanf("%d", &arr[i]);
		
			if(arr[i] < 0 || arr[i] > 100)
			{
				printf("仅支持百分制成绩\n");

				goto LOOP;
			}
		
		switch(arr[i] / 10)
		{
			case 10: count[10]++; break;
			case 9 : count[9]++; break;
			case 8 : count[8]++; break;
			case 7 : count[7]++; break;
			case 6 : count[6]++; break;
			case 5 : count[5]++; break;
			case 4 : count[4]++; break;
			case 3 : count[3]++; break;
			case 2 : count[2]++; break;
			case 1 : count[1]++; break;
			case 0 : count[0]++; break;
		}
	}
	printf("100: ");
	
	display(count[TEN]);
	
	printf("\n");

	for(int j = TEN; j > ZERO; j--)
	{	
		printf("%d0~%d9:", j - ONE, j - ONE);
		
		display(count[j]);
		
		printf("\n");
	}
	return 0;
}

int display(int a)
{
	for(int i = a; i > ZERO; i--)
		printf("* ");
}
