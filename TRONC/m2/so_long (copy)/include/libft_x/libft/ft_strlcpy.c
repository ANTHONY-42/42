/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:30:40 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/20 16:04:28 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
		{
			i++;
		}
		return (i);
	}
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
	{
		i++;
	}
	return (i);
}

/*
int main()
{
	char	dst[5];
	char	src[] = "strlcpy";
	int	len = ft_strlcpy(dst, src, sizeof(dst));
	printf("size src = %d\n", len);
	printf("size dst = %zu\n", sizeof(dst));
	printf("strlcpy = %s", dst);

}
*/
