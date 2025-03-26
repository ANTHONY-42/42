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

t_map	*load_map(int fd)
{
	int	i;
	char	*line;
	t_map	*map;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		error();
	line = get_next_line(fd);
	if (!line)
		error();
	map->tab = malloc(sizeof(char *) * 1024);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		map->tab[i] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	map->tab[i] = NULL;
			return (map);
}
t_map	*parsing(int ac, char **av)
{
	t_map	*map;
	int	fd;

	if (!(ac == 2))
		error();
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error();
	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error();
	map = load_map(fd);
	close(fd);
	verif_map(map->tab, map);
	return (map);
}
