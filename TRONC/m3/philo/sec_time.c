#include <stdio.h>
#include <unistd.h>

int	main()
{
	int	hrs = 0;
	int	min = 0;
	int	sec = 0;
	int	ms = 0;

	while (1)
	{
		ms++;
		if (ms == 1000)
		{
			ms = 0;
			sec++;
			if (sec == 60)
			{
				sec = 0;
				min++;
				if (min == 60)
				{
					min = 0;
					hrs++;
				}
			}
		}
		printf("\r%02dh:%02dm:%02ds:%02d",hrs, min, sec, ms);
		fflush(stdout);
		usleep(1000);
	}
}
