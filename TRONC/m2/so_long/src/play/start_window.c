/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:07:36 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/07 16:51:04 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE 64

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

void	init_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->size_y)
	{
		x = 0;
		while (x < game->size_x)
		{
			if (game->map[y][x] == '0')
				put_img(game, game->img_floor, x, y);
			else if (game->map[y][x] == '1')
				put_img(game, game->img_wall, x, y);
			else if (game->map[y][x] == 'P')
				put_img(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				put_img(game, game->img_collect, x, y);
			else if (game->map[y][x] == 'E')
				put_img(game, game->img_exit, x, y);
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
			"src/texture/player_h.xpm", &w, &h);
	game->img_player_b = mlx_xpm_file_to_image(game->mlx,
			"src/texture/player_b.xpm", &w, &h);
	game->img_player_g = mlx_xpm_file_to_image(game->mlx,
			"src/texture/player_g.xpm", &w, &h);
	game->img_player_d = mlx_xpm_file_to_image(game->mlx,
			"src/texture/player_d.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"src/texture/player_d.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"src/texture/floor.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"src/texture/wall.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"src/texture/collect.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"src/texture/exit.xpm", &w, &h);
	if (!game->img_player || !game->img_player_h || !game->img_player_b
		|| !game->img_player_g || !game->img_player_d || !game->img_floor
		|| !game->img_wall || !game->img_collect || !game->img_exit)
		error(game, "!img_loading.xpm\n");
}

void	start_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "!mlx_init\n");
	game->win = mlx_new_window(game->mlx, ((TILE - 2) * game->size_x),
			(TILE * game->size_y), "OMAR LE DAUPHIN");
	if (!game->win)
		error(game, "!mlx_new_windows\n");
	init_textures(game);
	init_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
