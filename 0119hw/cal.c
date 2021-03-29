//判断日期是第几天
#include<stdio.h>

int isleap();
int monthdays();

int main(void)
{
	int year, month, day;
	printf("请输入年月（年，月, 日）:");

	scanf("%d,%d,%d", &year, &month, &day);
	if(day > monthdays(month, year) || day < 1)
	{
		printf("当月无此日期\n");

		return 0;
	}
	if(month < 13 && month > 0)
	{
		int sumday = day;

		for(int i = 1; i < month; i++)
			sumday += monthdays(i, year);
		
	printf("%d年%d月%d日为此年的第%d天\n", year, month, day, sumday);
	}
	else
		printf("输入月份格式错误\n");
}

int isleap(int year_s)
{
		if(year_s % 4 == 0 && year_s % 100 != 0 || year_s % 400 == 0)
			return 1;
		else
			return 0;
}
int monthdays(int month_s, int year)
{
		if(month_s == 1 || month_s == 3 || month_s == 5 || month_s == 7 || month_s == 8 || month_s == 10 || month_s == 12)
			return 31;
		else if(month_s == 4 || month_s == 6 || month_s == 9 || month_s == 11)
			return 30;
		else 
			return 28 + isleap(year);
}
