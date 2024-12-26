#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include "libft.h"

#ifndef	BUFFER_SIZE
#define	BUFFER_SIZE 5
#endif

char *strjoin(const char *trace, const char *buffer) {
    if (!trace && !buffer)
        return NULL;
    if (!trace)
        return strdup(buffer);
    if (!buffer)
        return strdup(trace);

    size_t len1 = strlen(trace);
    size_t len2 = strlen(buffer);

    char *result = malloc((len1 + len2 + 1) * sizeof(char));
    if (!result)
        return NULL;

    strcpy(result, trace);
    strcat(result, buffer);

    return result;
}

// 	EXTRAIRE UNE LIGNE JUSQU'AU '\n'
char	*trace_x_line(char *trace)
{
	size_t	i;
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
	int		nb_read;
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	trace = malloc(1);
	if (!trace)
		return (NULL);
	while (!strchr(trace, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return NULL;
		if (nb_read == 0)
			break;
		buffer[nb_read] = '\0';
		trace = strjoin(trace, buffer);
		if (!trace)
			return (NULL);
	}

	if (!trace || trace[0] == '\0')
	{
		free(trace);
		trace = NULL;
		return (NULL);
	}
	line = trace_x_line(trace);
	trace = maj_trace(trace);
	return (line);
}

int main()
{
	int	fd;
	char	*line;
	
	fd = open("texte.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erreur open(fd)");
		return (1);
	}
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
		return 0;
	}
	close(fd);
	return (0);
}
