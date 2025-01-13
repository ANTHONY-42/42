#include "get_next_line.h"

int read_state(const char *state_file)
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

    // Lire l'état actuel ou démarrer à zéro si le fichier n'existe pas
    if (!file_exists(state_file)) {
        line_num = 0;
    } else {
        line_num = read_state(state_file);
    }

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
            reset_state(state_file); // Réinitialiser si on atteint la fin
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
