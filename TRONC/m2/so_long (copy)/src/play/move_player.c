/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:29:46 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/08 18:56:49 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->p_y = new_y;
	game->p_x = new_x;
	game->moves++;
	game->map[new_y][new_x] = 'P';
	init_map(game);
	ft_printf("%d\n", game->moves);
}

void	move_player(t_game *game, int y, int x)
{
	int		new_y;
	int		new_x;
	char	next_tile;

	new_y = game->p_y + y;
	new_x = game->p_x + x;
	next_tile = game->map[new_y][new_x];
	change_sprite(game, y, x);
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		game->c_collected++;
	if (next_tile == 'E')
	{
		if (game->c == game->c_collected)
			mlx_loop_end(game->mlx);
		return ;
	}
	game->map[game->p_y][game->p_x] = '0';
	new_player(game, new_y, new_x);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		mlx_loop_end(game->mlx);
	else if (keycode == 126 || keycode == 65362 || keycode == 'w')
		move_player(game, -1, 0);
	else if (keycode == 125 || keycode == 65364 || keycode == 's')
		move_player(game, 1, 0);
	else if (keycode == 123 || keycode == 65361 || keycode == 'a')
		move_player(game, 0, -1);
	else if (keycode == 124 || keycode == 65363 || keycode == 'd')
		move_player(game, 0, 1);
	return (0);
}
