#include "so_long.h"

void	check_tiles(t_game *game)
{
	if (game->C < 1)
		error("!game->C < 1\n");
	else if (game->E != 1)
		error("!game->E != 1\n");
	else if (game->P != 1)
		error("!game->P != 1\n");
}

void	increment_tiles(char c, t_game *game)
{
	if (c == 'C')
		game->C++;
	else if (c == 'E')
		game->E++;
	else if (c == 'P')
		game->P++; 
}

void	check_line(t_game *game, char *line, int border)
{
	int	x;
	int	size;

	size = ft_strlen(line); 
	if (size != game->size_x)
		error("!size != game->size_x\n");
	if (line[0] != '1' || line[size - 2] != '1')
			error("!border != '1'\n");
	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (border && (line[x] != '1'))
			error("!border != '1'\n");
		else if (!(line[x] == '0' || line[x] == '1'))
		{
			if (line[x] == 'C' || line[x] == 'E' || line[x] == 'P')
				increment_tiles(line[x], game);
			else
				error("!line[x] != '?'\n");
		}
		x++;
	}
}

void	check_map(t_game *game, char **tab)
{
	int	y;
	int	border;

	y = 0;
	if (game->size_y < 3)
		error("!game->size_y < 3\n");
	while (tab[y])
	{
		border = 0;
		if (y == 0 || y == (game->size_y - 1))
			border++;
		check_line(game, tab[y], border);
		y++;
	}
	check_tiles(game);
	flood_fill(game);
}

