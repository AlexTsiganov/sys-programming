#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

const int DEVIDE_BY_ZERO = 1;

int main()
{
	try {
		throw DEVIDE_BY_ZERO;
		printf("Doesn't print\n");
	}
	catch(int e) {
		if (e == DEVIDE_BY_ZERO)
			printf("Catch exception: Devide by zero\n");
		else
			printf("Catch exception: %d\n", e); 
	}
	return 0;
}
