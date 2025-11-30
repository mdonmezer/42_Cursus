/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_grid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:25:00 by rfirat            #+#    #+#             */
/*   Updated: 2025/08/29 00:29:06 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map_into_grid(t_scene *s, t_mapctx *ctx)
{
	int	r;
	int	c;

	r = 1;
	while (r <= ctx->height)
	{
		c = 1;
		while (c <= ctx->width)
		{
			ctx->grid[r][c] = s->map_lines[r - 1][c - 1];
			c++;
		}
		r++;
	}
}

static int	allocate_grid_rows(t_scene *s, t_mapctx *ctx)
{
	int	r;

	r = 0;
	while (r < ctx->height + 2)
	{
		ctx->grid[r] = (char *)gc_malloc(&s->gc, ctx->width + 2);
		if (!ctx->grid[r])
			return (-1);
		r++;
	}
	return (0);
}

static void	initialize_grid_spaces(t_mapctx *ctx)
{
	int	r;
	int	c;

	r = 0;
	while (r < ctx->height + 2)
	{
		c = 0;
		while (c < ctx->width + 2)
		{
			ctx->grid[r][c] = ' ';
			c++;
		}
		r++;
	}
}

int	build_padded_grid(t_scene *s, t_mapctx *ctx)
{
	ctx->height = s->map_height;
	ctx->width = s->map_width;
	ctx->grid = (char **)gc_malloc(&s->gc, sizeof(char *) * (ctx->height + 2));
	if (!ctx->grid)
		return (-1);
	if (allocate_grid_rows(s, ctx) != 0)
		return (-1);
	initialize_grid_spaces(ctx);
	return (0);
}
