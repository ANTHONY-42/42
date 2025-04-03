/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:07:36 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/01 19:54:28 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE 64

void	draw_tile(t_game *game, void *img, int x, int y)
{
	if (!img)
	{
		fprintf(stderr, "Error: Null pointer in draw_tile\n");
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

void	render_map(t_game *game)
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
				draw_tile(game, game->img_floor, x, y);
			else if (c == '1')
				draw_tile(game, game->img_wall, x, y);
			else if (c == 'P')
				draw_tile(game, game->img_player, x, y);
			else if (c == 'C')
				draw_tile(game, game->img_collectible, x, y);
			else if (c == 'E')
				draw_tile(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
}

void init_textures(t_game *game)
{
	int w, h;

	game->img_player_h = mlx_xpm_file_to_image(game->mlx, "src/texture/player_h.xpm", &w, &h);
	if (!game->img_player_h)
		error("Error loading player_h.xpm\n");
	game->img_player_b = mlx_xpm_file_to_image(game->mlx, "src/texture/player_b.xpm", &w, &h);
	if (!game->img_player_b)
		error("Error loading player_b.xpm\n");
	game->img_player_g = mlx_xpm_file_to_image(game->mlx, "src/texture/player_g.xpm", &w, &h);
	if (!game->img_player_g)
		error("Error loading player_g.xpm\n");
	game->img_player_d = mlx_xpm_file_to_image(game->mlx, "src/texture/player_d.xpm", &w, &h);
	if (!game->img_player_d)
		error("Error loading player_d.xpm\n");
	
	game->img_player = mlx_xpm_file_to_image(game->mlx, "src/texture/player_d.xpm", &w, &h);
	if (!game->img_player)
		error("Error loading player.xpm\n");
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "src/texture/floor.xpm", &w, &h);
	if (!game->img_floor)
		error("Error loading floor.xpm\n");
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "src/texture/wall.xpm", &w, &h);
	if (!game->img_wall)
		error("Error loading wall.xpm\n");
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "src/texture/collectible.xpm", &w, &h);
	if (!game->img_collectible)
		error("Error loading collectible.xpm\n");
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "src/texture/exit.xpm", &w, &h);
	if (!game->img_exit)
		error("Error loading exit.xpm\n");
}


void	start_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("!mlx_init\n");
	game->win = mlx_new_window(game->mlx, 1920, 1080, "OMAR LE DAUPHIN");
	if (!game->win)
		error("!mlx_new_windows\n");
	init_textures(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_loop(game->mlx);
}
