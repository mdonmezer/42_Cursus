/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:42:51 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/06/04 05:09:43 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	while (count--)
	{
		*ptr = (unsigned char) c;
		ptr++;
	}
	return (dest);
}
