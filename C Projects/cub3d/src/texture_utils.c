/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:34:04 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:25 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_one_texture(t_cub *cub, int tid, const char *path,
		const char *err_fmt)
{
	int	w;
	int	h;

	cub->textures[tid].img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx_ptr,
			(char *)path, &w, &h);
	if (!cub->textures[tid].img_ptr)
	{
		printf(ERR_PREFIX);
		printf(err_fmt, path);
		return (-1);
	}
	cub->textures[tid].width = w;
	cub->textures[tid].height = h;
	cub->textures[tid].img_data = mlx_get_data_addr(cub->textures[tid].img_ptr,
			&cub->textures[tid].bpp, &cub->textures[tid].line_length,
			&cub->textures[tid].endian);
	return (0);
}

int	load_textures(t_cub *cub)
{
	if (load_one_texture(cub, TEXTURE_NORTH, cub->scene_ref->no_path,
			ERR_FAILED_LOAD_NORTH_FMT) != 0)
		return (-1);
	if (load_one_texture(cub, TEXTURE_SOUTH, cub->scene_ref->so_path,
			ERR_FAILED_LOAD_SOUTH_FMT) != 0)
		return (-1);
	if (load_one_texture(cub, TEXTURE_EAST, cub->scene_ref->ea_path,
			ERR_FAILED_LOAD_EAST_FMT) != 0)
		return (-1);
	if (load_one_texture(cub, TEXTURE_WEST, cub->scene_ref->we_path,
			ERR_FAILED_LOAD_WEST_FMT) != 0)
		return (-1);
	return (0);
}

int	get_texture_pixel(t_cub *cub, int texture_id, int x, int y)
{
	int	*data;
	int	offset;

	if (x < 0 || x >= cub->textures[texture_id].width || y < 0
		|| y >= cub->textures[texture_id].height)
		return (0);
	data = (int *)cub->textures[texture_id].img_data;
	offset = y * cub->textures[texture_id].line_length / 4 + x;
	return (data[offset]);
}
