#include "philo.h"

int main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;
	int	i;

	pars_arg(ac, av, &data);

	data.fork = malloc(sizeof(pthread_mutex_t) * data.config.NB_PHILOS);
	data.philo = malloc(sizeof(t_philo) * data.config.NB_PHILOS);
	if (!data.fork || !data.philo)
		return (printf("Malloc failed\n"), 1);

	pthread_mutex_init(&data.print_mutex, NULL);
	data.start_time = get_time_ms();
	data.stop = 0;

	i = 0;
	while (i < data.config.NB_PHILOS)
	{
		pthread_mutex_init(&data.fork[i], NULL);

		data.philo[i].id = i;
		data.philo[i].nb_meal = 0;
		data.philo[i].last_meal = data.start_time;
		data.philo[i].fork_left = &data.fork[i];
		data.philo[i].fork_right = &data.fork[(i + 1) %  data.config.NB_PHILOS];
		data.philo[i].data = &data;

		pthread_create(&data.philo[i].thread_id, NULL, philosopher_routine, &data.philo[i]);
		i++;
	}

	pthread_create(&monitor, NULL, monitoring, &data);

	i = 0;
	while (i < data.config.NB_PHILOS)
	{
		pthread_join(data.philo[i].thread_id, NULL);
		pthread_mutex_destroy(&data.fork[i]);
		i++;
	}
	pthread_join(monitor, NULL);

	pthread_mutex_destroy(&data.print_mutex);
	free(data.fork);
	free(data.philo);

	return (0);
}
