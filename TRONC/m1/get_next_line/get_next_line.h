# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# endif
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

// BIBLIOTHEQUE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// FONCTION_GNL
int	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *trace, const char *buffer);

// MACHINE
char	*extract_trace(int fd, char *buffer, char *trace);
char	*extract_line(char *trace);
char	*maj_trace(char *trace);
