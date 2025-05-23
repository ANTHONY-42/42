/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:19:40 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/23 13:26:08 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd(char *arg, char **envp, t_open *fd)
{
	char	*pathname;

	fd->cmd = ft_split(arg, ' ');
	if (!fd->cmd || !fd->cmd[0])
	{
		error(fd->cmd[0], " : command not found.\n", fd);
	}
	pathname = get_path(envp, fd->cmd[0]);
	if (!pathname)
	{
		error(fd->cmd[0], " : command not found.\n", fd);
		free_path(fd->cmd);
	}
	if (execve(pathname, fd->cmd, envp) == -1)
	{
		free_path(fd->cmd);
		free(pathname);
		error(NULL, "execve command impossible.\n", fd);
	}
}

void	process_1(char **av, char **envp, t_open *fd)
{
	fd->pid_1 = fork();
	if (fd->pid_1 < 0)
		error(NULL, "impossible process_1.\n", fd);
	if (fd->pid_1 == 0)
	{
		fd->input = open(av[1], O_RDONLY);
		if (fd->input < 0)
			error(av[1], " : cannot open file.\n", fd);
		dup2(fd->input, 0);
		dup2(fd->pipefd[1], 1);
		close_fd();
		exec_cmd(av[2], envp, fd);
	}
}

void	process_2(char **av, char **envp, t_open *fd)
{
	fd->pid_2 = fork();
	if (fd->pid_2 < 0)
		error(NULL, "impossible process_2.\n", fd);
	if (fd->pid_2 == 0)
	{
		fd->output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd->output < 0)
			error(av[4], " : cannot open file.\n", fd);
		dup2(fd->pipefd[0], 0);
		dup2(fd->output, 1);
		close_fd();
		exec_cmd(av[3], envp, fd);
	}
}

void	pipex(char **av, char **envp, t_open *fd)
{
	pipe(fd->pipefd);
	if (fd->pipefd < 0)
		error(NULL, "function pipe.\n", fd);
	process_1(av, envp, fd);
	process_2(av, envp, fd);
	close_fd();
	waitpid(fd->pid_1, NULL, 0);
	waitpid(fd->pid_2, NULL, 0);
}
