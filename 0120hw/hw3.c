//模拟游戏
#include<stdio.h>

#define NUM  41
int main()
{
	int arr[NUM];
	int count = 0, humen = NUM, id = 0;

	for(int j = 0; j < NUM; j++)
		arr[j] = 1;

	while(humen)
	{
		id++;
		
		if(id == NUM + 1)
			id = 1;

		count += arr[id - 1];
		
		if(count == 3)
		{
			arr[id - 1] = count = 0;
			
			humen--;
		}
	}
	printf("最后留下第%d人\n", id);

	return 0;
}
