/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:04:02 by rfirat            #+#    #+#             */
/*   Updated: 2025/10/31 19:06:03 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dda(t_ray *ray, t_cub *cub)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (cub->player.x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - cub->player.x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (cub->player.y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - cub->player.y) * ray->deltadist_y;
	}
}

void	perform_dda(t_scene *s, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_x < 0 || ray->map_y >= s->map_height
			|| ray->map_x >= s->map_width)
			break ;
		else if (s->map_lines[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	calculate_line_height(t_ray *ray, t_cub *cub)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - cub->player.x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->wall_dist = (ray->map_y - cub->player.y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = cub->player.y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = cub->player.x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}
