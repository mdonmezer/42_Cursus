/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:33:54 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/08 19:33:55 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_p(char *dest, int *i, int n)
{
	if (n == -2147483648)
	{
		ft_strlcpy(dest, "-2147483648", 12);
	}
	else if (n < 0)
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
	char *c;
	int i;

	i = 0;
	c = (char *)malloc(100);
	ft_itoa_p(c, &i, n);
	return (c);
}
