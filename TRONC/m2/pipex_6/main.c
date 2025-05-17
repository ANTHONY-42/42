#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	t_pipe	fd;
	parsing(ac, av, &fd);
}
