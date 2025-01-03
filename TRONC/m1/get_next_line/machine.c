#include "get_next_line.h"

char    *extract_trace(int fd, char *buffer, char *trace)
{
	int     nb_read;
	char	*tmp;

	while (!strchr(trace, '\n'))
	{

		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(trace);
			return (NULL);
		}
		if (nb_read == 0)
			break;

		buffer[nb_read] = '\0';
		tmp = trace;
		trace = ft_strjoin(trace, buffer);
		free(tmp);
		if (!trace)
			return (NULL);
	}
	return (trace);
}

char    *extract_line(char *trace)
{
	int     i;
	int     len;
	char    *line;

	i = 0;
	len = 0;
	if (!trace || trace[0] == '\0')
		return (NULL);

	while (trace[len] && trace[len] != '\n')
		len++;
	if (trace[len] == '\n')
		len++;

	line =  malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);

	while (trace[i] && trace[i] != '\n')
	{
		line[i] = trace[i];
		i++;
	}
	if (trace[i])
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char    *maj_trace(char *trace)
{
	int     i;
	int     j;
	char    *new_trace;

	i = 0;
	j = 0;
	while (trace[i] && trace[i] != '\n')
		i++;
	if (!trace[i])
	{
		free(trace);
		return (NULL);
	}
	i++;
	new_trace = malloc(ft_strlen(&trace[i]) + 1);
	if (!new_trace)
	{
		free(trace);
		return (NULL);
	}

	while (trace[i])
		new_trace[j++] = trace[i++];
	new_trace[j] = '\0';
	
	free(trace);
	return (new_trace);
}
