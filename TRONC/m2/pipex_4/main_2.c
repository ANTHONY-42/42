#include "pipex.h"

void	path(char **path)
{
	char	*full_path;
	int		i;
	
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(full_path, X_OK) == 0)
		{
			i = 0;
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}

}

static char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;

	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}

int main(int ac, char **av, char **envp)
{
	int	infile;
	int	outfile;
	int	pipefd[2];

	if (ac != 5)
		error("args");

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		error("infile");

	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error("outfile");

	if (pipe(pipefd) == -1)
		error("pipe");

	process_1(av, envp, pipefd, infile);
	waitpid(pid1, NULL, 0);
	process_2(av, envp, pipefd, outfile);
	waitpid(pid2, NULL, 0);

	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	close(outfile);
	return (0);
}
