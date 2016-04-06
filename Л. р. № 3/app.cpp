#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void mySignalHandler(int signum)
{
	if (signum == SIGSEGV)
		printf("Check signal: SIGFPE\n");
	exit(0);
}


int main()
{
	signal(SIGSEGV, &mySignalHandler);
	float* d = 0;
	d[10] = 1;
	return 0;
}
