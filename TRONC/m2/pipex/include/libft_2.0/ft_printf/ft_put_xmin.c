/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_xmin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:32:35 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/03 19:14:33 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_xmin(unsigned int nb)
{
	static int	i;
	char		*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_put_xmin(nb / 16);
	}
	i++;
	ft_put_c(hex[nb % 16]);
	return (i);
}
