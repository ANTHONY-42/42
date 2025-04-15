/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_xmaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:32:26 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/04 19:42:22 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_xmaj(unsigned int nb)
{
	static int	i;
	char		*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_put_xmaj(nb / 16);
	}
	i++;
	ft_put_c(hex[nb % 16]);
	return (i);
}
