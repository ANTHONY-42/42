#include "philo.h"

int	death_loop(t_data *data)
{
	int	i;

	i = 0;
	data->all_finished = 1;
	while (i < data->config.NB_PHILOS)
	{
		pthread_mutex_lock(&data->philo[i].meal_lock);
		if (get_time_ms() - data->philo[i].last_meal > data->config.TIME_TO_DIE)
		{
			print_msg(data, data->philo[i].id, "est mort!");
			pthread_mutex_lock(&data->stop_lock);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_lock);
			//pthread_mutex_unlock(data->philo[i].fork_l);
			//pthread_mutex_unlock(data->philo[i].fork_r);
			pthread_mutex_unlock(&data->philo[i].meal_lock);
			return (1);
		}
		if (data->config.MUST_EAT == -1
				|| data->philo[i].nb_meal < data->config.MUST_EAT)
			data->all_finished = 0;
		pthread_mutex_unlock(&data->philo[i].meal_lock);
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!stopit_now(data))
	{
		if (death_loop(data))
			return (NULL);
		if (data->all_finished && data->config.MUST_EAT != -1)
		{
			data->stop = 1;
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
