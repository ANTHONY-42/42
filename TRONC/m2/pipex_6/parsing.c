#include "pipex.h"

void	parsing(int ac, char **av, t_open fd)
{
	if (ac == 5)
	{
		fd.input = open(av[1], O_RDONLY);
		if (fd.input < 0)
			error("input");

		fd.output(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd.output < 0)
			error("output");
		
		pipe(fd.pipefd);
		if (fd.pipe < 0)
			error("pipefd");
	}
	else
		error("number args");
}
