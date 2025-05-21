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
	fd->pid_1 = fork();
	if (fd->pid_1 < 0)
		error("fork_1");
	if (fd->pid_1 == 0)
	{
		dup2(fd->infile, 0);
		dup2(fd->pipefd[1], 1);
		close(fd->infile);
		close(fd->pipefd[0]);
		close(fd->pipefd[1]);
		exec_cmd(av[2], envp);
	}
}

//./pipex infile cmd1 cmd2 outfile
void	process_2(char **av, char **envp, t_pipex *fd)
{
	fd->pid_2 = fork();
	if (pid_2 < 0)
		error("fork_2");
	if (pid_2 == 0)
	{
		dup2(fd->pipefd[0], 0);
		dup2(fd->output, 1);
		close(fd->pipefd[0]);
		close(fd->output);
		exec_cmd(av[3], envp);
	}
}

void	pipex(char **av, char **envp, t_pipex *fd)
{
	process_1(av, envp, fd);
	process_2(av, envp, fd);
	waitpid(fd->pid_1, NULL, 0);
	waitpid(fd->pid_2, NULL, 0);
}
