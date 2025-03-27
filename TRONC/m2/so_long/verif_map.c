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
	else
		v_flood_fill(map);
}

void	check_line(char *line, int ref_size, int border, t_map *map)
{
	int	x;
	int	size;

	size = ft_strlen(line);
	if (size != ref_size)
		error();

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (border && line[x] != '1')
			error();
		else if (!border && (line[0] != '1' || line[size - 2] != '1'))
			error();

		else if (!border && (x > 0 && x < size))
		{
			if (!(line[x] == '0' || line[x] == '1' 
				   || line[x] == 'C' || line[x] == 'E' || line[x] == 'P'))
				error();
			else
				increment_tiles(line[x], map);
		}
		x++;
	}
}


void	verif_map(char **tab, t_map *map)
{
	int	x;
	int	y;
	int	ref_line;
	int	ref_tab;
	int	border;

	y = 0;
	x = 0;
	ref_line = ft_strlen(tab[0]);
	ref_tab = ft_strlen_tab(tab);
	if (ref_tab < 3)
		error();
	while (tab[y])
	{
		border = 0;
		if (y == 0 || y == (ref_tab - 1))
			border++;
		check_line(tab[y], ref_line, border, map);
		y++;
	}
	check_tiles(map);
}
