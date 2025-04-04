#include "so_long.h"

// void	free_full()
// {
// 	if (!game)
// 		free(game);
// }

void    error(char *str)
{
        ft_putstr("Error\n");
	ft_putstr(str);
        exit(1);
}
int	close_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (0);
}