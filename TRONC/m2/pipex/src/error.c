/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:19:56 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/21 20:19:57 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_open *fd)
{	
	if (fd->input)
		close(fd->input);
	if (fd->output)
		close(fd->output);
	if (fd->pipefd[0])
		close(fd->pipefd[0]);
	if (fd->pipefd[1])
		close(fd->pipefd[1]);
}

void	error(char *str, t_open *fd)
{
	close_fd(fd);
	perror("error");
	perror(str);
	exit(1);
}
