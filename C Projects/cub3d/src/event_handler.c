/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:34:04 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:10:58 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == 65307)
	{
		mlx_loop_end(cub->mlx.mlx_ptr);
		return (0);
	}
	else if (keycode == 119)
		cub->keys.w = 1;
	else if (keycode == 115)
		cub->keys.s = 1;
	else if (keycode == 100)
		cub->keys.a = 1;
	else if (keycode == 97)
		cub->keys.d = 1;
	else if (keycode == 65363)
		cub->keys.left = 1;
	else if (keycode == 65361)
		cub->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 119)
		cub->keys.w = 0;
	else if (keycode == 115)
		cub->keys.s = 0;
	else if (keycode == 100)
		cub->keys.a = 0;
	else if (keycode == 97)
		cub->keys.d = 0;
	else if (keycode == 65363)
		cub->keys.left = 0;
	else if (keycode == 65361)
		cub->keys.right = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_cub *cub)
{
	static int	center_x = WIN_WIDTH / 2;
	static int	center_y = WIN_HEIGHT / 2;
	int			delta_x;

	(void)y;
	if (cub->keys.mouse_pressed)
		return (0);
	delta_x = x - center_x;
	if (delta_x != 0)
	{
		rotate_player(cub, cub->player.mouse_sensitivity * delta_x);
		mlx_mouse_move(cub->mlx.mlx_ptr, cub->mlx.win_ptr, center_x, center_y);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->keys.mouse_pressed = 1;
	else if (button == 3)
		cub->keys.mouse_pressed = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->keys.mouse_pressed = 0;
	else if (button == 3)
		cub->keys.mouse_pressed = 0;
	return (0);
}
