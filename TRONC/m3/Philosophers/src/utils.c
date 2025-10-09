#include "philo.h"

void	precise_sleep(int sleep)
{
	long	start_time;
	long	past_time;

	start_time = get_time_ms();
	past_time = get_time_ms() - start_time;;
	while(past_time < sleep)
	{
		if (sleep - past_time > 10)
			usleep((sleep - past_time) * 100);
		else
			usleep(100);
		past_time = get_time_ms() - start_time;
	}
}

int	stopit_now(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->stop_lock);
	res = data->stop;
	pthread_mutex_unlock(&data->stop_lock);
	return (res);
}

long	ft_atoi(char *str)
{
	int	i = 0;
	int	nbr;
	long long	result = 0;

	while (str[i])
	{
		nbr = str[i] - '0';
		result = (result * 10) + nbr;
		i++;
	}
	return (result);
}

void	error(char *str, int i)
{
	printf(str, i);
	exit(1);
}

long long	get_time_ms(void)
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	print_msg(t_data *data, int id, const char *msg)
{
	long long	time;

	time = get_time_ms() - data->start_time;
	if (stopit_now(data))
		return;
	pthread_mutex_lock(&data->print_mutex);
	printf("[%lld ms] Philosophe %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}
