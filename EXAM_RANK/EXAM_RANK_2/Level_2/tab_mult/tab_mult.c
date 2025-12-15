#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
        if (nb > 9)
                ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
}

int     ft_atoi(char    *str)
{
        int     i = 0;
        int     result = 0;

        while (str[i] >= '0' && str[i] <= '9')
        {
                result = result * 10 + (str[i] - '0');
                i++;
        }
        return (result);
}

int main(int ac, char **av)
{
        if (ac == 2)
        {
                int     nb;
                int     mult;
                int     result;

                nb = 1;
                mult = ft_atoi(av[1]);
                while (nb < 10)
                {
                        result = mult * nb;
                        ft_putnbr(nb);
                        write(1, " x ", 3);
                        ft_putnbr(mult);
                        write(1, " = ", 3);
                        ft_putnbr(result);
                        write(1, "\n", 1);
                        nb++;
                }

        }
        else
                write(1, "\n", 1);
        return (0);
}

