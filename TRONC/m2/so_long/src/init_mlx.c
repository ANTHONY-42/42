#include "so_long.h"

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_windows(game->mlx, game->win, img, x * TILE, y * TILE);
}

void	render_map(t_map *game)
{
	int	y;
	int	x;
	char 	c;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			c = game->tab[y][x];
			if (c == '0')
				draw_tile(game, game->img_floor, x, y);
			else if (c == '1')\
				draw_tile(game, game->img_wall, x, y);
			else if (c == 'P')
				draw_tile(game, game->img_player_d, x, y);
			else if (c == 'C')
				draw_tile(game. game->img_collectible, x, y);
			else if (c == 'E')
				draw_tile(game. game->img_exit, x, y);
			x++;
		}
		y++;
	}
}
void	init_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_player_h = mlx_xmp_file_to_image(game->mlx, "textures/player_h.xpm", &w, &h);
	game->img_player_b = mlx_xmp_file_to_image(game->mlx, "textures/player_b.xpm", &w, &h);
	game->img_player_g = mlx_xmp_file_to_image(game->mlx, "textures/player_g.xpm", &w, &h);
	game->img_player_d = mlx_xmp_file_to_image(game->mlx, "textures/player_d.xpm", &w, &h);
	game->img_floor = mlx_xmp_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	game->img_wall = mlx_xmp_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->img_collectible = mlx_xmp_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
	game->img_exit = mlx_xmp_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("!mlx_init\n");
	game->win = mlx_new_window(game->mlx, 400, 300, "Fentre MLX");
	if (!game->win)
		error("!mlx_new_windows");
	init_textures(game);
	render_map(game);
	mlx_loop(game->mlx);
}
