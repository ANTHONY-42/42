#include "so_long.h"

static char **create_map_copy(t_map *map)
{
    char **copy;
    int i;

    copy = malloc(sizeof(char *) * (map->height + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < map->height)
    {
        copy[i] = ft_strdup(map->map[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

static void find_player(t_map *map, int *player_x, int *player_y)
{
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->map[i][j] == 'P')
            {
                *player_x = j;
                *player_y = i;
                return;
            }
            j++;
        }
        i++;
    }
}

static void fill(char **map_copy, int player_x, int player_y, t_map *map)
{
    if (player_x < 0 || player_x >= map->width || player_y < 0 
	|| player_y >= map->height || map_copy[player_y][player_x] == '1' 
	|| map_copy[player_y][player_x] == 'F' 
	|| map_copy[player_y][player_x] == 'M')
	return ;
    map_copy[player_y][player_x] = 'F';
    fill(map_copy, player_x + 1, player_y, map);
    fill(map_copy, player_x - 1, player_y, map);
    fill(map_copy, player_x, player_y + 1, map);
    fill(map_copy, player_x, player_y - 1, map);
}

static int check_accessibility(char **map_copy, t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if ((map->map[i][j] == 'C' || map->map[i][j] == 'E') 
                && map_copy[i][j] != 'F')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int flood_fill_check(t_map *map)
{
    char **map_copy;
    int player_x;
    int player_y;
	int i;

	i = 0;
    map_copy = create_map_copy(map);
    if (!map_copy)
        return (0);
    find_player(map, &player_x, &player_y);
    fill(map_copy, player_x, player_y, map);
    if (!check_accessibility(map_copy, map))
	{
        ft_putendl_fd("Error: Some collectibles or exit are not accessible", 2);
		 while (i < map->height)
        free(map_copy[i++]);
    	free(map_copy);
		return (0);
	}                                  
    while (i < map->height)
        free(map_copy[i++]);
    free(map_copy);
    return (1);
}
