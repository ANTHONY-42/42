/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:11:44 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/27 12:32:15 by anturtsc         ###   ########.fr       */
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
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	load_map(char *file, t_map *map)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;

	map->tab = malloc(sizeof(char *) * (count_line(file) + 1));
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		map->tab[i++] = ft_strdup(line);
		free(line);
	}
	map->tab[i] = NULL;
	map->y_end = ft_strlen_tab(map->tab);
	map->x_end = ft_strlen(map->tab[0]);
	close(fd);
}

void	parsing(t_map *map, int ac, char **av)
{
	if (!(ac == 2))
		error();
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error();

	load_map(av[1], map);
	if (!map->tab)
		error();

	check_map(map, map->tab);
}
