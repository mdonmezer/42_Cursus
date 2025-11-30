/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:34:04 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:47 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_struct(t_cub *cub)
{
	cub->mlx.mlx_ptr = NULL;
	cub->mlx.win_ptr = NULL;
	cub->mlx.img_ptr = NULL;
	cub->mlx.img_data = NULL;
	cub->mlx.width = WIN_WIDTH;
	cub->mlx.height = WIN_HEIGHT;
	cub->mlx.bpp = 0;
	cub->mlx.line_length = 0;
	cub->mlx.endian = 0;
}

static int	setup_mlx_and_resources(t_cub *cub)
{
	cub->mlx.mlx_ptr = mlx_init();
	if (!cub->mlx.mlx_ptr)
	{
		printf(ERR_PREFIX ERR_FAILED_INIT_MLX);
		return (-1);
	}
	cub->mlx.win_ptr = mlx_new_window(cub->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Cub3D");
	if (!cub->mlx.win_ptr)
	{
		printf(ERR_PREFIX ERR_FAILED_CREATE_WINDOW);
		return (-1);
	}
	cub->mlx.img_ptr = mlx_new_image(cub->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!cub->mlx.img_ptr)
	{
		printf(ERR_PREFIX ERR_FAILED_CREATE_IMAGE);
		return (-1);
	}
	cub->mlx.img_data = mlx_get_data_addr(cub->mlx.img_ptr, &cub->mlx.bpp,
			&cub->mlx.line_length, &cub->mlx.endian);
	return (0);
}

int	init_mlx_and_start(t_cub *cub)
{
	if (setup_mlx_and_resources(cub) != 0)
		return (-1);
	if (load_textures(cub) != 0)
	{
		printf(ERR_PREFIX ERR_FAILED_LOAD_TEXTURES);
		return (-1);
	}
	cub->keys = (t_keys){0};
	mlx_hook(cub->mlx.win_ptr, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx.win_ptr, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->mlx.win_ptr, 4, 1L << 2, mouse_press, cub);
	mlx_hook(cub->mlx.win_ptr, 5, 1L << 3, mouse_release, cub);
	mlx_hook(cub->mlx.win_ptr, 6, 1L << 6, mouse_hook, cub);
	mlx_hook(cub->mlx.win_ptr, 12, 0, expose_hook, cub);
	mlx_hook(cub->mlx.win_ptr, 17, 0, close_window, cub);
	mlx_loop_hook(cub->mlx.mlx_ptr, game_loop, cub);
	render_frame(cub);
	mlx_loop(cub->mlx.mlx_ptr);
	cleanup_mlx_resources(cub);
	return (0);
}

void	cleanup_mlx_resources(t_cub *cub)
{
	int	i;

	if (cub->scene_ref && cub->scene_ref->gc.head)
	{
		gc_free_all(&cub->scene_ref->gc);
	}
	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].img_ptr)
			mlx_destroy_image(cub->mlx.mlx_ptr, cub->textures[i].img_ptr);
		i++;
	}
	if (cub->mlx.img_ptr)
		mlx_destroy_image(cub->mlx.mlx_ptr, cub->mlx.img_ptr);
	if (cub->mlx.win_ptr)
		mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
	if (cub->mlx.mlx_ptr)
	{
		mlx_destroy_display(cub->mlx.mlx_ptr);
		free(cub->mlx.mlx_ptr);
	}
}
