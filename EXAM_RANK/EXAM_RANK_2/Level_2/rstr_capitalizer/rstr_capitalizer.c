#include <unistd.h>

char    *str_lowercase(char *str)
{
        int     i;
        i = 0;

        while (str[i])
        {
                if (str[i] >= 'A' && str[i] <= 'Z')
                        str[i] += 32;
                i++;
        }
        return (str);
}

int main(int ac, char **av)
{
        if (ac > 1)
        {
                int     i;
                int     j;

                j = 1;
                while (av[j])
                {
                        i = 0;
                        av[j] = str_lowercase(av[j]);
                        while (av[j][i])
                        {
                                if ((av[j][i + 1] == ' ' || av[j][i + 1] == '\0') &&
                                                (av[j][i] >= 'a' && av[j][i] <= 'z'))
                                {
                                        av[j][i] -= 32;
                                }
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
