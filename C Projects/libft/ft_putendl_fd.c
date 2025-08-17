/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:42:55 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/22 19:42:56 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			write (fd, &str[i], 1);
			i++;
		}
	}
	write(fd, "\n", 1);
}
