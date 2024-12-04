/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:03:13 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/03 16:20:21 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_i(int nb)
{
	static int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_put_c('-');
		nb = nb * -1;
		i++;
	}
	if (nb > 9)
	{
		ft_put_i(nb / 10);
		ft_put_i(nb % 10);
	}
	i++;
	ft_put_c(nb % 10 + '0');
	return (i);
}