#include "philo.h"

long     ft_atoi(char *str)
{
        int     i = 0;
        int     nbr;
        int     result = 0;

        while (str[i])
        {
                nbr = str[i] - '0';
                result = (result * 10) + nbr;
                i++;
        }
        return (result);
}

void    error(char *str, int i)
{
        printf(str, i);
        exit(1);
}

long long       get_time_ms(void)
{
        struct  timeval tv;
        gettimeofday(&tv, NULL);
        return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void            print_msg(t_data *data, int id, const char *msg)
{
        pthread_mutex_lock(&data->print_mutex);
        printf("[%lld ms] Philosophe %d %s\n", get_time_ms() - data->start_time, id + 1, msg);
        pthread_mutex_unlock(&data->print_mutex);
}


