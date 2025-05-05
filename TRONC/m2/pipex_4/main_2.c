#include "pipex.h"

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
	{
		full_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(full_path, X_OK) == 0)
		{
			// free tab avant de return
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}

static char	*get_path(char *cmd, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i][5], ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{

	}
}







void	error(char *str)
{
	perror(str);
	exit(1);
}

static char	*get_path(char	*cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*full_path;
}

void	exec_cmd(char *arg, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(arg, ' ');
	if (!cmd || !cmd[0])
		error("cmd invalid");
	
	path = get_path(cmd[0], envp);
	if (!path)
		perror(cmd);
	if (execve(path, arg, envp) == -1)
		error("execve");
}

void	process_1(char **av, char **envp, int *pipefd, int infile)
{	
	pid_t	pid_1;

	pid_1 = fork();
	if (pid_1 < 0)
		error("fork1");
	if (pid_1 == 0)
	{
		dup2(infile, 0);
		dup2(pipe[1], 1);
		close(pipe[0]);
		close(pipe[1]);
		exec_cmd(av[2], envp);
	}
}

void	process_2(char **av, char **envp, int *pipefd, int outfile)
{
	pid_t	pid_2;

	pid_2 = fork();
	if (pid_2 < 0)
		error("fork2");
	if (pid_2 == 0)
	{
		dup2(pipefd[0], 0);
		dup2(outfile, 1);
		close(pipefd[0]);
		close(pipefd[1]);
		exec_cmd(av[3], envp);
	}
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
