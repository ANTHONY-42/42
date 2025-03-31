/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:08:52 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 12:30:30 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stddef.h>

//remplie une zone memoire avec une valeur specifique;
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
int main()
{
    char str[10] = "0123456789";
    int	i = 0;

    ft_memset(str, '0', sizeof(str) - 1);
    str[9] = '\0';
    printf("str = %s",str);
}
*/
