/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:07:21 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:30 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_neighbor(t_process_neighbor_params *p)
{
	if (p->r < 0 || p->r > p->ctx->height + 1 || p->c < 0
		|| p->c > p->ctx->width + 1)
		return (0);
	if (p->ctx->grid[p->r][p->c] == ' ')
		return (-1);
	if (p->r >= 1 && p->r <= p->ctx->height && p->c >= 1
		&& p->c <= p->ctx->width)
	{
		if (is_walkable(p->ctx->grid[p->r][p->c])
			&& p->ctx->grid[p->r][p->c] != 'V')
		{
			p->stack[(*p->stack_top)++] = p->r;
			p->stack[(*p->stack_top)++] = p->c;
			p->ctx->grid[p->r][p->c] = 'V';
		}
	}
	return (0);
}

static int	init_floodfill_state(t_flood_init_params *p)
{
	int	*stack;

	(*p->dr)[0] = -1;
	(*p->dr)[1] = 1;
	(*p->dr)[2] = 0;
	(*p->dr)[3] = 0;
	(*p->dc)[0] = 0;
	(*p->dc)[1] = 0;
	(*p->dc)[2] = -1;
	(*p->dc)[3] = 1;
	stack = (int *)gc_malloc(&p->s->gc, (size_t)((p->ctx->height + 2)
				* (p->ctx->width + 2) * 2));
	if (!stack)
		return (-1);
	*p->out_stack_top = 0;
	stack[(*p->out_stack_top)++] = p->sr;
	stack[(*p->out_stack_top)++] = p->sc;
	p->ctx->grid[p->sr][p->sc] = 'V';
	*p->out_stack = stack;
	return (0);
}

static int	floodfill_from(t_scene *s, t_mapctx *ctx, int sr, int sc)
{
	int	*stack;
	int	dr[4];
	int	dc[4];
	int	stack_top;
	int	d;

	if (init_floodfill_state(&(t_flood_init_params){s, ctx, sr, sc,
			&stack, &stack_top, &dr, &dc}) != 0)
		return (-1);
	while (stack_top > 0)
	{
		sc = stack[--stack_top];
		sr = stack[--stack_top];
		d = 0;
		while (d < 4)
		{
			if (process_neighbor(&(t_process_neighbor_params)
					{ctx, stack, &stack_top, sr + dr[d], sc + dc[d]}) != 0)
				return (-1);
			d++;
		}
	}
	return (0);
}

static int	check_closed_floodfill(t_scene *s, t_mapctx *ctx)
{
	int	r;
	int	c;

	r = 1;
	while (r <= ctx->height)
	{
		c = 1;
		while (c <= ctx->width)
		{
			if (s->map_lines[r - 1][c - 1] == 'N' || s->map_lines[r - 1][c
				- 1] == 'S' || s->map_lines[r - 1][c - 1] == 'E'
				|| s->map_lines[r - 1][c - 1] == 'W')
			{
				if (floodfill_from(s, ctx, r, c) != 0)
					return (-1);
				return (0);
			}
			c++;
		}
		r++;
	}
	return (-1);
}

int	validate_map_content(t_scene *s, char *errbuf, size_t errcap)
{
	t_mapctx	ctx;

	(void)errcap;
	init_mapctx(&ctx, s);
	errbuf[0] = '\0';
	if (s->map_height <= 2 || s->map_width <= 2)
	{
		printf(ERR_PREFIX "map too small\n");
		return (-1);
	}
	if (validate_chars_and_player(s) != 0)
		return (-1);
	if (build_padded_grid(s, &ctx) != 0)
		return (-1);
	copy_map_into_grid(s, &ctx);
	if (check_closed_floodfill(s, &ctx) != 0)
	{
		printf(ERR_PREFIX "map not closed (flood fill)\n");
		return (-1);
	}
	return (0);
}
