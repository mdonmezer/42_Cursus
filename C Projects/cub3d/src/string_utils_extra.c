/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:26:44 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:15 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strendswith(const char *s, const char *suffix)
{
	size_t	s_len;
	size_t	suf_len;

	if (!s || !suffix)
		return (0);
	s_len = ft_strlen(s);
	suf_len = ft_strlen(suffix);
	if (s_len < suf_len)
		return (0);
	while (suf_len > 0)
	{
		if (s[s_len - 1] != suffix[suf_len - 1])
			return (0);
		s_len--;
		suf_len--;
	}
	return (1);
}

const char	*ft_basename(const char *path)
{
	const char	*p;
	const char	*last;

	if (!path)
		return (path);
	p = path;
	last = path;
	while (*p)
	{
		if (*p == '/')
			last = p + 1;
		p++;
	}
	return (last);
}
