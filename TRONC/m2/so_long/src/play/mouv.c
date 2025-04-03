#include "so_long.h"

void	exit_game(t_game *game)
{
	if (game)
	{
		// Libère la mémoire, ferme la fenêtre, etc.
		// Exemple :
		mlx_destroy_window(game->mlx, game->win);
		// (tu peux aussi free les textures si besoin)
	}
	exit(0);
}

void	change_sprite(t_game *game, int y, int x)
{
	if (y == -1)
		game->img_player = game->img_player_h;
	else if (y == 1)
		game->img_player = game->img_player_b;
	else if (x == -1)
		game->img_player = game->img_player_g;
	else if (x == 1)
		game->img_player = game->img_player_d;
}

void	new_player(t_game *game, int new_y, int new_x)
{
	game->P_y = new_y;
	game->P_x = new_x;
	game->moves++;
	game->map[new_y][new_x] = 'P'; // place le joueur à la nouvelle position
	render_map(game);
}


void	move_player(t_game *game, int y, int x)
{
	int	new_y;
	int	new_x;
	char	next_tile;

	new_y = game->P_y + y;
	new_x = game->P_x + x;
	next_tile = game->map[new_y][new_x];
	change_sprite(game, y, x);
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
	{
		game->C_collected++;
		game->map[new_y][new_x] = '0';
	}
	if (next_tile == 'E')
	{
		if (game->C == game->C_collected)
			exit_game(game);
		else
			return ;
	}
	game->map[game->P_y][game->P_x] = '0'; // vide l’ancienne position
	new_player(game, new_y, new_x);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(game);
	else if (keycode == 13 || keycode == 126)
		move_player(game, -1, 0);
	else if (keycode == 1 || keycode == 125)
		move_player(game, 1, 0);
	else if (keycode == 0 || keycode == 123)
		move_player(game, 0, -1);
	else if (keycode == 2 || keycode == 124)
		move_player(game, 0, 1);
	return (0);
}
