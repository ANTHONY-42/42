/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:22:09 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/20 20:09:01 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_d = 0;
	len_s = 0;
	while (dst[len_d] && len_d < dstsize)
	{
		len_d++;
	}
	while (src[len_s])
	{
		len_s++;
	}
	if (dstsize <= len_d)
		return (dstsize + len_s);
	while (src[i] && (len_d + i) < (dstsize - 1))
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

/*
int	main()
{
	char	dst[7] "dst";
	char	src[] = "src";

	size_t result = ft_strlcat(dst, src, sizeof(dst));
	printf("after dst = %s\n", dst);
	printf("taille dst = %zu", result);
}
*/
