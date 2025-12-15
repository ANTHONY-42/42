#include "list.h"
#include <stddef.h>

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
        int     tmp;
        int     sort;
        t_list  *start_lst;

        if (!lst)
                return (NULL);

        start_lst = lst;
        sort = 0;
        while (!sort)
        {
                sort = 1;
                lst = start_lst;
                while (lst->next != NULL)
                {
                        if (!cmp(lst->data, lst->next->data))
                        {
                                tmp = lst->data;
                                lst->data = lst->next->data;
                                lst->next->data = tmp;
                                sort = 0;
                        }
                        lst = lst->next;
                }
        }
        lst = start_lst;
        return (lst);
}
