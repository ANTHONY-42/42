/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:54 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 12:10:50 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stddef.h>

//	fonction qui trouve la dernier occurence;
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last_occ;

	i = 0;
	last_occ = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			last_occ = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (last_occ);
}
