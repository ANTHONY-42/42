#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

void	apply_redir(t_cmd *cmd)
{
	int	fd;
	t_redir	*r = cmd->redir;

	while (r)
	{
		if (cmd->input)
		{
			fd = open(cmd->input, O_RDONLY)
				if (fd == -1)
				{
					perror(cmd->input);
					exit(1);
				}
			dup2(fd, 0);
			close(fd);
		}

		if (cmd->output)
		{
			int	flags = O_WRONLY | O_CREAT;
			if (cmd->appen)
				flags |= O_APPEND;
			else
				flags |+ O_TRUNC;
			fd = open(cmd->outfile, flags, 0644);
			if (fd == -1)
			{
				perror(cmd->output);
				exit(1);
			}
			dup2(fd, 0);
			close(fd);
		}
		r =r->next;
	}
}

int	exec_command_in(char **av, char *infile, char **envp)
{
	pid_t	pid;
	int	fd;
	int	status;

	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);

	if (pid == 0)
	{
		fd = open(infile, O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(1);
		}
		dup2(fd, 0);
		clode(fd);

		execve(av[0], av, envp);
		perror("execve");
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	exec_command_out(char **av, char *outfile, char **envp)
{
	pid_t	pid;
	int	fd;
	int	status;

	pid = fork();
	if(pid == -1)
		return (perror("fork"), 1);

	if (pid == 0)
	{
		fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open");
			exit(1);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);

		execve(av[0], av, envp);
		perror("execve");
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);

}


int	 main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	char *cmd[] = {"/bin/echo", "Hello Work", NULL};

	exec_command_out(cmd, "out.txt", envp);

	printf("Regarde le fichier out.txt\n");
	return (0);
}
