//求当月天数 ，求输入日期在当年是第几天

#include<stdio.h>

int main(void)
{
	int year, month, day, days, i = 0;

	printf("请输入年月（年，月，日）:");

	scanf("%d,%d,%d", &year, &month, &day);

	if(month > 13 && month < 0)
	{
		printf("error\n");

		return 1;
	}
	int sumday = day;

	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		i = 1;
	for(int j = 1; j < month; j++)
	{
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			days = 31;
		
		else if(month == 4 || month == 6 || month == 9 || month == 11)
			days = 30;
		
		else 
			days = 28 + i;
		if(day > days || day < 1)
		{
			printf("日期格式不正确\n");

			return 1;				
		}
		sumday += days;	
	}
		printf("%d年%d月有%d天,%d日为本年的第%d天\n", year, month, days, day, sumday);
}
