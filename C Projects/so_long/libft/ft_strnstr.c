/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:47 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/30 18:05:56 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	old_i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			old_i = i;
			while (haystack[old_i] == needle[j] && needle[j] && haystack[old_i]
				&& old_i < len)
			{
				j++;
				old_i++;
			}
			if (needle[j] == '\0')
				return ((char *)(&haystack[old_i - j]));
		}
		i++;
	}
	return (NULL);
}
