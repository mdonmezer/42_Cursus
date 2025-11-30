/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:12:33 by rfirat            #+#    #+#             */
/*   Updated: 2025/10/31 16:01:46 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	init_raycasting_info(int x, t_ray *ray, t_cub *cub)
{
	double	base_dir_x;
	double	base_dir_y;
	double	plane_x;
	double	plane_y;

	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	base_dir_x = cos(cub->player.angle);
	base_dir_y = sin(cub->player.angle);
	plane_x = -sin(cub->player.angle) * FOV_PLANE;
	plane_y = cos(cub->player.angle) * FOV_PLANE;
	ray->dir_x = base_dir_x + plane_x * ray->camera_x;
	ray->dir_y = base_dir_y + plane_y * ray->camera_x;
	ray->map_x = (int)cub->player.x;
	ray->map_y = (int)cub->player.y;
	if (ray->dir_x != 0)
		ray->deltadist_x = fabs(1 / ray->dir_x);
	else
		ray->deltadist_x = 1e30;
	if (ray->dir_y != 0)
		ray->deltadist_y = fabs(1 / ray->dir_y);
	else
		ray->deltadist_y = 1e30;
}

static int	select_texture(t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		return (TEXTURE_EAST);
	else if (ray->side == 0 && ray->dir_x < 0)
		return (TEXTURE_WEST);
	else if (ray->side == 1 && ray->dir_y > 0)
		return (TEXTURE_SOUTH);
	else
		return (TEXTURE_NORTH);
}

static void	draw_vertical_line(t_cub *cub, int x, t_ray *ray)
{
	int	end_y;
	int	text_id;
	int	tex_x;

	text_id = select_texture(ray);
	tex_x = (int)(ray->wall_x * (double)cub->textures[text_id].width);
	if (ray->side == 0 && ray->dir_x < 0)
		tex_x = cub->textures[text_id].width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		tex_x = cub->textures[text_id].width - tex_x - 1;
	end_y = draw_column_texture(&(t_dct_params){cub, x, ray, text_id, tex_x},
			cub);
	draw_column_floor(cub, x, end_y);
}

void	raycasting(t_cub *cub)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_raycasting_info(x, &ray, cub);
		set_dda(&ray, cub);
		perform_dda(cub->scene_ref, &ray);
		calculate_line_height(&ray, cub);
		draw_vertical_line(cub, x, &ray);
		x++;
	}
}

void	render_frame(t_cub *cub)
{
	clear_image(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr,
		cub->mlx.img_ptr, 0, 0);
}
