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

void	find_player(t_map *map, int *player_x, int *player_y)
{
	int	x;
	int	y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
			{
				*player_y = y;
				*ptlayer_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char	**mapcpy, int player_x, int player_y)
{
	if (player_x < 0 || player_x >= end 
			|| player_y > 0 || player_y >= end 
			|| mapcpy[player_x][player_y] == 'F')
		return ;
	mapcopy()
}

int	flood_fill(char **map)
{
	int	player_x;
	int	player_y;
	char 	**mapcopy;

	mapcopy = ft_tabcpy(map->tab);
	if (!mapcpy)
		return (0);

	find_pos(map, &player_x, &player_y);
	flood_fill(mapcopy, player_x, player_y);
}
