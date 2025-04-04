/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:11:44 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/04 17:02:23 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tiles(t_game *game)
{
	game->P = 0;
	game->C = 0;
	game->E = 0;
	game->size_y = ft_strlen_tab(game->map);
	game->size_x = ft_strlen(game->map[0]);
}

int	count_line(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("!fd");
	line = get_next_line(fd);
	if (!line)
		error("!line");
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
	game->map = malloc(sizeof(char *) * (count_line(file) + 1));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("!fd\n");
	line = get_next_line(fd);
	while (line)
	{
		game->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	init_tiles(game);
}

void	parsing(t_game *game, int ac, char **av)
{
	if (!(ac == 2))
		error("!ac == 2\n");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error("!.ber\n");
	load_map(av[1], game);
	if (!game->map)
		error("load_map\n");
	check_map(game, game->map);
}
