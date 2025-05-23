/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:19:56 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/22 20:29:50 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(void)
{	
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

void	error(char *arg, char *str, t_open *fd)
{
	ft_putstr_fd("Error : ", 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (fd->cmd)
		free_path(fd->cmd);
	close_fd();
	exit(1);
}
