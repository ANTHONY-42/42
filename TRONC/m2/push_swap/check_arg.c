#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

int	is_double(char **tab, int nbr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_atoi(tab[j]) == nbr)
			return (1);
		j++;
	}
	return (0);
}

int	check_number(char **tab, char *arg, int i)
{
	if (!is_number(arg))
		return (0);
	else if (!is_int(arg))
		return (0);
	else if (is_double(tab, ft_atoi(arg), i))
		return (0);
	return (1);
}

void	check_arg(char **tab, int split)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (check_number(tab, tab[i], i))
			i++;
		else
		{
			if (split)
				error(NULL, NULL, tab);
			else
				error(NULL, NULL, NULL);
		}
	}
}
