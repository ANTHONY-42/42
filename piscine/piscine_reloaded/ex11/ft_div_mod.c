/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:07:47 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/08 14:24:58 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main()
{
	int	a;
	int	b;
	int	div;
	int	mod;
	a = 42;
	b = 10;
	ft_div_mod(a, b, &div, &mod);
	printf("div = %d | mod = %d", div, mod);
}
*/
