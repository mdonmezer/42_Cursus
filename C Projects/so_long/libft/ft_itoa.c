/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:42:14 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/25 21:59:49 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_itoa_p(char *dest, int *i, int n)
{
	if (n < 0)
	{
		dest[0] = '-';
		(*i)++;
		ft_itoa_p(dest, i, -n);
	}
	else if (n > 9)
	{
		ft_itoa_p(dest, i, n / 10);
		ft_itoa_p(dest, i, n % 10);
	}
	else
	{
		dest[*i] = n + '0';
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(sizeof(char) * (count_num(n) + 1));
	if (!c)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(c, "-2147483648", 12);
		return (c);
	}
	ft_itoa_p(c, &i, n);
	c[i] = '\0';
	return (c);
}
