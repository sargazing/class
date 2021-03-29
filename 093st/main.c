#include<stdio.h>
#include<queue.h>
#include<lstack.h>
#include<string.h>

int find(char key)
{
	char arr[] = "+-*/%";
	int i;
	for(i = 0; arr[i] != key; i++);
	return i;
}

int priority(char x, char y)
{				    //+ - * / %
	int arr[5][5] = {{1,0,1,1,1},	//+
					 {1,1,1,1,1},   //-
					 {0,0,0,0,0},	//*
					 {0,0,1,1,0},	///
					 {0,0,1,1,1},	//%
					};
	 return arr[find(x)][find(y)];

}

int main(int argc, char **argv)
{
	int i;
	queue_t *res;
	head_lstack *oper;

	queue_init(&res, sizeof(char), strlen(argv[1]));
	lstack_init(&oper, sizeof(char));

	for(i = 0; argv[1][i] != '\0'; i++)
	{
		if(argv[1][i] <= '9', argv[1][i] >= '0')
		{
			enqueue(res, *(argv + 1) + i);
			continue;
		}
		else if(!lstack_empty(oper) || argv[1][i] == '(')
		{
			lstack_push(oper, *(argv + 1) + i);
		}
		else if(argv[1][i] == ')')
		{
			char *data;
			while(*data != '(')
			{
				data = (char *)lstack_pop(oper, data);
				enqueue(res, data);
			}
			lstack_pop(oper, data);
		}
				
	}

}

