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
	pid_t pid_1;
	pid_t pid_2;
	int	input;
	int	output;
	int	pipefd[2];
}	t_pipex;
#endif

// typedef struct	s_pipex
// {
// 	pid_t *pid;
// 	char *input;
// 	char *output;
// 	int	pipefd[2];
// int len
// }	t_pipex;
// len = argc - 3
// pid = (pid_t *)malloc(sizeof(pid_t) * len);
// ./pipex infile cmd1 cmd2 outfile