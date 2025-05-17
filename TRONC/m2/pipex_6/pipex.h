#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

typedef	struct	s_open
{
	int	input;
	int	output;
	int	pipe[2];
}	t_open;
#endif
