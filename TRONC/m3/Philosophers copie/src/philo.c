#include "philo.h"

void    *philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data	*data = philo->data;

	while (!data->stop)
	{
		print_msg(data, philo->id, "réfléchit");
		usleep(100 * 1000);

		pthread_mutex_lock(philo->fork_left);
		print_msg(data, philo->id, "a pris la fourchette gauche");
		pthread_mutex_lock(philo->fork_right);
		print_msg(data, philo->id, "a pris la fourchette droite");

		print_msg(data, philo->id, "mange");
		philo->last_meal = get_time_ms();
		usleep(data->config.TIME_TO_EAT * 1000);
		if (data->config.MUST_EAT)
			philo->nb_meal++;

		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);

		print_msg(data, philo->id, "dort");
		usleep(data->config.TIME_TO_SLEEP * 1000);

		if (data->config.MUST_EAT != -1 && philo->nb_meal >= data->config.MUST_EAT)
			break;
	}
	return (NULL);
}
