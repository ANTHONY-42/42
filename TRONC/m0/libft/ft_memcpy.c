/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:21:34 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 17:59:04 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// STRNCPY DE BLOCK MEMEOIRE; SANS TENIR COMPTE DE CHAR SPECIAUX EX : "\0"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
int main()
{
    char src[50] = "Hello, World!";
    char dst[50];  // Destination non initialisée

    // Copier le contenu de src vers dst
    ft_memcpy(dst, src, strlen(src) + 1);

    // Afficher le résultat
    printf("Source: %s\n", src);
    printf("Destination après memcpy: %s\n", dst);

    return 0;
}*/
