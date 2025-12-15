#include "minishell.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
        size_t  len1 = ft_strlen(s1);
        size_t  len2 = ft_strlen(s2);
        char    *res = malloc(len1 + len2 + 1);
        if (!res)
                return (NULL);
        ft_memcpy(res, s1, len1);
        ft_memcpy(res + len1, s2, len2 + 1);
        return (res);
}

char    **ft_split(const char *s, char c)
{
        int             count = 1;
        for (int i = 0; s[i]; i++)
                if (s[i] == c)
                        count++;

        char    **arr = malloc(sizeof(char *) * (count + 1));
        if (!arr)
                return (NULL);

        int     i = 0;
        const char *start = s;
        for (int j = 0; ; j++)
        {
                if (s[j] == c || s[j] == '\0')
                {
                        size_t  len = s + j - start;
                        arr[i] = malloc(len + 1);
                        if (!arr[i])
                                return (NULL);
                        ft_memcpy(arr[i], start, len);
                        arr[i][len] = '\0';
                        i++;
                        if (s[j] == '\0')
                                break;
                        start = s + j + 1;
                }
        }
        arr[i] = NULL;
        return (arr);
}
