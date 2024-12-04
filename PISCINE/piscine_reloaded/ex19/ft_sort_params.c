/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:47 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/08 19:44:48 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_swap(char **i, char **j)
{
	char	*tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc - 1)
	{
		k = 0;
		while (argv[i][k] && argv[i + 1][k])
		{
			if (argv[i][k] > argv[i + 1][k])
			{
				i = ft_swap(&argv[i], &argv[i + 1]);
			}
			else if (argv[i][k] < argv[i + 1][k])
				i++;
			k++;
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
}
