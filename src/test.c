#include <stddef.h>
#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	printf(" sec = %lu\n", now.tv_sec);
	printf("usec = %lu\n", now.tv_usec);
}
