#include "so_long.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	free(s1 - len1);
	return (result - len1 -len2);
}

char	*extract_line(char **stored)
{
	char	*line;
	char	*new_stored;
	int		i;
	int		j;

	i = 0;
	while ((*stored)[i] && (*stored)[i] != '\n')
		i++;
	if ((*stored)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = (*stored)[j];
	line[j] = '\0';
	if (!(*stored)[i])
	{
		free(*stored);
		*stored = NULL;
		return (line);
	}
	new_stored = malloc(ft_strlen(*stored) - i + 1);
	if (!new_stored)
		return (NULL);
	j = 0;
	while ((*stored)[i])
		new_stored[j++] = (*stored)[i++];
	new_stored[j] = '\0';
	free(*stored);
	*stored = new_stored;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*buffer;
	int			bytes;
	int			i;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		i = 0;
		while (stored && stored[i] && stored[i] != '\n')
			i++;
		if (stored && stored[i] == '\n')
		{
			free(buffer);
			return (extract_line(&stored));
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buffer[bytes] = '\0';
		stored = ft_strjoin(stored, buffer);
	}
	if (!stored || !*stored)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (extract_line(&stored));
}
