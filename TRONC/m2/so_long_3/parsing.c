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

void	parsing(int ac, char **av)
{
	char	*str;
	str = av[1];
	if (!(ac == 2))
		error();
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
		error();
	else
		printf("ok");
	load_map()
}

//	fd = open("av[1]", O_RDONLY);
//	printf("%s", fd);

	/*
	//tab = init_tab(fd);
	//parsing_map(tab);
}
---------------------------------------------------------------




















	line = get_next_line(fd);
	if (!line)
		ft_putstr("Error\0");
		
	while (line)
	{
        line = get_next_line(fd);
        if (!line)
                ft_putstr("Error\0");

        while (line)
        {
                tab[nb_line] = ft_strdup(line);
                line = get_next_line(fd);
                nb_line++;
        }
        if (nb_line < 3)
                ft_putstr("Error\0");


		tab[nb_line] = ft_strdup(line);
		line = get_next_line(fd);
		nb_line++;
	}
	if (nb_line < 3)
		ft_putstr("Error\0");

	check_map(tab);


}*/
