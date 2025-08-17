/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:50:37 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:23:39 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_exit_command(char *line, t_shell *shell)
{
	shell->token = lexer(line);
	if (shell->token)
	{
		expand_variables(shell->token, shell);
		shell->command = parser(shell->token, shell);
		if (shell->command)
		{
			shell->last_exit_code = execute_builtin(shell->command, shell);
			return (1);
		}
	}
	return (1);
}
