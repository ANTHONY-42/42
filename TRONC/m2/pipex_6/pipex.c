#include "pipex.h"

void	process_2(char **av, char **envp, t_open *fd)
{
	
}

void	process_1(char **av, char **envp, t_open *fd)
{
	pid_t	pid_1;

	pid_1 = fork();
	if (pid_1 == 0)
		error("process_1")
	if (pid_1 == 0)
	{
		dup2(fd.input, 0);
	}
}

void	pipex()
{
	process_1(av, envp, fd);
	waitpid(pid1, NULL, 0);
}
