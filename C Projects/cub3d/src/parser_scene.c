/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 00:53:46 by rfirat            #+#    #+#             */
/*   Updated: 2025/10/31 19:08:17 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	scene_init(t_scene *s)
{
	gc_init(&s->gc);
	s->no_path = NULL;
	s->so_path = NULL;
	s->we_path = NULL;
	s->ea_path = NULL;
	s->floor_color.r = -1;
	s->floor_color.g = -1;
	s->floor_color.b = -1;
	s->ceiling_color.r = -1;
	s->ceiling_color.g = -1;
	s->ceiling_color.b = -1;
	s->map_lines = NULL;
	s->map_height = 0;
	s->map_width = 0;
}

void	free_scene(t_scene *s)
{
	if (!s)
		return ;
	gc_free_all(&s->gc);
	scene_init(s);
}
