/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:17:27 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:09:30 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

static void	set_player_spawn(t_cub *cub, int x, int y, char spawn_char)
{
	cub->player.x = x + 0.5;
	cub->player.y = y + 0.5;
	if (spawn_char == 'N')
		cub->player.angle = 3 * M_PI / 2;
	else if (spawn_char == 'S')
		cub->player.angle = M_PI / 2;
	else if (spawn_char == 'E')
		cub->player.angle = 0.0;
	else if (spawn_char == 'W')
		cub->player.angle = M_PI;
	cub->scene_ref->map_lines[y][x] = '0';
}

int	find_player_spawn(t_cub *cub)
{
	int		x;
	int		y;
	char	spawn_char;

	y = 0;
	while (y < cub->scene_ref->map_height)
	{
		x = 0;
		while (x < cub->scene_ref->map_width)
		{
			spawn_char = cub->scene_ref->map_lines[y][x];
			if (spawn_char == 'N' || spawn_char == 'S' || spawn_char == 'E'
				|| spawn_char == 'W')
			{
				set_player_spawn(cub, x, y, spawn_char);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
