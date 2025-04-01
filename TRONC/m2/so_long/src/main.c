/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:20:15 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/01 09:42:38 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error();
	parsing(map, ac, av);
	if (!map)
		error();
	free(map);
	return (0);
}
