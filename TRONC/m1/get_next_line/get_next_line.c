#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*trace[BUFFER_SIZE] = {0};
	char *line;
//	char *buffer;
	int	nbr_read;


	strjoin(trace, buffer);
	lis buffer jusquq un \n ou un \0;
	stock avant \n premier dans line;
	stock apres \n dans trace
	
	nbr_read = read(fd, line, BUFFER_SIZE);
//	if (nb_read != BUUFER_SIZE)
//			retrun(line)i
//
	return (line);
}

int main()
{
	int	fd;
	char	line[50];

	fd = open("test.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	//printf("%s", line);
	free(line);
}
