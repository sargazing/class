#include<stdio.h>

#define SIZE 32

struct stu_animal{
	char colour[SIZE];
	char name[SIZE];
	int age;
};

int findmax(struct stu_animal *p, int num);

int main()
{
	struct stu_animal arr[3];
	struct stu_animal *p = arr;

	for(int j = 0; j < 3; j++)
	{
		arr[j].age = j + 22;
		snprintf(arr[j].colour, SIZE, "hello%d", j + 1);
		snprintf(arr[j].name, SIZE, "hello%d", j + 2);
	}

	int k = findmax(arr, 3);

	for(int i = 0; i < 3 ; i++)
		printf("%s, %s, %d\n", (p + i) -> colour, (p + i) -> name, (p + i) -> age);

	printf("maxage:");
	printf("%s, %s, %d\n", (p + k) -> colour, (p + k) -> name, (p + k) -> age);

	return 0;
}
int findmax(struct stu_animal *p, int num)
{
	int k = 0;

	for(int i = 0; i < num; i++)
	{
		if((p + k) -> age < (p + i) -> age)
			k = i;
	}
	return k;
}
