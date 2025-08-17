/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_proc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:22:11 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:22:12 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_parent(t_parent_ctx ctx)
{
	(void)ctx.shell;
	(void)ctx.pid;
	if (*ctx.in_fd != STDIN_FILENO)
		close(*ctx.in_fd);
	if (ctx.command->next)
	{
		close((*(ctx.pipe_fd))[1]);
		*ctx.in_fd = (*(ctx.pipe_fd))[0];
	}
	else
	{
		*ctx.in_fd = -1;
	}
}

void	finalize_pipeline(pid_t last_pid, t_shell *shell)
{
	int	status;

	if (last_pid > 0)
	{
		waitpid(last_pid, &status, 0);
		if (WIFEXITED(status))
			shell->last_exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->last_exit_code = 128 + WTERMSIG(status);
	}
	while (wait(NULL) > 0)
		;
}
