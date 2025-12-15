#include <stdlib.h>

int     a_sep(char c)
{
        if (c <= ' ')
                return (1);
        return (0);
}

int     count_word(char *str)
{
        int     i = 0;
        int     count = 0;
        int     in_word = 0;

        while (str[i])
        {
                if ((!a_sep(str[i])) && in_word == 0)
                {
                        in_word = 1;
                        count++;
                }
                else if (a_sep(str[i]))
                        in_word = 0;
                i++;
        }
        return (count);
}

char    *word_dup(char *start, char *end)
{
        int     i = 0;
        int     len = end - start;
        char    *word;

        word = malloc(sizeof(char) * (len + 1));
        if (!word)
                return (NULL);

        while (i < len)
        {
                word[i] = start[i];
                i++;
        }
        word[i] = '\0';
        return (word);
}

char    **ft_split(char *str)
{
        int     i = 0;
        int     j = 0;
        char    **words;
        char    *start;
        char    *end;

        words = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
        if (!words)
                return (NULL);

        while (str[i])
        {
                while (str[i] && a_sep(str[i]))
                        i++;
                if (str[i])
                {
                        start = &str[i];
                        while (str[i] && (!a_sep(str[i])))
                                i++;
                        end = &str[i];
                        words[j++] = word_dup(start, end);
                }
        }
        words[j] = NULL;
        return (words);
}
