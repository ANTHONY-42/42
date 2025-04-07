/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:06:49 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/07 16:33:11 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_tiles(t_game *game)
{
	if (game->c < 1)
		error(game, "!game->C < 1\n");
	else if (game->e != 1)
		error(game, "!game->E != 1\n");
	else if (game->p != 1)
		error(game, "!game->P != 1\n");
}

void	increment_tiles(char c, t_game *game)
{
	if (c == 'C')
		game->c++;
	else if (c == 'E')
		game->e++;
	else if (c == 'P')
		game->p++;
}

void	check_line(t_game *game, char *line, int border)
{
	int	x;
	int	size;

	size = ft_strlen(line);
	if (size != game->size_x)
		error(game, "!size line\n");
	if (line[0] != '1' || line[size - 2] != '1')
		error(game, "border vertical\n");
	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (border && (line[x] != '1'))
			error(game, "border horizontal\n");
		else if (!(line[x] == '0' || line[x] == '1'))
		{
			if (line[x] == 'C' || line[x] == 'E' || line[x] == 'P')
				increment_tiles(line[x], game);
			else
				error(game, "map[y][x] != 01CEP\n");
		}
		x++;
	}
}

void	check_map(t_game *game, char **tab)
{
	int	y;
	int	border;

	y = 0;
	if (game->size_y < 3)
		error(game, "map < 3\n");
	while (tab[y])
	{
		border = 0;
		if (y == 0 || y == (game->size_y) - 1)
			border++;
		check_line(game, tab[y], border);
		y++;
	}
	check_tiles(game);
	flood_fill(game);
}
