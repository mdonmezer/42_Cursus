/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:54 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/22 22:01:00 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	s_len;
	char	*dest;

	s_len = ft_strlen(s);
	if ((start >= s_len) || !s)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dest = malloc((sizeof(char)) * (len + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < len)
	{
		dest[j] = s[start];
		j++;
		start++;
	}
	dest[j] = '\0';
	return (dest);
}
