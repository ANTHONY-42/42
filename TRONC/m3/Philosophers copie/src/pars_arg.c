#include "philo.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error("arg %d is not int\n", i);
		i++;
	}
	return (0);
}

void	verif_min_max(long arg, int i, int min, int max)
{
	if (arg < min)
		error("arg[%d] is to small\n", i);
	if (arg > max)
		error("arg[%d] is to big\n", i);
}

void	init_config(int ac, char **av, t_data *data)
{
	data.config.NB_PHILO = ft_atoi(av[1]);
	data.config.TIME_TO_DIE = ft_atoi(av[2]);
	data.config.TIME_TO_EAT = ft_atoi(av[3]);
	data.config.TIME_TO_SLEEP = ft_atoi(av[4]);
	if (ac == 6)
		data.config.MUST_EAT = ft_atoi(av[5]);
	else
		data.config.MUST_EAT = -1;
}

void	pars_arg(int ac, char **av, t_data *data)
{
	int	min;
	int	max;
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		error("Error : nbr arg incorret(%d)\n", ac);

	while (i != ac)
	{
		is_digit(av[i]);
		min = 60;
		max = INT_MAX;
		if (i == 1)
		{
			min = 1;
			max = 200;
		}
		verif_min_max(ft_atoi(av[i]), i, min, max);
		i++;
	}
	init_config(ac, av, &data);
}
