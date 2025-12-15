#include <stdio.h>

typedef struct s_point
{
    int x;
    int y;
} t_point;

void fill(char **tab, t_point size, int x, int y, char target)
{
    // Vérifier si on est en dehors des limites
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return;

    // Vérifier si la case actuelle est différente du caractère cible
    if (tab[y][x] != target)
        return;

    // Remplacer par 'F'
    tab[y][x] = 'F';

    // Récursion pour remplir les voisins (haut, bas, gauche, droite)
    fill(tab, size, x + 1, y, target);
    fill(tab, size, x - 1, y, target);
    fill(tab, size, x, y + 1, target);
    fill(tab, size, x, y - 1, target);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x]; // Caractère à remplacer
    if (target != 'F') // Évite de remplir une zone déjà remplie
        fill(tab, size, begin.x, begin.y, target);
}
