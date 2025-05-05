#include "pipex.h"

void	parsing(int ac, char **av)
{

	if (ac != 5)
	{
		error("argument < 5")
	}

	int	intput;
	int	output;

	input = open(av[1], O_RDONLY);
	if (input < 0)
		error("open file1");
	output = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output < 0)
		error("open file2");
	pipex(ac, av, envp, input, output);
	close(input);
	close(output);
}
