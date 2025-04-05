/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/05 16:21:21 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_tabcpy(char **tab)
{
	int		i;
	int		len;
	char	**dst;

	i = 0;
	len = ft_strlen_tab(tab);
	dst = malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = ft_strdup(tab[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

void	find_player(char **mapcopy, int *player_y, int *player_x)
{
	int	x;
	int	y;

	y = 0;
	while (mapcopy[y])
	{
		x = 0;
		while (mapcopy[y][x])
		{
			if (mapcopy[y][x] == 'P')
			{
				*player_y = y;
				*player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood(t_game *game, char **mapcopy, int p_y, int p_x)
{
	if (p_x < 0 || p_x >= game->size_x
		|| p_y < 0 || p_y >= game->size_y
		|| mapcopy[p_y][p_x] == '1'
		|| mapcopy[p_y][p_x] == 'F')
		return ;
	else if (mapcopy[p_y][p_x] == 'E')
	{
		mapcopy[p_y][p_x] = 'F';
		return ;
	}
	mapcopy[p_y][p_x] = 'F';
	flood(game, mapcopy, p_y + 1, p_x);
	flood(game, mapcopy, p_y - 1, p_x);
	flood(game, mapcopy, p_y, p_x + 1);
	flood(game, mapcopy, p_y, p_x - 1);
}

void	check_access(char **mapcopy, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ((game->map[y][x] == 'C' || game->map[y][x] == 'E')
					&& mapcopy[y][x] != 'F')
				error("!flood fill");
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game)
{
	int		p_y;
	int		p_x;
	char	**mapcopy;

	mapcopy = ft_tabcpy(game->map);
	if (!mapcopy)
		error ("!mapcopy");
	find_player(mapcopy, &p_y, &p_x);
	flood(game, mapcopy, p_y, p_x);
	check_access(mapcopy, game);
	game->P_y = p_y;
	game->P_x = p_x;
}
