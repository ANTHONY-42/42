/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:21:29 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/03 22:37:23 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fonction(char i, va_list args)
{
	int	len;

	len = 0;
	if (i == '%')
		return (ft_put_100());
	else if (i == 'c')
		len = ft_put_c(va_arg(args, int));
	else if (i == 's')
		len = ft_put_s(va_arg(args, char *));
	else if (i == 'p')
		len = ft_put_p(va_arg(args, unsigned long long int));
	else if (i == 'd')
		len = ft_put_d(va_arg(args, int));
	else if (i == 'i')
		len = ft_put_d(va_arg(args, int));
	else if (i == 'u')
		len = ft_put_u(va_arg(args, unsigned int));
	else if (i == 'x')
		len = ft_put_xmin(va_arg(args, unsigned int));
	else if (i == 'X')
		len = ft_put_xmaj(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (format == 0)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len = len + ft_fonction(format[i], args);
		}
		else
		{
			ft_put_c(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// #include <limits.h>

// int	main()
// {
// 	int	p = 45;
// 	int size;
// // 	// int	ft;

// // 	// p = 0;
// // 	// ft = 0;
// // 	// ft = ft_printf("%p", "abcd");
// // 	// printf("retour : %d\n\n", ft);
// // 	// p = printf("%p", "abcd");
// // 	// printf("retour : %d", p);		
// 	//int size = ft_printf("%p\n", &p);
	
// 	size = ft_printf(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
//  	//size = printf("%p\n", &p);
// 	printf("size is %d\n", size);
// 	size = printf(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, (int)LONG_MAX, (int)LONG_MIN, (unsigned int)ULONG_MAX, 0, -42);
// 	printf("size is %d\n", size);
// }
//  /*      
// int	main()
// {
// char 	c = 'a';
// char	*s = "printf";
// void	*p = &s;
// int 	d = 12;
// int 	i = 120;
// unsigned int 	u = 3000000000;
// ft_printf("%%");
// printf("\nMOI: %d\n", ft_printf("c = %c", c));
// printf("\nVRAI: %d\n", printf("c = %c", c));
// }*/
