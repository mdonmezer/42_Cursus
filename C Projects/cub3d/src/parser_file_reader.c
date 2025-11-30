/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_reader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:22:40 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:33 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd);

void	trim_newline(char *line)
{
	int	l;

	l = 0;
	while (line[l] && line[l] != '\n')
		l++;
	if (line[l] == '\n')
		line[l] = '\0';
}

static int	grow_line_array(t_line_params *p)
{
	char	**newarr;
	int		j;

	p->cap *= 2;
	newarr = (char **)gc_malloc(p->gc, sizeof(char *) * p->cap);
	if (!newarr)
		return (-1);
	j = 0;
	while (j < *p->count)
	{
		newarr[j] = (*p->arr)[j];
		j++;
	}
	*p->arr = newarr;
	return (0);
}

static int	add_line_to_array(t_line_params *p, char *line)
{
	if (*p->count >= p->cap)
	{
		if (grow_line_array(p) != 0)
		{
			free(line);
			return (-1);
		}
	}
	trim_newline(line);
	if (gc_register(p->gc, line) != 0)
	{
		free(line);
		return (-1);
	}
	(*p->arr)[*p->count] = line;
	(*p->count)++;
	return (0);
}

int	read_lines_from_fd(int fd, t_line_params *p)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (add_line_to_array(p, line) != 0)
			return (-1);
	}
	return (0);
}

int	init_line_params(t_line_params *p, t_gc *gc, char ***arr,
		int *count)
{
	p->cap = 64;
	*arr = (char **)gc_malloc(gc, sizeof(char *) * p->cap);
	if (!*arr)
		return (-1);
	*count = 0;
	p->arr = arr;
	p->count = count;
	p->gc = gc;
	return (0);
}
