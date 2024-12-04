/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:38:01 by mkerrien          #+#    #+#             */
/*   Updated: 2024/09/22 03:02:09 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	rush(unsigned int x, unsigned int y);

void	ext_r(unsigned int x, unsigned int y, unsigned int col, unsigned int r)
{
	if ((r == 1 && col == 1) || (r == x && col == y && y != 1 && x != 1))
		ft_putchar('/');
	else if ((r == 1 && col == y) || (r == x && col == 1))
		ft_putchar('\\');
	else if (r != 1 && r != x)
		ft_putchar('*');
}

void	put_middle_rows(unsigned int x, unsigned int r)
{
	if (r == 1 || r == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(unsigned int x, unsigned int y)
{
	unsigned int	r;
	unsigned int	col;

	r = 1;
	col = 1;
	if (x <= 0 || y <= 0)
		return ;
	else
	{
		while (col <= y)
		{
			r = 1;
			while (r <= x)
			{
				if (col == 1 || col == y)
					ext_r(x, y, col, r);
				else
					put_middle_rows(x, r);
				r++;
			}
			ft_putchar('\n');
			col++;
		}
	}
}
