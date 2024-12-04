/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:06:05 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/08 21:08:36 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_read_file(char *str)
{
	int		fd;
	int		size;
	int		trigger;
	char	reader[100];

	fd = open(str, O_RDONLY);
	if (fd == 1)
	{
		write(1, "Cannot read file.\n", 18);
		return ;
	}
	trigger = 0;
	size = 0;
	while (size > 0 || trigger == 0)
	{
		size = read(fd, reader, 100);
		write(1, reader, size);
		trigger++;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	ft_read_file(argv[1]);
	return (0);
}
