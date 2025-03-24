/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:11:44 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/20 17:31:42 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(int fd, t_stack *map)
{
	int	i;
	char	*line;
	t_map	*map;

	i = 0;
	map->tab = malloc(sizeof(t_map));
	line = get_next_line(fd);
	if (!line)
		error();
	while (line)
	{
		map->tab[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
			return (map);
}
void	parsing(int ac, char **av, t_map *map)
{
	if (!(ac == 2))
		error();
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error();
	
	map = malloc(sizeof(t_map));
	if (!map)
		error();
	fd = open(av[1], O_RDONLY);
	if (!fd < 0)
		error();
	map->tab = load_map(fd, map);
	check_map(map->tab);
	return (map);
}
