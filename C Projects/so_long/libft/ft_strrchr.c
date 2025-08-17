/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:49 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/22 19:43:50 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	while (len + 1 > 0)
	{
		if (str[len] == (char)c)
			return ((char *)(str + len));
		len--;
	}
	if (c == 0)
		return ((char *)(str + len));
	return (NULL);
}
