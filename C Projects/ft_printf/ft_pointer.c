/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:45 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/12/19 16:38:46 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long ptr)
{
	int	i;

	i = 0;
	if (ptr == (unsigned long) NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	if (ptr >= 16)
		i += ft_pointer(ptr / 16);
	else
		i += ft_putstr("0x");
	if ((ptr % 16) < 10)
		i += ft_putchar((ptr % 16) + '0');
	else
		i += ft_putchar((ptr % 16) + 87);
	return (i);
}
