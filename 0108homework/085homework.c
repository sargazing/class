//   5 x 100元纸币换算
#include<stdio.h>

int main(void)
{
	int rmb50, rmb20, rmb10, rmb5, max = 0, min = 100, j = 0;

	printf("50元 20元 10元 5元 总计\n");

	for(rmb50 = 1; rmb50 <= 500 / 50 ; rmb50++)
		for(rmb20 = 1; rmb20 <= 500 / 20; rmb20++)
			for(rmb10 = 1; rmb10 <=  500 / 10; rmb10++)
				for(rmb5 = 1; rmb5 <= 500 / 5; rmb5++)
				{
					if(rmb50 * 50 + rmb20 * 20 + rmb10 * 10 +rmb5 * 5 == 500)
					{
						printf("%5d%5d%5d%5d%5d\n", rmb50, rmb20, rmb10, rmb5, rmb50 + rmb20 + rmb10 + rmb5);
	
						if(max < rmb50 + rmb20 + rmb10 + rmb5)
							max = rmb50 + rmb20 + rmb10 + rmb5;

						else if(min > rmb50 + rmb20 + rmb10 + rmb5)
							min = rmb50 + rmb20 + rmb10 + rmb5;
						
						j++;
					}
				}
	printf("共%d种换法，最多换%d张，最少换%d张\n",j, max, min);
}
