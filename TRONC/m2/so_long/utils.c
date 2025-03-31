#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	int		len;
// 	char	*dest;

// 	i = 0;
// 	len = 0;
// 	while (s[len])
// 	{
// 		len++;
// 	}
// 	dest = malloc((len + 1) * sizeof(char));
// 	if (dest == NULL)
// 	{
// 		return (NULL);
// 	}
// 	while (s[i])
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
	{
		return ((char *)str);
	}
	i = 0;
	while (i < n && str[i])
	{
		j = 0;
		while ((i + j) < n && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)&str[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

