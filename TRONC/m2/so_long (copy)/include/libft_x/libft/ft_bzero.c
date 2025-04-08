/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:34:49 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 12:28:51 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h> // Pour size_t

// bzero remplir la mémoire la valeur 0;
// str = |0|0|0|0|0|0|
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>
   int main()
   {
   char str[10];

   ft_bzero(str, 5);
   printf("str après ft_bzero = %s\n", str);
   }
   */
