#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	infile;
	int	outfile;
	int	pipe_fd[2];

	if (argc != 5)
		return (printf("erreur argument"), 1);
	if (pipe(pipe_fd) == -1)
		return (printf("erreur pipe"), 1);



	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		return ((printf("erreur infile"), 1);
	}

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		close(infile);
		return ((printf("erreur outfile"), 1);
	}

	pid_t pid1 = fork();
	if (pid1 == 0)
		first_child(infile, pipe_fd, argv[2], envp);

	pid_t pid2 = fork();
	if (pid2 == 0)
		second_child(outfile, pipe_fd, argv[3], envp);
	
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	close(outfile);
	return (0);
}
