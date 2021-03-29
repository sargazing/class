#include<stdio.h>
#include<unistd.h>
#include<getopt.h>

int main(int argc, char **argv)
{
	if(argc < 2)
		return 1;
	
	struct option str[] = 
	{
		{"HELLO", no_argument, NULL, 'H'},
		{"hello", required_argument, NULL, 'h'},
		{"world", optional_argument, NULL, 'w'},
		{0,0,0,0}
	};

	int flag;
	int num;

	while(1)
	{
		flag = getopt_long(argc, argv, "-ag:", str, &num);

		if(flag == -1)
			break;

		switch(flag)
		{
			case 'a': printf("a\n");break;
			case 'g': 
				if(optarg == NULL)
					printf("g error\n");
				else
					puts(optarg);
				break;
			case 'H': printf("%s\n", str[num].name);break;
			case 'h': printf("%s\n", str[num].name);
					  if(optarg != NULL)
						  printf("%s\n", optarg);
					  else(printf("no argument\n"));
					  break;
			case 'w': printf("%s\n", str[num].name);
					  if(optarg !=NULL)
						  puts(optarg);
					  break;
			case 1: if(optarg != NULL) printf("%s\n", optarg);break;
			default :printf("?\n");break;
		}
	}


	return 0;
}
