#include<stdio.h>
#include<string.h>

#define SIZE  32
struct stu_st{
	int age;
	char name[SIZE];
	float score;
};

int main()
{
	struct stu_st stu = {23, "emb", 100};
	struct stu_st stu2;
	struct stu_st stu3[3] = {{20, "aa", 100},{21, "bb", 60},{22, "cc", 59.5}};
	struct stu_st *p = stu3;

	for(int j = 0; j < 3; j++)
	{
		scanf("%d,%s,%f", &stu3[j].age, stu3[j].name, &stu3[j].score);

//		if(getchar() == '\n');

//		continue;
	}

/*	printf("%d, %s, %f\n", stu.age, stu.name, stu.score);

	stu2.age = 22;
	stu2.score = 90;
	strcpy(stu2.name, "hhhh");
*/
	for(int i = 0; i < 3 ; i++)
		printf("%d, %s, %f\n", (p + i) -> age, (p + i) -> name, (p + i) -> score);

	return 0;
}
