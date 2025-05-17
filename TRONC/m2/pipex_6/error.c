#include "pipex.h"

void	close_fd(t_open fd)
{	
	if (fd.input)
		close(fd.input);
	if (fd.output)
		close(fd.output);
	if (fd.pipefd)
		close(fd.pipefd);
}

void	error(char *str, t_open fd)
{
	close_fd(fd);
	perror("error\n");
	perror("%s", str);
}
