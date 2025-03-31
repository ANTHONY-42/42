/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:43:58 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 20:12:24 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fonction qui "extrait une sous-chaîne";
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	len_s;

	i = 0;
	j = 0;
	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = '\0';
	return (substr);
}
/*
   int	main(void)
   {
   char const	*str;
   char		*s;

   str = "bonjour ! ";
   s = ft_substr(str, 400, 20);
   printf("%s\n", s);
   return (0);
   }
   */
