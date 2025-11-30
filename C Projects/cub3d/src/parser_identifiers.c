/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_identifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:38:11 by md                #+#    #+#             */
/*   Updated: 2025/10/31 18:51:55 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_texture_identifier(t_scene *scene, const char *line)
{
	const char	*trimmed;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "NO", 2) == 0 && !scene->no_path)
		scene->no_path = gc_strtrim(&scene->gc, skip_spaces(trimmed + 2));
	else if (ft_strncmp(trimmed, "SO", 2) == 0 && !scene->so_path)
		scene->so_path = gc_strtrim(&scene->gc, skip_spaces(trimmed + 2));
	else if (ft_strncmp(trimmed, "WE", 2) == 0 && !scene->we_path)
		scene->we_path = gc_strtrim(&scene->gc, skip_spaces(trimmed + 2));
	else if (ft_strncmp(trimmed, "EA", 2) == 0 && !scene->ea_path)
		scene->ea_path = gc_strtrim(&scene->gc, skip_spaces(trimmed + 2));
	else
		return (0);
	return (1);
}

static int	handle_color_identifier(t_scene *scene, const char *line)
{
	const char	*trimmed;
	const char	*color_str;

	trimmed = skip_spaces(line);
	if (ft_strncmp(trimmed, "F", 1) == 0
		&& ft_is_space((unsigned char)trimmed[1]) && scene->floor_color.r == -1)
	{
		color_str = skip_spaces(trimmed + 1);
		if (parse_rgb_triplet(color_str, &scene->floor_color) != 0)
			return (printf(ERR_PREFIX ERR_INVALID_FLOOR_COLOR), -1);
		return (1);
	}
	if (ft_strncmp(trimmed, "C", 1) == 0
		&& ft_is_space((unsigned char)trimmed[1])
		&& scene->ceiling_color.r == -1)
	{
		color_str = skip_spaces(trimmed + 1);
		if (parse_rgb_triplet(color_str, &scene->ceiling_color) != 0)
		{
			printf(ERR_PREFIX ERR_INVALID_CEILING_COLOR);
			return (-1);
		}
		return (1);
	}
	return (0);
}

int	is_identifier_line(const char *line)
{
	while (*line && ft_is_space((unsigned char)*line))
		line++;
	if ((ft_strncmp(line, "NO", 2) == 0 && ft_is_space((unsigned char)line[2]))
		|| (ft_strncmp(line, "SO", 2) == 0
			&& ft_is_space((unsigned char)line[2]))
		|| (ft_strncmp(line, "WE", 2) == 0
			&& ft_is_space((unsigned char)line[2]))
		|| (ft_strncmp(line, "EA", 2) == 0
			&& ft_is_space((unsigned char)line[2]))
		|| (ft_strncmp(line, "F", 1) == 0
			&& ft_is_space((unsigned char)line[1]))
		|| (ft_strncmp(line, "C", 1) == 0
			&& ft_is_space((unsigned char)line[1])))
		return (1);
	return (0);
}

const char	*skip_spaces(const char *p)
{
	while (*p && ft_is_space((unsigned char)*p))
		p++;
	return (p);
}

int	handle_identifier_line(t_scene *scene, const char *line)
{
	int	result;

	result = handle_texture_identifier(scene, line);
	if (result != 0)
	{
		if (result < 0)
			return (-1);
		return (0);
	}
	result = handle_color_identifier(scene, line);
	if (result < 0)
		return (-1);
	return (0);
}
