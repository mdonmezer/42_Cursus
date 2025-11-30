/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 01:09:58 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/01 22:08:36 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	run_cub3d(t_scene *scene, t_cub *cub)
{
	cub->scene_ref = scene;
	init_mlx_struct(cub);
	init_player(cub);
	if (init_mlx_and_start(cub) != 0)
	{
		printf(C_BRED "Error:" C_RESET " Failed to initialize MLX\n");
		return ;
	}
}

int	main(int argc, char **argv)
{
	const char	*map_path;
	t_scene		scene;
	t_cub		cub;

	if (validate_arguments(argc, argv, &map_path) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (parse_scene(map_path, &scene) != 0)
		return (EXIT_FAILURE);
	run_cub3d(&scene, &cub);
	free_scene(&scene);
	return (EXIT_SUCCESS);
}
