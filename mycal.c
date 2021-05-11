#include <stdio.h>
#include <stdlib.h>

int isleap(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}

int ret_month_days(int month)
{
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	return days[month - 1];
}

int sum_all_days(int year, int month)
{
	int sum_days = 0;
	for(int i = 1970; i < year; i++)
	{
		sum_days += (365 + isleap(i)); 
	}
	for(int i = 1; i < month; i++)
	{
		sum_days +=	ret_month_days(i);
		if(i == 2)
			sum_days += isleap(year);
	}
	return sum_days;
}

void show_mycal(int year, int month)
{
	int sum_days = sum_all_days(year, month);

	int start = (sum_days + 4) % 7;

	int monthdays = ret_month_days(month) + isleap(year);

	int cnt = 0;

	printf("	%d月 %d	\n", month, year);
	printf("日 一 二 三 四 五 六\n");
	for(int i = 1; i <= monthdays ;i++)
	{
		if(start < 6 && start > 0)
		{
			for(; start > 0; start--)
			{
			printf("   ");
			cnt++;
			}
		}
		if(cnt == 7)
		{
			printf("\n");
			cnt = 0;
		}
		printf("%2d ", i);
		cnt ++;

	}
		printf("\n");
}

int main(int argc, char *argv[])
{
	show_mycal(atoi(argv[1]), atoi(argv[2]));

	return 0;
}

