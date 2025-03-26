/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:54:32 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 18:23:14 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h> // Pour size_t

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		return (ft_memcpy(dst, src, n));
	}
	while (n--)
	{
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	return ((unsigned char *)dst);
}

/*
   int main()
   {
   char str[] = "Bonjour, tout le monde !";

   printf("Avant ft_memmove : %s\n", str);

// Déplacer les 7 premiers caractères à partir de l'index 10
ft_memmove(str + 10, str, 7);

printf("Après ft_memmove : %s\n", str);

return (0);
}
 */
