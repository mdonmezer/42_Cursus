#include "libft.h"

int		ft_atoi(const char *str)
{
	int count = 0;
	int i = 0;
	int isaret = 1;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			isaret = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		count = (count * 10) + (str[i] - '0');
		i++;
	}
	return (count * isaret);
}
