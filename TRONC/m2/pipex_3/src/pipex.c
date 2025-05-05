#include "pipex.h"

void	pipex(char **av, char **envp)
{
	int	input;
	int	output;
	int	pipefd[2];

	input = open(av[1], O_RDONLY);
	if (input < 0)
		error("input");
	output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output < 0)
		error("output");

	if (pipe(pipefd) == -1)
		error("pipe");

	pid_t	pid;
	pid = fork();
	if (pid == -1)
		error("fork_1");
	if (pid == 0)
	{
		dup2(input, 0);
		dup2(pipe[1], 1);
	}
	
}


0 | STDIN | terminal
1 | STDOUT| terminal
2 | STDERR | terminal
3 | input | ...
4 | output | ...
5 | pipefd[0] | ...
6 | pipefd[1] | ...
