/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:12:33 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/01 21:18:01 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_line_empty(const char *line)
{
	while (line && *line)
	{
		if (!ft_is_space((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}

static int	control_identifier_map_line(t_parsectx *ctx, t_scene *scene)
{
	if (is_identifier_line(ctx->line))
	{
		if (ctx->map_started)
		{
			printf(ERR_PREFIX "Identifier found after map content\n");
			return (-1);
		}
		return (handle_identifier_line(scene, ctx->line));
	}
	if (is_map_line(ctx->line))
	{
		ctx->map_started = 1;
		return (append_map_line(scene, ctx->line));
	}
	printf(ERR_PREFIX "Invalid line in file: %s\n", ctx->line);
	return (-1);
}

int	handle_line(t_parsectx *ctx, t_scene *scene, int *stop)
{
	int	j;

	if (is_line_empty(ctx->line))
	{
		if (ctx->map_started)
		{
			j = ctx->i + 1;
			while (j < ctx->line_count)
			{
				if (!is_line_empty(ctx->lines[j]))
				{
					printf(ERR_PREFIX ERR_EMPTY_LINE_INSIDE_MAP);
					return (-1);
				}
				j++;
			}
			*stop = 1;
		}
		return (0);
	}
	return (control_identifier_map_line(ctx, scene));
}

int	finalize_scene(t_scene *scene, t_parsectx *ctx)
{
	if (!scene->no_path || !scene->so_path || !scene->we_path
		|| !scene->ea_path)
	{
		printf(ERR_PREFIX ERR_MISSING_TEXTURE_PATHS);
		return (-1);
	}
	if (scene->floor_color.r < 0 || scene->ceiling_color.r < 0)
	{
		printf(ERR_PREFIX ERR_MISSING_FLOOR_OR_CEILING);
		return (-1);
	}
	if (scene->map_height == 0)
	{
		printf(ERR_PREFIX ERR_MISSING_MAP_CONTENT);
		return (-1);
	}
	if (validate_space_adjancency(scene) != 0)
		return (-1);
	if (normalize_map(scene) != 0)
		return (-1);
	if (validate_map_content(scene, ctx->err, sizeof(ctx->err)) != 0)
		return (-1);
	return (0);
}
