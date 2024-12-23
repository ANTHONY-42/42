/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:03:41 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/04 19:55:42 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int nb)
{
	static int	i;

	i = 0;
	if (nb > 9)
	{
		ft_put_u(nb / 10);
	}
	i++;
	ft_put_c(nb % 10 + '0');
	return (i);
}
