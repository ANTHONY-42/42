#include "so_long.h"

void	increment_tiles(char c, t_map *map)
{
	if (c == 'C')
		map->C++;
	else if (c == 'E')
		map->E++;
	else if (c == 'P')
		map->P++; 
}

void	check_tiles(t_map *map)
{
	if (map->C < 1)
		error();
	else if (map->E != 1)
		error();
	else if (map->P != 1)
		error();
}

void	check_line(char *line, int ref_size, int border, t_map *map)
{
	int	x;
	int	size;

	size = ft_strlen(line);
	if (size != ref_size)
		error();

	x = 0;
	while (line[x])
	{
		if (border && line[x] != '1')
			error();
		else if (line[0] != '1' || line [x_size] != '1')
			error();
		else if (i > 0 && i < size)
		{
			if (!(line[i] == '0' || line[i] == '1' 
				   || line[i] == 'C' || line[i] == 'E' || line[i] 'P'))
				error();
			else
				increment_tiles(line[i], map);
		}
		i++;
	}
}


void	check_map(char **tab, t_map *map)
{
	int	x;
	int	y;
	int	ref_line;
	int	ref_tab;
	int	border;

	y = 0;
	x = 0;
	ref_line = ft_strlen(tab[y]);
	ref_tab = ft_strlen_tab(tab);
	if (ref_tab < 3)
		error();
	while (tab[y])
	{
		border = 0;
		if (y == 0 || y == ref_tab)
			border++;
		check_line(tab[y], ref_line, border, map);
		y++;
	}
	check_tiles(map);
}
