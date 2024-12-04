/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:56 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/08 18:43:15 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		f(tab[i]);
		i++;
	}
}

/*
int main()
{
	int *tab = {2, 4, 7, 1};
	int i = 0; 
	ft_foreach(&tab, 3, &putnbr);
	while (tab[i])
		printf("%d\n", tab[i++]);
	return(0);
}
*/
