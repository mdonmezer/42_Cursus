#include "libft.h"
#include <limits.h>

int ft_atoi(const char *str)
{
    int sign = 1;
    long result = 0;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
        if (result * sign > INT_MAX)
            return (-1);
        if (result * sign < INT_MIN)
            return (0);
    }
    return (result * sign);
}