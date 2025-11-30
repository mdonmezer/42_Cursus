/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:17:27 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:11:09 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

void	init_player(t_cub *cub)
{
	cub->player.move_speed = 0.02;
	cub->player.rot_speed = 0.02;
	cub->player.mouse_sensitivity = 0.002;
	if (!find_player_spawn(cub))
	{
		cub->player.x = 1.5;
		cub->player.y = 1.5;
		cub->player.angle = 0.0;
	}
}

void	move_player(t_cub *cub, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.x + dx;
	new_y = cub->player.y + dy;
	if (!check_collision(cub, new_x, new_y))
	{
		cub->player.x = new_x;
		cub->player.y = new_y;
	}
}

void	rotate_player(t_cub *cub, double rotation_speed)
{
	cub->player.angle += rotation_speed;
	while (cub->player.angle < 0)
		cub->player.angle += 2 * M_PI;
	while (cub->player.angle >= 2 * M_PI)
		cub->player.angle -= 2 * M_PI;
}
