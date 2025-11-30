/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:23:43 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:10:39 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_cub *cub)
{
	mlx_loop_end(cub->mlx.mlx_ptr);
	return (0);
}

int	expose_hook(t_cub *cub)
{
	render_frame(cub);
	return (0);
}

int	game_loop(t_cub *cub)
{
	if (cub->keys.w)
		move_player(cub, cos(cub->player.angle) * cub->player.move_speed,
			sin(cub->player.angle) * cub->player.move_speed);
	if (cub->keys.s)
		move_player(cub, -cos(cub->player.angle) * cub->player.move_speed,
			-sin(cub->player.angle) * cub->player.move_speed);
	if (cub->keys.a)
		move_player(cub, -sin(cub->player.angle) * cub->player.move_speed,
			cos(cub->player.angle) * cub->player.move_speed);
	if (cub->keys.d)
		move_player(cub, sin(cub->player.angle) * cub->player.move_speed,
			-cos(cub->player.angle) * cub->player.move_speed);
	if (cub->keys.left)
		rotate_player(cub, cub->player.rot_speed);
	if (cub->keys.right)
		rotate_player(cub, -cub->player.rot_speed);
	render_frame(cub);
	return (0);
}
