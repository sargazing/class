#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("hello ");

	fflush(NULL);

	printf("world ");

	write(1, "good ", 5);
	write(1, "morning ", 8);

	return 0;

}
