#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef	BUFFER_SIZE
#define	BUFFER_SIZE 5

// 	EXTRAIRE UNE LIGNE JUSQU'AU '\n'
char	*extract_line(char *trace)
{
	int	i;
	char	*line;

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
char	*next_line(char	*trace)
{
	int	i;
	int	j;

	char	*new_line;
	i = 0;
	j = 0;
	while (trace[i] && trace[i] != '\n')
		i++;
	if (!trace[i])
	{
		free(trace);
		return (NULL);
	}
	new_trace = malloc((ft_strlen))
}

//	LIRE LES DONNEES AVEC READ;
//	MAJ DE TRACE;
//	EXTRAIRE UNE LIGNE
char	*get_next_line(int fd)
{
	char 		*buffer;
	char 		*line;
	static char	*trace;
	int		nbr_read;
	
	// SECURITE
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// ALLOUE BUFFER DE LECTURE
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	trace = malloc(1 * sizeof(char))
		if(!trace)
			return (NULL);

	while (1)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = '\0';
		trace = ft_strjoin(trace, buffer); //cat 2 str
		if (ft_strchr(trace, '\n') != NULL)
			break;
	}

	1 fonction qui recupere la ligne;

	line = trace;
	
	
	strjoin(trace, buffer);
	lis buffer jusquq un \n ou un \0;
	stock avant \n premier dans line;
	stock apres \n dans trace
	
	nbr_read = read(fd, line, BUFFER_SIZE);
//	if (nb_read != BUFFER_SIZE)
//			retrun(line)i
//
	return (line);
}

int main()
{
	int	fd;
	char	*line;

	if (fd < 0)
		return (1);

	fd = open("test.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	//printf("%s", line);
	free(line);
}
