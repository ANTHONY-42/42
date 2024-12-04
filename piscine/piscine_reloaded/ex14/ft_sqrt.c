/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:14:53 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/08 19:38:54 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int n)
{
	long	nb;
	long	i;

	i = 0;
	nb = n;
	if (nb < 1)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	i = 2;
	while (i <= nb / i)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}