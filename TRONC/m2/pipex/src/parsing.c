/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:19:28 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/21 20:22:58 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(int ac, char **av, char	**envp, t_open *fd)
{
	if (!envp)
		error("envp", fd);
	if (ac == 5)
	{
		fd->input = open(av[1], O_RDONLY);
		if (fd->input < 0)
			error("input", fd);
		fd->output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd->output < 0)
			error("output", fd);
		pipe(fd->pipefd);
		if (fd->pipefd < 0)
			error("pipefd", fd);
	}
	else
		error("number args", fd);
}
