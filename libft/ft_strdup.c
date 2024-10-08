/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:33:57 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/08 19:33:58 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int i;
	int len;
	char *dest;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc((len + 1) * sizeof(char));
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
