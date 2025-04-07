#include "so_long.h"

void	free_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			free(&map[y][x]);
			x++;
		}
		y++;
	}
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
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

int	close_game(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		//free(game->win);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		//free(game->mlx);
	}
	return (0);
}

void	free_all(t_game *game)
{
	free_map(game->map);
	free_map(game->mapcopy);
	free_img(game);
	close_game(game);
        exit(1);
}

void    error(t_game *game, char *str)
{
        ft_printf("Error\n");
	ft_printf("%s", str);
	free_all(game);
}

// une fonction pr free les images
// une fonction pr free la map
// fonction pr free fenetre et pointeur mlx
