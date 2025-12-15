#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int	status;
	if (ac < 2)
	{
		printf("Error : arg");
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(av[1], &av[1], envp);
		perror("execve");
		exit(127);
	}

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		return (1);
	}
	return (0);
}
