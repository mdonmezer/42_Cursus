/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:20:00 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/01 23:03:00 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map_row(const char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
				|| line[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(const char *line)
{
	while (*line && ft_is_space((unsigned char)*line))
		line++;
	if (*line == '\0')
		return (0);
	if (is_identifier_line(line))
		return (0);
	return (is_valid_map_row(line));
}

int	append_map_line(t_scene *s, const char *line)
{
	char		**new_map;
	int			i;
	int			new_w;
	const char	*trimmed_line;

	new_map = (char **)gc_calloc(&s->gc, (s->map_height + 2), sizeof(char *));
	if (!new_map)
		return (-1);
	i = 0;
	while (++i < s->map_height)
		new_map[i] = s->map_lines[i];
	trimmed_line = line;
	while (*trimmed_line && ft_is_space((unsigned char)*trimmed_line))
		trimmed_line++;
	new_map[s->map_height] = gc_strdup(&s->gc, trimmed_line);
	if (!new_map[s->map_height])
		return (-1);
	s->map_lines = new_map;
	s->map_height += 1;
	new_w = (int)ft_strlen(trimmed_line);
	if (new_w > s->map_width)
		s->map_width = new_w;
	return (0);
}

static int	normalize_row(t_normalize_row_params *p)
{
	p->c = -1;
	while (++p->c < (int)ft_strlen(p->row) && p->c < p->s->map_width)
	{
		if (p->row[p->c] == ' ')
			p->newrow[p->c] = '1';
		else
			p->newrow[p->c] = p->row[p->c];
	}
	while (++p->c < p->s->map_width)
		p->newrow[p->c] = '1';
	p->newrow[p->s->map_width] = '\0';
	return (0);
}

int	normalize_map(t_scene *s)
{
	t_normalize_row_params	p;

	p.s = s;
	p.r = -1;
	while (++p.r < s->map_height)
	{
		p.row = s->map_lines[p.r];
		p.newrow = (char *)gc_malloc(&s->gc, (size_t)s->map_width + 1);
		if (!p.newrow)
			return (-1);
		if (normalize_row(&p) != 0)
			return (-1);
		s->map_lines[p.r] = p.newrow;
	}
	return (0);
}
