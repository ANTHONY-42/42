#include "pipex.h"

void	pipex(int ac, char **av, char **envp)
{
	int	input;
	int	output;
	int	pipe_fd[2];

	intput = open(av[1], O_RDONLY);
	if (input < 0)
		error("open input");
	output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output < 0)
		error("")

	
	pid1 = fork();
	if (pid1 == -1)
		error("fork 1");
	if (pid1 == 0)
	{
		dup2(pipe_fd[0], 0);
		execve(av[2]);
		dup2(input, 0);
	}
}
