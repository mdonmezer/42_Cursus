/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:22:01 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:49:24 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_path(char **path)
{
	int		i;

	if (!path)
		return ;
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

void	print_error_s(t_error_msg e)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd((char *)e.subject, 2);
	ft_putendl_fd((char *)e.suffix, 2);
}

static char	*direct_path_dir_or_dup(char *c)
{
	struct stat	path_stat;

	if (stat(c, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
		return (
			print_error_s((t_error_msg){
				.subject = c,
				.suffix = ": Is a directory"
			}),
			NULL
		);
	return (ft_strdup(c));
}

char	*direct_path(char *c)
{
	if (access(c, F_OK) == 0)
	{
		if (access(c, X_OK) == 0)
			return (direct_path_dir_or_dup(c));
		return (
			print_error_s((t_error_msg){
				.subject = c,
				.suffix = ": Permission denied"
			}),
			NULL
		);
	}
	return (
		print_error_s((t_error_msg){
			.subject = c,
			.suffix = ": No such file or directory"
		}),
		NULL
	);
}

char	*find_path_line(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->envp && sh->envp[i]
		&& ft_strncmp(sh->envp[i], "PATH=", 5) != 0)
		i++;
	if (!sh->envp || !sh->envp[i])
		return (NULL);
	return (sh->envp[i] + 5);
}
