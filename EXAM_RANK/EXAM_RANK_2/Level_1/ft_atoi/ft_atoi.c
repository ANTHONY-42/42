int     ft_atoi(const char *str)
{
        int     i = 0;
        int     neg = 1;
        int     result = 0;


        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
                        str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
                i++;

        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        neg = -1;
                i++;
        }

        while (str[i] >= '0' && str[i] <= '9')
        {
                result = result * 10 + (str[i] - '0');
                i++;
        }
        return (result * neg);
}
