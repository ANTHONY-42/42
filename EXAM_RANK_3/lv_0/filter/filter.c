#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE 4096
#endif

void	ft_filter(char *trace, char **av, size_t len_arg)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (trace[i])
	{
		j = 0;
		while (av[1][j] && av[1][j] == trace[j + i])
			j++;
		if (j == len_arg)
		{
			k = 0;
			while (k < len_arg)
			{
				trace[k + i] = '*';
				k++;
			}
			i += (len_arg - 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*trace = NULL;
	char	*trace_tmp = NULL;
	char	buffer[BUFFER_SIZE];
	ssize_t	nb_read = 0;
	ssize_t	ttl_read = 0;;
	ssize_t	len_arg = 0;
	ssize_t	i = 0;

	if (ac != 2 || !av[1][0])
		return (1);
	else
		len_arg = strlen(av[1]);

	while ((nb_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		trace_tmp = realloc(trace, ttl_read + nb_read + 1);
		if (!trace_tmp)
		{
			perror("Error: ");
			free(trace_tmp);
			free(trace);
			return (1);
		}
		trace = trace_tmp;
		i = 0;
		while (i < nb_read)
		{
			trace[ttl_read + i] = buffer[i];
			i++;
		}
		ttl_read += nb_read;
		trace[ttl_read] = '\0';
	}
	if (nb_read < 0)
	{
		perror("Error: ");
		free(trace);
		return (1);
	}
	if (trace)
	{
		ft_filter(trace, av, len_arg);
		printf("%s", trace);
		free(trace);
	}
	return (0);
}
