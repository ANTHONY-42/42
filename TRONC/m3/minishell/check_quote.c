#include "minishell.h"

void	check_two_double_quote(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == '"')
			q++;
		i++;
	}
	if (q % 2 != 0)
		return (1);
	return (0)
}

void	check_two_single_quote(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == ''')
			q++;
		i++;
	}
	if (q % 2 != 0)
		return (1);
	return (0)
}
