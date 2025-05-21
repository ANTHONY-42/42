#include "pipex.h"

void	parsing(int ac, char **av, t_pipex *fd)
{
	if (ac != 5)
		error("args");
	
	fd->input = open(av[1], O_RDONLY);
	if (fd->input < 0)
		error("infile");

	fd->output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd->output < 0)
		error("outfile");

	if (pipe(fd->pipefd) == -1)
		error("pipe");
}
