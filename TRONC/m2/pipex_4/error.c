#include "pipex.h"

void	close_fd(t_pipex *fd)
{
	if (fd.input > 0)
		close(fd.input);
	if (fd.output > 0)
		close(fd.output);
	if (fd.pipefd[0] > 0)
		close(fd.pipefd[0]);
	if (fd.pipefd[1] > 0)
		close(fd.pipefd[1]);
	if (fd)
		free(fd);
}

void	error(t_pipex *fd, char *str)
{
	close_fd(fd);
	perror(str);
	exit(1);
}
