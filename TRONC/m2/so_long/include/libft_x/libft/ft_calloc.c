/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:51:46 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/20 19:37:28 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h> // Pour size_t

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*src;

	if (size && nmemb > 2147483647 / size)
	{
		return (0);
	}
	src = malloc(nmemb * size);
	if (!src)
	{
		return (0);
	}
	ft_bzero(src, (size * nmemb));
	return (src);
}
