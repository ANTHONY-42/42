/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:57 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/03 19:47:32 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_d(int nbr)
{
	long	nb;
	int	count;
	
	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		count += ft_put_c('-');
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		count += ft_put_d(nb / 10);
	}
	count++;
	ft_put_c((nb % 10) + '0');
	return (count);
}
