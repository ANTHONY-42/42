/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:08:25 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/27 14:49:49 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (!fd || fd < 0)
		return ;
	write(fd, &c, 1);
}

/*
int	main()
{
	// SORTIE STANDARD
	ft_putcharfd('a', 1);
	// SORTIE D'ERREUR
	ft_putcharfd('a', 2);
}
*/
