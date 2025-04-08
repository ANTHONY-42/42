/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:04:29 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:55 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	free_img(t_game *game)
{
	if (game->img_player_h)
		mlx_destroy_image(game->mlx, game->img_player_h);
	if (game->img_player_b)
		mlx_destroy_image(game->mlx, game->img_player_b);
	if (game->img_player_g)
		mlx_destroy_image(game->mlx, game->img_player_g);
	if (game->img_player_d)
		mlx_destroy_image(game->mlx, game->img_player_d);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

int	free_all(t_game *game)
{
	free_img(game);
	if (game->map)
		free_map(game->map);
	if (game->mapcopy)
		free_map(game->mapcopy);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{		
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	return (0);
}

void	error(t_game *game, char *str)
{
	ft_printf("Error\n");
	ft_printf("%s", str);
	free_all(game);
	exit (1);
}
