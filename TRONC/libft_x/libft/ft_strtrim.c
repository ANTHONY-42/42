/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:21:45 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 20:14:13 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	occ(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	len_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && occ(s1[start], set))
		start++;
	return (start);
}

int	len_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end > 0 && occ(s1[end], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = len_start(s1, set);
	end = len_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	trim = malloc((end - start + 2) * sizeof(char));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[start], end - start + 2);
	return (trim);
}

/*
int main()
{
	char s1[] = "234strtrim3567";
	char set[] = "0123456789";
	printf("%s", ft_strtrim(s1, set));
}
*/
