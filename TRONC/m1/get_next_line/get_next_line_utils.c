/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:32:59 by anturtsc          #+#    #+#             */
/*   Updated: 2025/01/06 16:59:07 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *trace, char *buffer)
{
	int		i;
	int		j;
	size_t	len;
	char	*result;

	i = 0;
	j = 0;
	if (!trace && !buffer)
		return (NULL);
	if (!trace)
		return (ft_strdup(buffer));
	if (!buffer)
		return (ft_strdup(trace));
	len = ft_strlen(trace) + ft_strlen(buffer);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strcpy(result, trace);
	i = ft_strlen(trace);
	while (buffer[j])
		result[i++] = buffer[j++];
	result[i] = '\0';
	return (result);
}
