/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:42:48 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/18 18:33:56 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

// 	fonction qui trouve la 1er occurence;
char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

/*
int main()
{
	char	s[] = "bonjour";
	char	c = 'o';
	char	*result;

	result = ft_strchr(s, c);
	printf("%s", result);
}
*/
