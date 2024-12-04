/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:38:17 by anturtsc          #+#    #+#             */
/*   Updated: 2024/10/03 19:05:43 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power == 0)
	{
		return (1);
	}
	else if (nb == 0 || power < 0)
	{
		return (0);
	}
	else
	{
		while (power > 1)
		{
			n *= nb;
			power--;
		}
	}
	return (n);
}
