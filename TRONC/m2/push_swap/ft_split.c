#include "push_swap.h"

int	is_sep(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	count_letter(char *str)
{
	int	i;

	i = 0;
	while (!is_sep(str[i]) && str[i])
		i++;
	return (i);
}

int	count_word(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_sep(str[i]) && str[i])
			i++;
		if (str[i])
			count++;
		while (!is_sep(str[i]) && str[i])
			i++;
	}
	return (count);
}

char	*epurstr(char *str)
{
	int		i;
	int		j;
	int		space;
	char	*dst;

	i = 0;
	j = 0;
	space = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dst)
		return (NULL);
	while (str[i])
	{
		while (is_sep(str[i]) && str[i])
			i++;
		if (space && str[i])
			dst[j++] = ' ';
		while (!is_sep(str[i]) && str[i])
			dst[j++] = str[i++];
		space = 1;
	}
	dst[j] = '\0';
	return (dst);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = ((k = 0));
	str = epurstr(str);
	if (!str)
		return (NULL);
	tab = (char **)malloc((count_word(str) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		j = 0;
		tab[k] = malloc((count_letter(&str[i]) + 1) * sizeof(char));
		if (!tab[k])
			return (NULL);
		while (!is_sep(str[i]) && str[i])
			tab[k][j++] = str[i++];
		if (str[i])
			i++;
		tab[k++][j] = '\0';
	}
	return (tab[k] = (NULL), tab);
}
