#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	pars_arg(ac, av, &data);
	if (init_data(&data))
		return (1);
	init_philo(&data);
	start_thread(&data);
	destroy_all(&data);
	return (0);
}
