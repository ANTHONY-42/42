/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:19:14 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/23 13:23:33 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_open	fd;

	if (!envp)
	{
		ft_putstr_fd("envp not exist\n", 2);
		exit(1);
	}
	if (ac != 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(1);
	}
	ft_memset(&fd, 0, sizeof(t_open));
	pipex(av, envp, &fd);
}
