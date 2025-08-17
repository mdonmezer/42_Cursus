/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:23:12 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:26:28 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_n_flag(char *s)
{
	int	i;

	if (!s || s[0] != '-' || s[1] != 'n')
		return (0);
	i = 2;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(t_command *cmd)
{
	int	i;
	int	newline_flag;

	i = 1;
	newline_flag = 1;
	while (cmd->args[i] && is_n_flag(cmd->args[i]))
	{
		newline_flag = 0;
		i++;
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], 1);
		if (cmd->args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline_flag)
		ft_putchar_fd('\n', 1);
	return (0);
}
