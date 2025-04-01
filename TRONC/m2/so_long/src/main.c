/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:20:15 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/01 13:25:36 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	map = malloc(sizeof(t_map));
	game = malloc(sizeof(t_game));
	if (!map)
		error();
	parsing(map, ac, av);
	if (!map)
		error();
	init_mlx(game);	
	free(map);
	return (0);
}
