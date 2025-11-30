/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 00:52:03 by rfirat            #+#    #+#             */
/*   Updated: 2025/08/26 00:53:35 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	expect_char_advance(const char **ps, char expected)
{
	const char	*s;

	s = *ps;
	if (*s != expected)
		return (-1);
	s++;
	*ps = s;
	return (0);
}

int	parse_rgb_component(const char **ps, long *out_val)
{
	const char	*s;
	long		v;
	int			ok;

	s = *ps;
	while (*s && ft_is_space((unsigned char)*s))
		s++;
	v = ft_atoi_pos(s, &ok);
	if (!ok || v < 0 || v > 255)
		return (-1);
	while (*s && ft_is_digit((unsigned char)*s))
		s++;
	*out_val = v;
	*ps = s;
	return (0);
}

int	parse_rgb_triplet(const char *s, t_rgb *out)
{
	long	r;
	long	g;
	long	b;

	if (parse_rgb_component(&s, &r) != 0)
		return (-1);
	if (expect_char_advance(&s, ',') != 0)
		return (-1);
	if (parse_rgb_component(&s, &g) != 0)
		return (-1);
	if (expect_char_advance(&s, ',') != 0)
		return (-1);
	if (parse_rgb_component(&s, &b) != 0)
		return (-1);
	while (*s && ft_is_space((unsigned char)*s))
		s++;
	if (*s != '\0')
		return (-1);
	out->r = (int)r;
	out->g = (int)g;
	out->b = (int)b;
	return (0);
}
