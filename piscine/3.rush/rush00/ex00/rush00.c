/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:38:01 by mkerrien          #+#    #+#             */
/*   Updated: 2024/09/22 16:34:44 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	rush(unsigned int x, unsigned int y);

void	external_rows(unsigned int x, unsigned int row)
{
	if (row == 1 || row == x)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	put_middle_rows(unsigned int x, unsigned int row)
{
	if (row == 1 || row == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(unsigned int x, unsigned int y)
{
	unsigned int	row;
	unsigned int	column;

	row = 1;
	column = 1;
	if (x <= 0 || y <= 0)
		return ;
	else
	{
		while (column <= y)
		{
			row = 1;
			while (row <= x)
			{
				if (column == 1 || column == y)
					external_rows(x, row);
				else
					put_middle_rows(x, row);
				row++;
			}
			ft_putchar('\n');
			column++;
		}
	}
}
