/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:05:47 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/22 20:29:24 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_open
{
	int		input;
	int		output;
	int		pipefd[2];
	char	**cmd;
	pid_t	pid_1;
	pid_t	pid_2;
}	t_open;

// MAIN
void	parsing(int ac, char **av, char **envp, t_open *fd);

// EXEC
void	pipex(char **av, char **envp, t_open *fd);
void	process_1(char **av, char **envp, t_open *fd);
void	process_2(char **av, char **envp, t_open *fd);
void	exec_cmd(char *arg, char **envp, t_open *fd);

// PATH
char	*get_path(char **envp, char *cmd);
char	*absolute_path(char **path, char *cmd);
void	free_path(char **path);

// ERROR
void	error(char *str, char *error, t_open *fd);
void	close_fd(void);

#endif
