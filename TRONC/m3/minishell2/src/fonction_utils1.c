#include "minishell.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        size_t          i;
        char            *d;
        const char      *s;

        i = 0;
        d = (char *)dst;
        s = (const char *)src;
        if (!dst && !src)
        {
                return (NULL);
        }
        while (i < n)
        {
                d[i] = s[i];
                i++;
        }
        return (dst);
}

ssize_t ft_strlen(const char *s)
{
        ssize_t i       =       0;
        while (s[i])
                i++;
        return (i);
}

char    *ft_strdup(const char *s)
{
        size_t  len = ft_strlen(s);
        char    *dup = malloc(len + 1);
        if (!dup)
                return (NULL);
        ft_memcpy(dup, s, len + 1);
        return (dup);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i = 0;
        while (i < n && (s1[i] || s2[i]))
        {
                if ((unsigned char)s1[i] != (unsigned char)s2[i])
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                i++;
        }
        return (0);
}

char    *ft_strchr(const char *s, int c)
{
        while (*s)
        {
                if (*s == (char)c)
                        return ((char *)s);
                s++;
        }
        return (c == 0 ? (char *)s : NULL);
}
