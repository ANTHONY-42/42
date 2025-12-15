#include <unistd.h>

int main(int ac, char **av)
{
        if (ac == 3)
        {
                int     i;
                int     j;
                char    repeat[256] = {0};

                i = 0;

                while (av[1][i])
                {
                        if (repeat[av[1][i]] == 0)
                        {
                                write(1, &av[1][i], 1);
                                repeat[av[1][i]] = 1;
                        }
                        i++;
                }

                j = 0;
                while (av[2][j])
                {
                        if (repeat[av[2][j]] == 0)
                        {
                                write(1, &av[2][j], 1);
                                repeat[av[2][j]] = 1;
                        }
                        j++;
                }
        }
        write(1, "\n", 1);
        return (0);
}
