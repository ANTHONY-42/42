/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:53:04 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/20 16:53:49 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//TRANSFORME UNE MAJ EN MIN;
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

/*
#include <stdio.h>
int main()
{
    char uppercase = 'G';
    char lowercase = 'g';
    char non_letter = '5';

    printf("Original: %c, To Lower: %c\n", uppercase, ft_tolower(uppercase));
    printf("Original: %c, To Lower: %c\n", lowercase, ft_tolower(lowercase));
    printf("Original: %c, To Lower: %c\n", non_letter, ft_tolower(non_letter));
}
*/
