/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:22:40 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:10:16 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi_pos(const char *s, int *ok)
{
	long	val;
	int		read_any;

	val = 0;
	read_any = 0;
	if (ok)
		*ok = 0;
	if (!s || *s == '\0')
		return (0);
	while (ft_is_space((unsigned char)*s))
		s++;
	while (*s && ft_is_digit((unsigned char)*s))
	{
		read_any = 1;
		val = val * 10 + (*s - '0');
		s++;
		if (val > 2147483647)
			break ;
	}
	if (ok && read_any)
		*ok = 1;
	return (val);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*gc_strtrim(t_gc *gc, const char *s)
{
	const char	*start;
	const char	*end;
	size_t		len;
	char		*out;
	size_t		i;

	if (!s)
		return (NULL);
	start = s;
	while (*start && ft_is_space((unsigned char)*start))
		start++;
	end = start + ft_strlen(start);
	while (end > start && ft_is_space((unsigned char)*(end - 1)))
		end--;
	len = (size_t)(end - start);
	out = (char *)gc_malloc(gc, len + 1);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len)
		out[i] = start[i];
	out[len] = '\0';
	return (out);
}
