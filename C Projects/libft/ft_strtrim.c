/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:51 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/10/30 18:03:50 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	begin(char const *s1, char const *set, size_t *i)
{
	size_t	j;

	while (s1[*i] != '\0')
	{
		j = 0;
		while (s1[*i] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (s1[*i] != set[j])
			break ;
		(*i)++;
	}
}

void	end(char const *s1, char const *set, size_t *size)
{
	size_t	j;

	while (*size > 0)
	{
		j = 0;
		while (s1[*size] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (s1[*size] != set[j])
			break ;
		(*size)--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s1);
	i = 0;
	begin(s1, set, &i);
	end(s1, set, &size);
	return (ft_substr(s1, i, size - i + 1));
}
