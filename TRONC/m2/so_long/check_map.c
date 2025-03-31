#include "so_long.h"

void	check_tiles(t_map *map)
{
	if (map->C < 1)
		error();
	else if (map->E != 1)
		error();
	else if (map->P != 1)
		error();
}

void	increment_tiles(char c, t_map *map)
{
	if (c == 'C')
		map->C++;
	else if (c == 'E')
		map->E++;
	else if (c == 'P')
		map->P++; 
}

void	check_line(t_map *map, char *line, int border)
{
	int	x;
	int	size;

	size = ft_strlen(line); 
	if (size != map->size_x)
		error();
	if (line[0] != '1' || line[size - 2] != '1')
			error();

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (border && (line[x] != '1'))
			error();
		else if (!(line[x] == '0' || line[x] == '1'))
		{
			if (line[x] == 'C' || line[x] == 'E' || line[x] == 'P')
				increment_tiles(line[x], map);
			else
				error();
		}
		x++;
	}
}


void	check_map(t_map *map, char **tab)
{
	int	y;
	int	border;

	y = 0;
	if (map->size_y < 3)
		error();
	while (tab[y])
	{
		border = 0;
		if (y == 0 || y == (map->size_y - 1))
			border++;
		check_line(map, tab[y], border);
		y++;
	}
	check_tiles(map);
	flood_fill(map);
}

