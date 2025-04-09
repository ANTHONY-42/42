/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:11:44 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/08 17:42:39 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_value(t_game *game)
{
	game->mapcopy = NULL;
	game->size_y = ft_strlen_tab(game->map);
	game->size_x = ft_strlen(game->map[1]);
	game->p_y = 0;
	game->p_x = 0;
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->moves = 0;
	game->c_collected = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->img_player_h = NULL;
	game->img_player_b = NULL;
	game->img_player_g = NULL;
	game->img_player_d = NULL;
	game->img_player = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
}

int	count_line(t_game *game, char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	 	parsing_error(game, "!fd\n");
	line = get_next_line(fd);
	if (!line)
	 	parsing_error(game, "!line\n");
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	load_map(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	game->map = malloc(sizeof(char *) * (count_line(game, file) + 1));
	if (!game->map)
		parsing_error(game, "!malloc map\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	 	parsing_error(game, "!fd\n");
	line = get_next_line(fd);
	while (line)
	{
		game->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

t_game	*parsing(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	 	parsing_error(game, "!game\n");
	if (ac != 2)
	 	parsing_error(game, "!ac == 2\n");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	 	parsing_error(game, "!.ber\n");
	load_map(av[1], game);
	if (!game->map)
		parsing_error(game, "load_map\n");	
	init_value(game);
	check_map(game, game->map);
	return (game);
}
