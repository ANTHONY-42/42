#include <stdlib.h>

int     *ft_range(int start, int end)
{
        int     i = 0;
        int     reverse = 0;
        int     size;
        int     *tab;

        if (start > end)
                reverse = 1;

        size = (start <= end) ? (end - start + 1) : (start - end + 1);
        tab = malloc((size) * sizeof(int));
        if (!tab)
                return (NULL);

        while (i < size)
        {
                tab[i++] = start;
                if (!reverse)
                        start++;
                else
                        start--;
        }
        return (tab);
}
