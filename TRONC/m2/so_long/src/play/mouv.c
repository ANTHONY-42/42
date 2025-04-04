/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:29:46 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/04 20:49:21 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	if (game)
		mlx_destroy_window(game->mlx, game->win);
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
	game->map[new_y][new_x] = 'P';
	init_map(game);
}

void	move_player(t_game *game, int y, int x)
{
	int		new_y;
	int		new_x;
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
	game->map[game->P_y][game->P_x] = '0';
	new_player(game, new_y, new_x);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		exit_game(game);
	else if (keycode == 13 || keycode == 126 || keycode == 65362)
		move_player(game, -1, 0);
	else if (keycode == 1 || keycode == 125 || keycode == 65364)
		move_player(game, 1, 0);
	else if (keycode == 0 || keycode == 123 || keycode == 65361)
		move_player(game, 0, -1);
	else if (keycode == 2 || keycode == 124 || keycode == 65363)
		move_player(game, 0, 1);
	return (0);
}
