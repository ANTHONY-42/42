#include "pipex.h"

int 	main(int ac, char **av, char **envp)
{
	if (ac != 5)
		error("args");
	pipex(argv, envp);
	return (0);
}
