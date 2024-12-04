/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:00:21 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/26 16:05:41 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	int_to_ascii(int n, int count, char *result)
{
	while (n)
	{
		result[count--] = (n % 10) + '0';
		n = n / 10;
	}
	return (result[count]);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		sign;
	int		count;
	int		i;

	i = 0;
	sign = ft_sign(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = count_digit(n) + sign;
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	if (sign == 1)
	{
		n = n * -1;
		result[i] = '-';
	}
	result[count--] = '\0';
	int_to_ascii(n, count, result);
	return (result);
}

/*
#include <stdio.h>
int	main()
{
printf("%s\n", ft_itoa(-14525));
}
*/
