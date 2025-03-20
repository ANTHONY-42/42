#include "so_long.h"

void	size_line()
{
	int	x;
	int	count;
	int	size_line;

	size_line = ft_strlen();
	while (tab[n_line][count])
		count++;
	if (count != size_line)
		ft_putstr("Error\n");
}

void	check_element()
{
	int	first;
	int	last;
	int	start
	int	end;

	first = 0;
	start = 0;
	last = ...
	end = ...
	while (line[n_line + 1])
		n_line++;
	first = 0;
	last = n_line;
	while (tab[y])
	{
		if (y = first || y = last)
			{
				if (tab[y][x] != '1')
					ft_putstr("Error\n");
			}
		}
	}
}

void	check_line()
{
	int	size;

	size = ft_strlen(tab[0])
	while (tab[y])
	{
		if (size_error())
			return (1)
		if (element_error)
			return (1);
		if ()
		y++;
	}
	size_line();

}

void	check_map()
{
	char	*line;
	char	**tab;
	int	y;

	nb_line = 0;
	line = get_next_line(fd);
	if (!line)
		ft_putstr("Error\n");

	while (line)
	{
		tab[nb_line] = get_next_line(fd);
		nb_line++;
		if (!line && y < 3)
			ft_putstr("Error\n");
	}
	check_line(tab);
}
