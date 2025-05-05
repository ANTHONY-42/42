#include "pipex.h"

void	exec_cmd(char *arg, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(arg, ' ');
	if (!cmd || !cmd[0])
		error("cmd_invalid");

	path = get_path(cmd[0], envp);
	if (!path)
		perror(cmd);
	if (execve(path, arg, envp) == -1)
		error("execve");
}

void	process_1(char **av, char **envp, t_pipex *fd)
{
	pid_t	pid_1;

	pid_1 = fork();
	if (pid_1 < 0)
		error("fork_1");
	if (pid_1 == 0)
	{
		dup2(fd.infile, 0);
		dupe2(fd.pipe[1], 1);
		close(fd.pipe[0]);
		close(fd.pipe[1]);
		exec_cmd(av[2], envp);
	}
}

void	process_2(char **av, char **envp, t_pipex *fd)
{
	pid_t	pid_2;

	pid_2 = fork();
	if (pid_2 < 0)
		error("fork_2");
	if (pid_2 == 0)
	{
		dup2(fd.pipefd[0], 0);
		dup2(fd.outfile, 1);
		close(fd.pipefd[0]);
		close(fd.pipefd[1]);
		exec_cmd(av[3], envp);
	}
}

void	pipex(char **av, char **envp, t_pipex *fd)
{
	process_(av, envp, fd);
	waitpid(pid1, NULL, 0);
	process_2(av, envp, fd);
	waitpid(pid2, NULL, 0);
}
