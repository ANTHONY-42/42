#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int	c)
{
	size_t		i;
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
	char	*dest;
	int	i;
	int	len;

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

char    *ft_strjoin(const char *trace, const char *buffer) {
    if (!trace && !buffer)
        return NULL;
    if (!trace)
        return strdup(buffer);
    if (!buffer)
        return strdup(trace);

    size_t len1 = strlen(trace);
    size_t len2 = strlen(buffer);

    char *result = malloc((len1 + len2 + 1) * sizeof(char));
    if (!result)
        return NULL;

    strcpy(result, trace);
    strcat(result, buffer);

    return result;
}
