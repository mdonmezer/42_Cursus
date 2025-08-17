/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:19 by mdonmeze          #+#    #+#             */
/*   Updated: 2024/11/15 23:49:16 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

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

static char	*get_next_word(char const **s, char c)
{
	char	*start;
	char	*word;
	int		len;

	while (**s == c)
		(*s)++;
	start = (char *)*s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ret = malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < words)
	{
		ret[i] = get_next_word(&s, c);
		if (!(ret[i]))
		{
			while (i-- > 0)
				free(ret[i]);
			free(ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
