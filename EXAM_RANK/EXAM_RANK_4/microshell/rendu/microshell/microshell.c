#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void	error(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int	cd(char **av, int i)
{
	if (i != 2)
	{
		error("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(av[1]))
	{
		error("error: cd: cannot change directory to ");
		error(av[1]);
		error("\n");
		return (1);
	}
	return (0);
}

int	ft_execute(char **av, int i, char **env)
{
	int	has_pipe;
	int	fd[2];
	int	pid;
	int	status;

	has_pipe = av[i] && !strcmp(av[i], "|");
	if (!has_pipe && !strcmp(*av, "cd"))
		return (cd(av, i));
	if (has_pipe && pipe(fd))
	{
		error("error: fatal\n");
		exit(1);
	}
	if ((pid = fork()) < 0)
	{
		error("error: fatal\n");
		exit(1);
	}
	if (pid == 0)
	{
		av[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0))
		{
			error("error: fatal\n");
			exit(1);
		}
                if (!has_pipe && !strcmp(*av, "cd"))
		  return (cd(av, i));
		execve(*av, av, env);
		error("error: cannot execute ");
		error(*av);
		error("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0))
	{
		error("error: fatal\n");
		exit(1);
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	int	i = 0;
	int	status = 0;
	
	while (av[i])
	{
		av += i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i)
			status = ft_execute(av, i, env);
	}
	return (status);
}
