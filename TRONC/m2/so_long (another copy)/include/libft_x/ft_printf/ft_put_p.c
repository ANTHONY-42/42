/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:04:02 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/03 19:12:39 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_put_p(unsigned long long int nb)
{
	static int	i;
	char		*hexa;

	i = 2;
	hexa = "0123456789abcdef";
	if (nb == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	if (nb >= 16)
	{
		ft_put_p(nb / 16);
	}
	if (i == 2)
	{
		write(1, "0x", 2);
	}
	i++;
	ft_put_c(hexa[nb % 16]);
	return (i);
}
