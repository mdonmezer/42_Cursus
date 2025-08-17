/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:47:23 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:47:24 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell_all(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->token)
	{
		free_tokens(shell->token);
		shell->token = NULL;
	}
	if (shell->command)
	{
		free_commands(shell->command);
		shell->command = NULL;
	}
	if (shell->envp)
	{
		free_envp(shell->envp);
		shell->envp = NULL;
	}
}

void	cleanup_and_exit(t_shell *shell, int status)
{
	free_shell_all(shell);
	exit(status);
}
