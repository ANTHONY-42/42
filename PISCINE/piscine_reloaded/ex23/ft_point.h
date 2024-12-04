/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:40:30 by anturtsc          #+#    #+#             */
/*   Updated: 2024/11/08 17:08:49 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct s_point
{
	int	x;
	int	y;	
}	t_point;

#endif

/*test
ft_point.c
#include "ft_point.h"

void set_point(t_point *point)
{
        point->x = 42;
        point->y = 21;
}

int main(void)
{
        t_point point;
        set_point(&point);
        return (0);
}
*/
