#include "so_long.h"

char	**ft_tabcpy(char **tab)
{
	int	i;
	int	len;
	char	**dst;

	i = 0;
	len = ft_strlen_tab(tab);
	dst = malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = ft_strdup(tab[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

void	find_P(char **mapcopy, int *player_y, int *player_x)
{
	int	x;
	int	y;

	y = 0;
	while (mapcopy[y])
	{
		x = 0;
		while (mapcopy[y][x])
		{
			if (mapcopy[y][x] == 'P')
			{
				*player_y = y;
				*player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood(t_map *map, char	**mapcopy, int P_y, int P_x)
{
	if (P_x < 0 || P_x >= map->size_x 
			|| P_y < 0 || P_y >= map->size_y 
			|| mapcopy[P_y][P_x] == '1'
			|| mapcopy[P_y][P_x] == 'F')
		return ;
	
	mapcopy[P_y][P_x] = 'F';
	flood(map, mapcopy, P_y + 1, P_x);
	flood(map, mapcopy, P_y - 1, P_x);
	flood(map, mapcopy, P_y, P_x + 1);
	flood(map, mapcopy, P_y, P_x - 1);
}

void	check_access(char **mapcopy, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while(map->tab[y])
	{
		x = 0;
		while (map->tab[y][x])
		{
			if ((map->tab[y][x] == 'C' || map->tab[y][x] == 'E')
					&& mapcopy[y][x] != 'F')
				error();
			x++;
		}
		y++;
	}
}

void	flood_fill(t_map *map)
{
	int	P_y;
	int	P_x;
	char 	**mapcopy;

	mapcopy = ft_tabcpy(map->tab);
	if (!mapcopy)
		error ();

	find_P(mapcopy, &P_y, &P_x);
	flood(map, mapcopy, P_y, P_x);
	check_access(mapcopy, map);
}
