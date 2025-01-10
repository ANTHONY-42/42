/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:18:34 by anturtsc          #+#    #+#             */
/*   Updated: 2025/01/09 15:49:31 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_trace(int fd, char *buffer, char *trace)
{
	int		nb_read;
	char	*tmp;

	while (!ft_strchr(trace, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(trace);
			return (NULL);
		}
		if (nb_read == 0)
			break ;
		buffer[nb_read] = '\0';
		tmp = trace;
		trace = ft_strjoin(trace, buffer);
		free(tmp);
		if (!trace)
			return (NULL);
	}
	return (trace);
}

char	*extract_line(char *trace)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	if (!trace || trace[0] == '\0')
		return (NULL);
	while (trace[len] && trace[len] != '\n')
		len++;
	if (trace[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (trace[i] && trace[i] != '\n')
	{
		line[i] = trace[i];
		i++;
	}
	if (trace[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*maj_trace(char *trace)
{
	int		i;
	int		j;
	char	*new_trace;

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

char	*machine(int fd, char *buffer, char **trace, char *line)
{
	*trace = extract_trace(fd, buffer, *trace);
	free(buffer);
	buffer = NULL;
	if (!*trace)
		return (NULL);
	line = extract_line(*trace);
	*trace = maj_trace(*trace);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*trace;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!trace)
	{
		trace = malloc(1);
		if (!trace)
		{
			free(buffer);
			return (NULL);
		}
		trace[0] = '\0';
	}
	line = machine(fd, buffer, &trace, line);
	return (line);
}
