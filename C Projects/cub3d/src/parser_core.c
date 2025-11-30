/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:21:49 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/01 22:00:43 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cleanup_parse_failure(t_scene *scene)
{
	if (scene)
		free_scene(scene);
	return (-1);
}

int	parse_scene(const char *path, t_scene *out_scene)
{
	t_parsectx	ctx;
	int			stop;

	if (!out_scene)
		return (-1);
	scene_init(out_scene);
	if (read_lines_with_gnl(path, &ctx.lines, &ctx.line_count,
			&out_scene->gc) != 0)
		return (cleanup_parse_failure(out_scene));
	ctx.map_started = 0;
	ctx.i = 0;
	stop = 0;
	while (ctx.i < ctx.line_count && !stop)
	{
		ctx.line = ctx.lines[ctx.i];
		if (handle_line(&ctx, out_scene, &stop) != 0)
			return (cleanup_parse_failure(out_scene));
		ctx.i++;
	}
	if (finalize_scene(out_scene, &ctx) != 0)
		return (cleanup_parse_failure(out_scene));
	return (0);
}
