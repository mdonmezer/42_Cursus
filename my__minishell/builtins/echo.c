/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md <md@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:00:42 by md                #+#    #+#             */
/*   Updated: 2025/07/15 00:06:54 by md               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_echo(t_command *cmd)
{
	int	i;
	int	newline_flag;

	i = 1;
	newline_flag = 1;
	//-n'leri atla.
	while (cmd->args[i] && ft_strncmp(cmd->args[i], "-n", 3) == 0)
	{
		newline_flag = 0;
		i++;
	}
	//argümanları ekrana bas.
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], 1);
		if (cmd->args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	//eğer -n değilse newline bas
	if (newline_flag)
		ft_putchar_fd('\n', 1);
	return (0);
}
