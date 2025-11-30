/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_reader_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfirat <rfirat@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:28:15 by rfirat            #+#    #+#             */
/*   Updated: 2025/11/28 17:10:47 by rfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_lines_with_gnl(const char *path, char ***out_lines,
		int *out_count, t_gc *gc)
{
	int				fd;
	char			**arr;
	int				count;
	t_line_params	p;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (init_line_params(&p, gc, &arr, &count) != 0)
	{
		close(fd);
		return (-1);
	}
	if (read_lines_from_fd(fd, &p) != 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	*out_lines = arr;
	*out_count = count;
	return (0);
}
