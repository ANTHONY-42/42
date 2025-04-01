/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:11:44 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/01 19:59:46 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file)
{
	int	fd;
	int	count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if(fd < 0)
		error("!fd");
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	load_map(char *file, t_game *game)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;

	game->map = malloc(sizeof(char *) * (count_line(file) + 1));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("!fd\n");
	while ((line = get_next_line(fd)))
	{
		game->map[i++] = ft_strdup(line);
		free(line);
	}
	game->map[i] = NULL;
	close(fd);
	game->P = 0;
	game->C = 0;
	game->E = 0;
	game->size_y = ft_strlen_tab(game->map);
	game->size_x = ft_strlen(game->map[0]);
}

void	parsing(t_game *game, int ac, char **av)
{
	if (!(ac == 2))
		error("!ac == 2\n");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error("!.ber\n");

	load_map(av[1], game);
	if (!game->map)
		error("!map->tab\n");

	check_map(game, game->map);
}
