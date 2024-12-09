/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:11:55 by anturtsc          #+#    #+#             */
/*   Updated: 2024/12/06 14:43:32 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h> // Pour size_t
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define TEST 45

//cspdiuxX%
int	ft_printf(const char *format, ...);
int	ft_put_c(int c);
int	ft_put_s(const char *str);
int	ft_put_p(unsigned long long int nb);
int	ft_put_d(int nbr);
int	ft_put_i(int nb);
int	ft_put_u(unsigned int nb);
int	ft_put_xmin(unsigned int nb);
int	ft_put_xmaj(unsigned int nb);
int	ft_put_100(void);

#endif
