/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:39:25 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/12/19 16:39:26 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unnbr(unsigned long u)
{
	int	i;

	i = 0;
	if (u <= 9)
		i += ft_putchar(u + '0');
	else
	{
		i += ft_unnbr(u / 10);
		i += ft_unnbr(u % 10);
	}
	return (i);
}
