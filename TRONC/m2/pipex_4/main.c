#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	parsing();
	pipex();
	close_fd();
}
