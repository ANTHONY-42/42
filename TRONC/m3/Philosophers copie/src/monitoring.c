#include "philo.h"

void    *monitoring(void *arg)
{
	t_data	*data = (t_data *)arg;

	while (!data->stop)
	{
		int	i;
		int	all_finished;

		i = 0;
		all_finished = 1;
		while (i < data->config.NB_PHILOS)
		{
			long long now = get_time_ms();
			if (now - data->philo[i].last_meal > data->config.TIME_TO_DIE)
			{
				print_msg(data, data->philo[i].id, "est mort !");
				data->stop = 1;
				return (NULL);
			}

			if (data->config.MUST_EAT == -1 
					|| data->philo[i].nb_meal < data->config.MUST_EAT)
				all_finished = 0;
			i++;
		}
		if (all_finished && data->config.MUST_EAT != -1)
		{
			data->stop = 1;
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
