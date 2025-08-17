/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:30:55 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/03/24 00:47:42 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	check(char **res, size_t i)
{
	if (!res[i])
	{
		while (i > 0)
			free(res[--i]);
		free(res);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**list;
	size_t		count;
	const char	*begin;

	count = 0;
	list = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!list)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			begin = s;
			while (*s && *s != c)
				s++;
			list[count] = ft_substr(begin, 0, s - begin);
			if (!check(list, count))
				return (NULL);
			count++;
		}
	}
	list[count] = NULL;
	return (list);
}
