#include<stdio.h>

int main()
{
	int j = 0;

	while(j < 4)
	{
		printf("请输入第%d个学生的成绩:",++j);


		int num;

		//	printf("请输入一个成绩：");

		scanf("%d", &num);

		if(num < 0 || num > 100)
		{	
			printf("error\n");

			continue;
		}
		int i = num / 10;

		switch(i)
		{	
			case 10:

			case  9:
				printf("A\n");
				break;

			case 8:
				printf("B\n");
				break;

			case 7:
				printf("C\n");
				break;

			case 6:
				printf("D\n");
				break;

			default:
				printf("E\n");
				break;
		}

		return 0;
	}
	/*	else if(num >= 90)
		printf("A\n");

		else if(num > 79)
		printf("B\n");

		else if(num > 69)
		printf("C\n");

		else if(num > 59)
		printf("D\n");

		else 
		printf("E\n");
	 */	
}
