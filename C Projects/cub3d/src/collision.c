/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:17:27 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:09:59 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

int	is_wall(t_cub *cub, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= cub->scene_ref->map_width || map_y < 0
		|| map_y >= cub->scene_ref->map_height)
		return (1);
	if (cub->scene_ref->map_lines[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	check_collision(t_cub *cub, double new_x, double new_y)
{
	double	radius;
	double	check_x;
	double	check_y;
	double	angle;

	radius = 0.3;
	angle = 0;
	check_x = 0;
	check_y = 0;
	while (angle < 2 * M_PI)
	{
		check_x = new_x + radius * cos(angle);
		check_y = new_y + radius * sin(angle);
		if (is_wall(cub, check_x, check_y))
			return (1);
		angle += M_PI / 4;
	}
	return (0);
}
