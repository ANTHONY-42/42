/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:56:59 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/08 17:44:29 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft_x/libft/libft.h"
# include "libft_x/ft_printf/ft_printf.h"
// # include "libft/libft.h"
// # include "libft_x/ft_printf/ft_printf.h"

// # define BUFFER_SIZE 42

typedef struct s_game
{
	char	**map;
	char	**mapcopy;
	int		size_y;
	int		size_x;
	int		p_y;
	int		p_x;
	int		p;
	int		c;
	int		e;
	int		moves;
	int		c_collected;
	void	*mlx;
	void	*win;
	void	*img_player_h;
	void	*img_player_b;
	void	*img_player_g;
	void	*img_player_d;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_exit;
}	t_game;

//		SO_LONG			//

//	PARSING
t_game	*parsing(int ac, char **av);
void	load_map(char *file, t_game *game);
int		count_line(t_game *game, char *file);
//	CHECK_MAP
void	check_map(t_game *game, char **tab);
void	check_line(t_game *game, char *line, int border);
void	check_tiles(t_game *game);
void	increment_tiles(char c, t_game *game);
//	FLOOD_FILL
void	flood_fill(t_game *game);
void	flood(t_game *game, int p_y, int p_x);
char	**ft_tabcpy(char **tab);
//	GET_NEXT_LINE
char	*get_next_line(int fd);
char	*extract_line(char **stored);

//	PLAY
//	START_WINDOW
void	start_window(t_game *game);
void	init_textures(t_game *game);
void	init_map(t_game *game);

//	MOVE
void	move_player(t_game *game, int y, int x);
int		handle_keypress(int keycode, t_game *game);
void	new_player(t_game *game, int new_y, int new_x);
void	change_sprite(t_game *game, int y, int x);
void	exit_game(t_game *game);

//	UTILS
void	error(t_game *game, char *str);
int		free_all(t_game *game);
int		close_game(t_game *game);
void	free_img(t_game *game);
void	free_map(char **map);
int		ft_strlen_tab(char **tab);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
void	ft_putstr(char *str);
int		close_game(t_game *game);
void	parsing_error(t_game *game, char *str);

#endif
