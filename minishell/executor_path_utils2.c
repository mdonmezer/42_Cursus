/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_path_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:22:06 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:22:07 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_in_paths(char **p, char *c)
{
	int		i;
	char	*path_part;
	char	*full_path;

	i = 0;
	while (p[i])
	{
		path_part = ft_strjoin(p[i], "/");
		full_path = ft_strjoin(path_part, c);
		free(path_part);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}
