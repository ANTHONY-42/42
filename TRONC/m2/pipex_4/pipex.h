#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_pipex
{
	int	infile;
	int	outfile;
	int	pipefd[2];
}	t_pipex;
#endif
