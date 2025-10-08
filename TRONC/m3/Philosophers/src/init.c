#include "philo.h"

int	init_data(t_data *data)
{
	data->fork = malloc(sizeof(pthread_mutex_t) * data->config.NB_PHILOS);
	data->philo = malloc(sizeof(t_philo) * data->config.NB_PHILOS);
	if (!data->fork || !data->philo)
		return (printf("Malloc failed\n"), 1);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->stop_lock, NULL);
	data->stop = 0;
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.NB_PHILOS)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_mutex_init(&data->philo[i].meal_lock, NULL);
		data->philo[i].id = i + 1;
		data->philo[i].nb_meal = 0;
		data->philo[i].fork_l = &data->fork[i];
		data->philo[i].fork_r = &data->fork[(i + 1) % data->config.NB_PHILOS];
		data->philo[i].data = data;
		//data->philo[i].last_meal = get_time_ms();
		i++;
	}
}

void	start_thread(t_data *data)
{
	pthread_t	monitor;
	int			i;

	data->start_time = get_time_ms();
	i = 0;
	while (i < data->config.NB_PHILOS)
	{
		pthread_create(&data->philo[i].thread_id, NULL,
			philosopher_routine, &data->philo[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitoring, data);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data->config.NB_PHILOS)
	{
		pthread_join(data->philo[i].thread_id, NULL);
		i++;
	}
}

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.NB_PHILOS)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&data->stop_lock);
	free(data->fork);
	free(data->philo);
}
