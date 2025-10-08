#include <stdio.h>
#include <sys/time.h>
#include <time.h>

long long get_time_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

int main(void)
{
	long long epoch_ms = get_time_ms();
	time_t epoch_sec = epoch_ms / 1000;

	// Affichage brut
	printf(" Millisecondes depuis Epoch : %lld ms\n", epoch_ms);
	printf(" Secondes depuis Epoch      : %ld s\n", epoch_sec);

	// Conversion en heure lisible
	struct tm *local = localtime(&epoch_sec);
	printf(" Date locale : %02d-%02d-%d %02d:%02d:%02d\n",
		local->tm_mday,
		local->tm_mon + 1,
		local->tm_year + 1900,
		local->tm_hour,
		local->tm_min,
		local->tm_sec
	);

	return 0;
}
