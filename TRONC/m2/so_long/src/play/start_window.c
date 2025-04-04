/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:07:36 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/04 20:51:25 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE 64

/*
void	draw_tile(t_game *game, void *img, int x, int y)
{
	if (!img)
	{
		fprintf(stderr, "Error: Null pointer in draw_tile\n");
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}*/

void	init_map(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->size_y)
	{
		x = 0;
		while (x < game->size_x)
		{
			c = game->map[y][x];
			if (c == '0')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_floor, x * TILE, y * TILE);
			else if (c == '1')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_wall, x * TILE, y * TILE);
			else if (c == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_player, x * TILE, y * TILE);
			else if (c == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_collect, x * TILE, y * TILE);
			else if (c == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
						game->img_exit, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}

void	init_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_player_h = mlx_xpm_file_to_image(game->mlx,
			"src/txt/player_h.xpm", &w, &h);
	game->img_player_b = mlx_xpm_file_to_image(game->mlx,
			"src/txt/player_b.xpm", &w, &h);
	game->img_player_g = mlx_xpm_file_to_image(game->mlx,
			"src/txt/player_g.xpm", &w, &h);
	game->img_player_d = mlx_xpm_file_to_image(game->mlx,
			"src/txt/player_d.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"src/txt/player_d.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"src/txt/floor.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"src/txt/wall.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"src/txt/collect.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"src/txt/exit.xpm", &w, &h);
	if (!game->img_player || !game->img_player_h || !game->img_player_b
			|| !game->img_player_g || !game->img_player_d || !game->img_floor
			|| !game->img_wall || !game->img_collect || !game->img_exit)
		error("!img_loading.xpm\n");
}

void	start_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("!mlx_init\n");
	game->win = mlx_new_window(game->mlx, ((TILE * game->size_x) - 1), (TILE * game->size_y), "OMAR LE DAUPHIN");
	if (!game->win)
		error("!mlx_new_windows\n");
	init_textures(game);
	init_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
