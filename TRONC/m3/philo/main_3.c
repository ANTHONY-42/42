#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <pthread.h>
#define	NB_PHILO	10

pthread_mutex_t	forks[NB_PHILO];
pthread_mutex_t	print_mutex;

long long       get_time_ms(void)
{
        struct  timeval tv;
        gettimeofday(&tv, NULL);
        return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void    print_msg(int id, const char *msg)
{
        pthread_mutex_lock(&print_mutex);
        printf("[%lld ms] Philosophe %d %s\n", get_time_ms() - g_start_time, id + 1, msg);
        pthread_mutex_unlock(&print_mutex);
}


void	*philosopher_routine(void *arg)
{
	int	id = *(int *)arg;
	int	left = id;
	int	right = (id + 1) % NB_PHILO;
	int	i = 0;

	while (i < 5)
	{
		print_msg(id, "réfléchit");
		usleep(100000);

		pthread_mutex_lock(&forks[left]);
		print_msg(id, "a pris la fourchette gauche");
		pthread_mutex_lock(&forks[right]);
		print_msg(id, "a pris la fourchette droite");

		print_msg(id, "mange");
		usleep(100000);

		pthread_mutex_unlock(&forks[right]);
		pthread_mutex_unlock(&forks[left]);

		print_msg(id, "dort");
		usleep(100000);

		i++;
	}
	return (NULL);
}

int	main()
{
	pthread_t	philo[NB_PHILO];
	int	ids[NB_PHILO];
	int	i;

	pthread_mutex_init(&print_mutex, NULL);

	i = 0;
	while (i < NB_PHILO)
	{
		ids[i] = i;
		pthread_mutex_init(&forks[i], NULL);
		pthread_create(&philo[i], NULL, philosopher_routine, &ids[i]);
		i++;
	}

	i = 0;
	while (i < NB_PHILO)
	{
		pthread_join(philo[i], NULL);
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&print_mutex);

	return 0;	
}
