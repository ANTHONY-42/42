#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putnbr(int nbr)
{
        if (nbr > 9)
                ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
}
int main(int ac, char **av)
{
        if (ac > 0)
        {
                int     i;
                i = 0;
                while (av[i + 1])
                        i++;
                ft_putnbr(i);
        }
        write(1, "\n", 1);
        return (0);
}
