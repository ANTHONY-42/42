#include "get_next_line.h"

static char	*machine(int fd, char *buffer, char **trace, char *line)
{
	*trace = extract_trace(fd, buffer, *trace);
	free(buffer);
	buffer = NULL;
	if (!*trace)
		return (NULL);
	line = extract_line(*trace);
	*trace = maj_trace(*trace);
	return (line);
}

static char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*trace;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	if (!trace)
	{
		trace = malloc(1);
		if (!trace)
		{
			free(buffer);
			return (NULL);
		}
		trace[0] = '\0';
	}
	line = machine(fd, buffer, &trace, line);
	return (line);
}



// Fonction pour lire l'état de progression
int	read_state(const char *state_file)
{
    FILE *file = fopen(state_file, "r");
    int line_num = 0;

    if (file)
    {
        fscanf(file, "%d", &line_num);
        fclose(file);
    }

    return line_num;
}

// Fonction pour sauvegarder l'état de progression
void save_state(const char *state_file, int line_num)
{
    FILE *file = fopen(state_file, "w");

    if (file)
    {
        fprintf(file, "%d", line_num);
        fclose(file);
    }
}

int main()
{
    const char *state_file = "state.txt";
    int fd;
    char *line;
    int line_num;

    // Lire l'état actuel
    line_num = read_state(state_file);

    fd = open("texte.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Erreur open(fd)\n");
        return (1);
    }

    // Lire les lignes jusqu'à atteindre la bonne
    for (int i = 0; i <= line_num; i++)
    {
        line = get_next_line(fd);
        if (!line)
        {
            printf("Fin du fichier ou erreur.\n");
            close(fd);
            return (0);
        }

        if (i == line_num)
        {
            printf("%s", line); // Afficher la ligne actuelle
            free(line);
        }
        else
        {
            free(line); // Libérer les lignes précédentes
        }
    }

    // Sauvegarder l'état pour la prochaine exécution
    save_state(state_file, line_num + 1);

    close(fd);
    return (0);
}

/*
int main()
{
	int	fd;
	char	*line;

	fd = open("teste2.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erreur open(fd)");
		return (1);
	}

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		close(fd);
		return (0);
	}
}*/
