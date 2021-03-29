#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int s)
{
	write(1, "!", 1);
	sleep(1);
	write(1, "!", 1);
}

int main()
{
	sigset_t mysig, oldsig;

	struct sigaction act;
	
	act.sa_handler = handler;
	act.sa_flags = 0;
	
//	signal(SIGINT, handler);

	sigemptyset(&act.sa_mask);

	sigaddset(&act.sa_mask, SIGINT);

	sigaction(SIGQUIT, &act, NULL);

//	sigprocmask(SIG_BLOCK, &mysig, &oldsig);
	for(int i = 0; i < 5; i++)
	{
//	sigprocmask(SIG_BLOCK, &mysig, &oldsig);
		for(int j = 0; j < 5; j++)
		{
			write(1, "~", 1);

			sleep(1);
		}
		write(1, "\n", 1);
//		sigsuspend(&oldsig);
	}

	return 0;
}

