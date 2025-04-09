/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:12:55 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/08 17:31:58 by anturtsc         ###   ########.fr       */
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

void	find_player(t_game *game, int *player_y, int *player_x)
{
	int	x;
	int	y;

	y = 0;
	while (game->mapcopy[y])
	{
		x = 0;
		while (game->mapcopy[y][x])
		{
			if (game->mapcopy[y][x] == 'P')
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

void	flood(t_game *game, int p_y, int p_x)
{
	if (p_x < 0 || p_x >= game->size_x
		|| p_y < 0 || p_y >= game->size_y
		|| game->mapcopy[p_y][p_x] == '1'
		|| game->mapcopy[p_y][p_x] == 'F')
		return ;
	else if (game->mapcopy[p_y][p_x] == 'E')
	{
		game->mapcopy[p_y][p_x] = 'F';
		return ;
	}
	game->mapcopy[p_y][p_x] = 'F';
	flood(game, p_y + 1, p_x);
	flood(game, p_y - 1, p_x);
	flood(game, p_y, p_x + 1);
	flood(game, p_y, p_x - 1);
}

void	check_access(t_game *game)
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
					&& game->mapcopy[y][x] != 'F')
				error(game, "!flood fill\n");
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game)
{
	int		p_y;
	int		p_x;

	game->mapcopy = ft_tabcpy(game->map);
	if (!game->mapcopy)
		error (game, "!mapcopy\n");
	find_player(game, &p_y, &p_x);
	flood(game, p_y, p_x);
	check_access(game);
	game->p_y = p_y;
	game->p_x = p_x;
}
