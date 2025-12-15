#include "philo.h"

void	thinking(t_philo *philo)
{
	t_data	*data;
	long	time;
	long 	y;
	long 	x;

	data = philo->data;
	print_msg(data, philo->id, "réfléchit");

	x = data->config.TIME_TO_EAT + data->config.TIME_TO_SLEEP;
	y = data->config.TIME_TO_DIE - x;
	time = y / 2;
	//if (y > 200)
	//	time = 200;
	precise_sleep(time, data);
}

void	take_fork(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_r);
		if (stopit_now(data))
			return (fork_unlock(philo));
		print_msg(data, philo->id, "a pris la fourchette droite");
		pthread_mutex_lock(philo->fork_l);
		if (stopit_now(data))
			return (fork_unlock(philo));
		print_msg(data, philo->id, "a pris la fourchette gauche");
	}
	else
	{
		pthread_mutex_lock(philo->fork_l);
		if (stopit_now(data))
			return (fork_unlock(philo));
		print_msg(data, philo->id, "a pris la fourchette gauche");
		if (data->config.NB_PHILOS == 1)
			return (fork_unlock(philo));
		pthread_mutex_lock(philo->fork_r);
		if (stopit_now(data))
			return (fork_unlock(philo));
		print_msg(data, philo->id, "a pris la fourchette droite");
	}
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;

	last_meal_lock(philo);
	print_msg(data, philo->id, "mange");
	precise_sleep(data->config.TIME_TO_EAT, data);
	
	fork_unlock(philo);
	if (data->config.MUST_EAT != -1)
		philo->nb_meal++;
}

void	sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_msg(data, philo->id, "dort");
	precise_sleep(data->config.TIME_TO_SLEEP, data);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	while (get_time_ms() < philo->data->start_time)
		precise_sleep(1, data);
	if (philo->id %2 == 0)
		precise_sleep(5, data);
	while (!stopit_now(data))
	{
		if (!stopit_now(data))
			thinking(philo);
		if (!stopit_now(data))
			take_fork(philo);
		if (data->config.NB_PHILOS == 1)
			return (NULL);
		if (!stopit_now(data))
			eating(philo);
		if (!stopit_now(data))
			sleeping(philo);
		if (stopit_now(data) || (data->config.MUST_EAT != -1
				&& philo->nb_meal >= data->config.MUST_EAT))
			break ;
	}
	return (NULL);
}
