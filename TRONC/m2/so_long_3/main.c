/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:20:15 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/18 18:42:01 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<stdio.h>
int	main(int ac, char **av)
{
	printf("%d%s\n", ac, av[1]);
	// parsing(av[1]);
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
