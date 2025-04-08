/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:31:57 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/27 14:37:41 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

// s = string
// c = seperateur
static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	count_lettre(char const *s, int c)
{
	int	len_lettre;

	if (!ft_strchr(s, c))
	{
		len_lettre = ft_strlen(s);
	}
	else
	{
		len_lettre = ft_strchr(s, c) - s;
	}
	return (len_lettre);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	size_t	nb_lettre;
	char	**split;

	i = ((j = 0));
	split = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			nb_lettre = count_lettre(&s[i], c);
			split[j++] = ft_substr(s, i, nb_lettre);
			if (!split[j - 1])
				return (free_split(split), NULL);
			i = i + nb_lettre;
		}
	}
	split[j] = NULL;
	return (split);
}

/*
#include <stdio.h>
int main()
{
	char **tab = ft_split("-----salut----comment-ca-va", '-');

	int i = 0;
	while (tab[i] != NULL)
		printf("%s\n", tab[i++]);
                len_lettre = ft_strlen(s);
                len_lettre = ft_strlen(s);
                len_lettre = ft_strlen(s);
                len_lettre = ft_strlen(s);
}
*/
