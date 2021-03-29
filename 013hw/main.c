#include<stdio.h>
#include"seqlist.h"
#include<stdlib.h>

typedef struct 
{
	char *name;

	int age;

	char *num;
}stu_t;
typedef struct{
	stu_t stude[2];

	int len;
}student_list;

static void show_int(void *arr)
{
	const int *d = arr;
	printf("%d\n", *d);

}	
static int mycmp(const void *a, const void *b)
{
	const int *aa = a;
	const int *bb = b;

	if(*aa == *bb)
	   return 1;
	return 0;	
}

int main(void)
{
	student_list student;
	
	student.stude[1].name = "aasd";
	student.stude[1].num = "15127632832";
	student.stude[1].age = 23;
	student.stude[0].name = "asd";
	student.stude[0].num = "1867632832";
	student.stude[0].age = 33;

	for(int j = 0; j < 2; j++)
	{
		puts(student.stude[j].name);
		puts(student.stude[j].num);
	}
	seqlist_t *seq;

	seq = seqlist_int(sizeof(stu_t));

	for(int i = 0; i < 6; i++)
		seqlist_add(seq, &i);

	seqlist_travel(seq, show_int);
	
	int a = 0;
	int b = 33;

	seq = seqlist_del(seq, &a, mycmp);

	seqlist_travel(seq, show_int);

	a++;
	seqlist_update(seq, &a, mycmp, &b);

	seqlist_travel(seq, show_int);

	return 0;
	return 0;
}
