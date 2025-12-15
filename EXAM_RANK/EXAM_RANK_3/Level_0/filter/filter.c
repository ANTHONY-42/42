#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE	4096
#endif

void	ft_filter(char *line, char **av)
{
	ssize_t	i	= 0;
	ssize_t	j	= 0;
	ssize_t	k	= 0;
	ssize_t	len_av	= strlen(av[1]);

	while (line[i])
	{
		j = 0;
		while (line[i + j] && av[1][j]
				&& line[i + j] == av[1][j])
			j++;
		if (j == len_av)
		{
			k = 0;
			while (k < len_av)
			{
				write(1, "*", 1);
				k++;
			}
			i += len_av;
		}
		else
		{
			write(1, &line[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	char	buffer[BUFFER_SIZE];
	char	*trace		= NULL;
	char	*line		= NULL;
	ssize_t	nb_read		= 0;
	ssize_t	ttl_read	= 0;
	ssize_t	i		= 0;

	if (ac != 2 || av[1][0] == '\0')
		return (1);

	while ((nb_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		trace = realloc(line, ttl_read + nb_read + 1);
		if (!trace)
		{
			perror("Error");
			if (line)
				free(line);
			return (1);
		}
		line = trace;
		i = 0;
		while (i < nb_read)
		{
			line[ttl_read + i] = buffer[i];
			i++;
		}
	ttl_read += nb_read;
	line[ttl_read] = '\0';
	}
	if (nb_read < 0)
	{
		perror("Error");
		if (line)
			free(line);
		return (1);
	}
	if (line)
	{
		ft_filter(line, av);
		free(line);
		return (0);
	}
	return (1);
}
