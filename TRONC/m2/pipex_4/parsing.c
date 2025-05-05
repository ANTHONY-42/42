#include "pipex.h"

void	parsing(int ac, char **av, t_pipex *fd)
{
	if (ac != 5)
		error("args");
	
	fd.infile = open(av[1], O_RDONLY);
	if (fd.infile < 0)
		error("infile");

	fd.outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd.outfile < 0)
		error("outfile");

	if (pipe(fd.pipefd) == -1)
		error("pipe");
}
