/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:47:34 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/08 14:30:43 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	diff;
	int	*tab;
	int	i;

	diff = max - min;
	tab = NULL;
	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	tab = (int *)malloc(sizeof(int) * (diff));
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}

/*
int	main(int argc, char argv)
{
	int	*test = ft_range(2, 5);
	int	i;
	int	diff;

	i = 0;
	diff = 5 - 2;
	while(i < diff)
	{
		printf("%d", test[i]);
		i++;
	}
	free(test);
}
*/
