/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:49:18 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/20 16:52:12 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//TRANSFORME UN MIN EN MAJ;
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

/*
#include <stdio.h>
int main()
{
    char lowercase = 'b';
    char uppercase = 'B';
    char non_letter = '1';

    printf("Original: %c, To Upper: %c\n", lowercase, ft_toupper(lowercase));
    printf("Original: %c, To Upper: %c\n", uppercase, ft_toupper(uppercase));
    printf("Original: %c, To Upper: %c\n", non_letter, ft_toupper(non_letter));
}
*/
