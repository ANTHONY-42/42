#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef	struct	s_map
{
	char	**tab;
	int	C;
	int	E;
	int	P;
}		t_map;

 //		SO_LONG			//

//	PARSING
t_map	*parsing(int ac, char **av);
t_map	*load_map(int fd);

//	VERIF_MAP
void	verif_map(char **tab, t_map *map);
void	check_line(char *line, int ref_size, int border, t_map *map);
void	check_tiles(t_map *map);
void	increment_tiles(char c, t_map *map);

//	GET_NEXT_LINE
char	*get_next_line(int fd);
char	*extact_line(char **stored);

//	UTILS
int	ft_strlen(char *str);
int	ft_strlen_tab(char **tab);
char    *ft_strnstr(const char *str, const char *to_find, size_t n);
char    *ft_strdup(const char *s);
void	ft_putstr(char *str);
//	FREE
void    error();
# endif
