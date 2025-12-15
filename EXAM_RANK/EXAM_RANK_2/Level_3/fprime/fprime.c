#include <stdlib.h>
#include <stdio.h>

void    fprime(int nb)
{
        int     mult;
        mult = 2;

        if (nb == 1)
        {
                printf("1");
                return;
        }

        while (nb >= mult)
        {
                if (nb % mult == 0)
                {
                        printf("%d", mult);
                        nb = nb / mult;
                        if (nb > 1)
                                printf("*");
                }
                        else
                                mult++;
        }
}

int main(int ac, char **av)
{
        if (ac == 2)
        {
                int     nb;
                nb = atoi(av[1]);

                if (nb > 0)
                        fprime(nb);
        }
        printf("\n");
        return (0);
}
