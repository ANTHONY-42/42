#include "pipex.h"

void	parsing()
{
	if (ac != 5)
		error("ac < 5");
	
	fd.input = open(av[1], O_RDONLY);
	if (fd.input < 0)
		error("!open input");

	fd.output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd.output < 0)
		error("!open output");

	if (pipe(fd.pipefd) == -1)
		error("!pipe");
}
