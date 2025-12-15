#include <unistd.h>

int     after_space(char c)
{
        if (c <= ' ')
                return (1);
        return (0);
}

int     lowercase(char c)
{
        if (c >= 'a' && c <= 'z')
                return (1);
        return (0);
}

int     uppercase(char c)
{
        if (c >= 'A' && c <= 'Z')
                return (1);
        return (0);
}

int     main(int ac, char **av)
{
        if (ac > 1)
        {
                int     i;
                int     j;
                j = 1;
                while (av[j])
                {
                        i = 0;
                        while (av[j][i])
                        {
                                if (i == 0 && lowercase(av[j][i]))
                                        av[j][i] = av[j][i] - 32;

                                else if (after_space(av[j][i - 1]) && lowercase(av[j][i]))
                                        av[j][i] = av[j][i] - 32;

                                else if (!after_space(av[j][i - 1]) && uppercase(av[j][i]))
                                        av[j][i] = av[j][i] + 32;
                                write(1, &av[j][i], 1);
                                i++;
                        }
                        write(1, "\n", 1);
                        j++;
                }
        }
        else
                write(1, "\n", 1);
        return (0);
}
