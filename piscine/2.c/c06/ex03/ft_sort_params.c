/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:21:00 by anturtsc          #+#    #+#             */
/*   Updated: 2024/10/07 15:06:55 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	sort_param(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	j = 1;
	while (j < argc - 1)
	{
		i = 1;
		while (i < argc - j)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	sort_param(argc, argv);
	while (i <= argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			j++;
		}
		write(1, argv[i], j);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
