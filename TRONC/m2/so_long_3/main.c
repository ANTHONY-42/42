/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:20:15 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/20 13:42:24 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<stdio.h>
int	main(int ac, char **av)
{
	parsing(ac, av);
}
/*
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	if (parsing(av[1]))
		ft_putstr("Error\n");
	so_long(av[1]);
	return (0);
}*/
