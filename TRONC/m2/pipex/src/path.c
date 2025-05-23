/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anturtsc <anturtsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:20:13 by anturtsc          #+#    #+#             */
/*   Updated: 2025/05/22 21:35:41 by anturtsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

char	*absolute_path(char **path, char *cmd)
{
	int		i;
	char	*pathname;
	char	*path_tmp;

	i = 0;
	while (path[i])
	{
		path_tmp = ft_strjoin(path[i], "/");
		pathname = ft_strjoin(path_tmp, cmd);
		free(path_tmp);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	return (NULL);
}

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	**path;
	char	*pathname;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		return (NULL);
	pathname = absolute_path(path, cmd);
	free_path(path);
	return (pathname);
}
