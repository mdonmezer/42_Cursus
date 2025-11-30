/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:34:04 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:10:54 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_column_ceiling(t_dct_params *p, t_cub *cub)
{
	int	y;
	int	ceiling_color;

	y = 0;
	while (y < p->ray->draw_start)
	{
		if (y >= 0 && p->x >= 0 && p->x < WIN_WIDTH)
		{
			ceiling_color = (cub->scene_ref->ceiling_color.r << 16)
				| (cub->scene_ref->ceiling_color.g << 8)
				| cub->scene_ref->ceiling_color.b;
			*(int *)(p->cub->mlx.img_data + (y * p->cub->mlx.line_length + p->x
						* (p->cub->mlx.bpp / 8))) = ceiling_color;
		}
		y++;
	}
}

int	draw_textured_wall_with_params(t_tw_params *p)
{
	int	y;
	int	tex_y;
	int	color;

	y = p->draw_start;
	while (y < p->draw_end)
	{
		if (y >= 0 && p->x >= 0 && p->x < WIN_WIDTH)
		{
			tex_y = (int)p->tex_pos & (p->cub->textures[p->texture_id].height
					- 1);
			p->tex_pos += p->step;
			color = get_texture_pixel(p->cub, p->texture_id, p->tex_x, tex_y);
			*(int *)(p->cub->mlx.img_data + (y * p->cub->mlx.line_length + p->x
						* (p->cub->mlx.bpp / 8))) = color;
		}
		y++;
	}
	return (y);
}

int	draw_column_texture(t_dct_params *p, t_cub *cub)
{
	t_vline		v;
	t_tw_params	params;

	v.texture_id = p->texture_id;
	v.tex_x = p->tex_x;
	draw_column_ceiling(p, cub);
	v.step = 1.0 * cub->textures[v.texture_id].height / p->ray->line_height;
	v.tex_pos = (p->ray->draw_start - WIN_HEIGHT / 2 + p->ray->line_height / 2)
		* v.step;
	{
		params = (t_tw_params){cub, p->x, v.texture_id, v.tex_x, v.step,
			v.tex_pos, p->ray->draw_start, p->ray->draw_end};
		v.y = draw_textured_wall_with_params(&params);
	}
	return (v.y);
}

void	draw_column_floor(t_cub *cub, int x, int start_y)
{
	int	y;
	int	floor_color;

	y = start_y;
	while (y < WIN_HEIGHT)
	{
		if (y >= 0 && x >= 0 && x < WIN_WIDTH)
		{
			floor_color = (cub->scene_ref->floor_color.r << 16)
				| (cub->scene_ref->floor_color.g << 8)
				| cub->scene_ref->floor_color.b;
			*(int *)(cub->mlx.img_data + (y * cub->mlx.line_length + x
						* (cub->mlx.bpp / 8))) = floor_color;
		}
		y++;
	}
}

void	clear_image(t_cub *cub)
{
	int	x;
	int	y;
	int	ceiling_color;

	ceiling_color = (cub->scene_ref->ceiling_color.r << 16)
		| (cub->scene_ref->ceiling_color.g << 8)
		| cub->scene_ref->ceiling_color.b;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			*(int *)(cub->mlx.img_data + (y * cub->mlx.line_length + x
						* (cub->mlx.bpp / 8))) = ceiling_color;
			x++;
		}
		y++;
	}
}
