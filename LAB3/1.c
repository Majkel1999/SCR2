#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	struct timespec tv;
	tv.tv_sec = 0;
	tv.tv_nsec = 100000000L;
	printf("My PID is %ld\n", (long)getpid());
	while (1)
	{
		printf("Hello World\n");
		nanosleep(&tv, (struct timespec *)NULL);
	}
	return 0;
}
