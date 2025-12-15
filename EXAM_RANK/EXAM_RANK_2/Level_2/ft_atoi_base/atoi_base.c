int     convers(char c)
{
        if (c >= '0' && c <= '9')
                return (c - '0');

        else if (c >= 'a' && c <= 'f')
                return (c - 'a' + 10);

        else if (c >= 'A' && c <= 'F')
                return (c - 'A' + 10);

        return (-1);
}
int     ft_atoi_base(const char *str, int str_base)
{
        int     i;
        int     sign;
        int     value;
        int     result;

        i = 0;
        sign = 1;
        result = 0;

        if (str_base < 2 || str_base > 16)
                return (0);

        while (str[i] <= ' ')
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        sign = -1;
                i++;
        }

        while (str[i])
        {
                value = convers(str[i]);
                if (value < 0 || value >= str_base)
                        break;
                result = result * str_base + value;
                i++;
        }
        return (result * sign);
}
