/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:20:15 by anturtsc          #+#    #+#             */
/*   Updated: 2025/03/20 13:42:24 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	t_map	*map;

	map = parsing(ac, av, map)
	if (!map)
		error();
}
