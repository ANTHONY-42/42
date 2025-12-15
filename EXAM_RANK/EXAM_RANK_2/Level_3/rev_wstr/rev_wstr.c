#include <unistd.h>

int main(int ac, char **av)
{
        if (ac == 2)
        {
                int     i = 0;
                int     j = 0;

                while (av[1][j])
                        j++;
                j--;
                while (j > 0)
                {
                        while (av[1][j] <= ' ')
                                j--;
                        while (av[1][j] > ' ')
                                j--;
                        i = j + 1;
                        while (av[1][i] > ' ')
                        {
                                write(1, &av[1][i], 1);
                                i++;
                        }
                        if (j > 0)
                                write(1, " ", 1);
                }
        }
        write(1, "\n", 1);
        return (0);
}
