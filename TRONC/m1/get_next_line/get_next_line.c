#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include "libft.h"

#ifndef	BUFFER_SIZE
#define	BUFFER_SIZE 5
#endif

char *strjoin(const char *s1, const char *s2) {
    if (!s1 && !s2)
        return NULL;
    if (!s1)
        return strdup(s2); // Si s1 est NULL, on retourne une copie de s2
    if (!s2)
        return strdup(s1); // Si s2 est NULL, on retourne une copie de s1

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Allouer suffisamment d'espace pour les deux chaînes + '\0'
    char *result = malloc(len1 + len2 + 1);
    if (!result)
        return NULL;

    // Copier s1 dans result
    strcpy(result, s1);
    // Ajouter s2 à la suite
    strcat(result, s2);

    return result;
}

// 	EXTRAIRE UNE LIGNE JUSQU'AU '\n'
char	*trace_x_line(char *trace)
{
	int	i;
	char	*line;

	i = 0;
	if (!trace || trace[0] == '\0')
		return (NULL);
	while (trace[i] && trace[i] != '\n')
		i++;
	line = malloc((i + 2) *  sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (trace[i] && trace[i] != '\n')
	{
		line[i] = trace[i];
		i++;
	}
	if (trace[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

//	MAJ DE TRACE APRES '\n'
char	*maj_trace(char	*trace)
{
	int	i;
	int	j;

	char	*new_trace;
	i = 0;
	j = 0;
	while (trace[i] && trace[i] != '\n')
		i++;
	if (!trace[i])
	{
		free(trace);
		return (NULL);
	}
	new_trace = malloc((strlen(trace) - i + 1) * sizeof(char));
	if (!new_trace)
		return (NULL);
	i++; // passe le '\n'
	while (trace[i])
		new_trace[j++] = trace[i++];
	new_trace[j] = '\0';
	free(trace);
	return (new_trace);
}

//	LIRE LES DONNEES AVEC READ;
//	MAJ DE TRACE;
//	EXTRAIRE UNE LIGNE
static char	*get_next_line(int fd)
{
	static char	*trace;
	char 		*buffer;
	char 		*line;
	int		nb_read;

	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	trace = malloc(1);
	if (!trace)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	while (!strchr(trace, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE); // rempli buffer
		if (nb_read <= 0)
			break;
		buffer[nb_read] = '\0';
		trace = strjoin(trace, buffer); //cat buffer a la suite de trace
	}
	free(buffer);
	if (!trace || trace[0] == '\0')
		return (NULL);
	
	line = trace_in_line(trace);
	trace = maj_trace(trace);
	return (line);
}

int main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0)
		return (1);

	printf("%s\n", line);
	free(line);
	close(fd);
}
