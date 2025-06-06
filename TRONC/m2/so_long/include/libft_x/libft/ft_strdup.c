/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:04:58 by anturtsc          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:41 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// STRCPY AVEC MALLOC;
char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (s[len])
	{
		len++;
	}
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int main()
{
	char	s1[] = "strdup";
	printf("%s", ft_strdup(s1));
}
*/
