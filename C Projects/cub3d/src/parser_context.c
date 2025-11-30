/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:23:18 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/01 22:08:00 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_walkable(char t)
{
	if (t == '0' || t == 'N' || t == 'S' || t == 'E' || t == 'W')
		return (1);
	return (0);
}

void	init_mapctx(t_mapctx *ctx, t_scene *s)
{
	ctx->height = 0;
	ctx->width = 0;
	ctx->h = 0;
	ctx->i = 0;
	ctx->player_count = 0;
	ctx->c = '\0';
	ctx->grid = NULL;
	ctx->row = 0;
	ctx->col = 0;
	ctx->lenrow = 0;
	ctx->rr = 0;
	ctx->tile = '\0';
	ctx->scene = s;
}
