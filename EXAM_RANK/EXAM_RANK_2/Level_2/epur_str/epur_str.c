#include <unistd.h>

int     main(int ac, char **av)
{
        if (ac == 2)
        {
                int     i;
                i = 0;

                while (av[1][i] <= ' ')
                        i++;

                while (av[1][i])
                {
                        if (av[1][i] <= ' ')
                        {
                                while (av[1][i] <= ' ')
                                {
                                        if (av[1][i] == '\0')
                                        {
                                                write(1, "\n", 1);
                                                return (0);
                                        }
                                        i++;
                                }
                                write(1, " ", 1);
                        }
                        write(1, &av[1][i], 1);
                        i++;
                }
        }
        write(1, "\n", 1);
        return (0);
}
