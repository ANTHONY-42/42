#ifndef SO_LONG_H
# define SO_LONG_H

# include"libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef	struct	s_map
{
	char	**tab;
}		t_map;

 //		SO_LONG			//

//	PARSING
 int    check_name(char *str);
void    parsing(int ac, char **av);

//	FREE
void    error();
# endif
