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
		printf("erreur infile");
		return (1);
	}

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		printf("erreur outfile");
		close(infile);
		return (1);
	}
	printf("Pipe created: read = %d, write = %d\n", pipe_fd[0], pipe_fd[1]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(infile);
	close(outfile);
	return (0);
}
