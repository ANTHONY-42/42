/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:19:40 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/21 20:19:45 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *arg, char **envp, t_open *fd)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(arg, ' ');
	if (!cmd || !cmd[0])
		error("cmd_invalid", fd);
	path = get_path(envp, cmd[0]);
	if (!path)
		error(cmd[0], fd);
	if (execve(path, cmd, envp) == -1)
		error("execve", fd);
}

void	process_1(char **av, char **envp, t_open *fd)
{
	fd->pid_1 = fork();
	if (fd->pid_1 < 0)
		error("process_1", fd);
	if (fd->pid_1 == 0)
	{
		dup2(fd->input, 0);
		dup2(fd->pipefd[1], 1);
		close_fd(fd);
		exec_cmd(av[2], envp, fd);
	}
}

void	process_2(char **av, char **envp, t_open *fd)
{
	fd->pid_2 = fork();
	if (fd->pid_2 < 0)
		error("process_2", fd);
	if (fd->pid_2 == 0)
	{
		dup2(fd->pipefd[0], 0);
		dup2(fd->output, 1);
		close_fd(fd);
		exec_cmd(av[3], envp, fd);
	}
}

void	pipex(char **av, char **envp, t_open *fd)
{
	process_1(av, envp, fd);
	process_2(av, envp, fd);
	close_fd(fd);
	waitpid(fd->pid_1, NULL, 0);
	waitpid(fd->pid_2, NULL, 0);
}
