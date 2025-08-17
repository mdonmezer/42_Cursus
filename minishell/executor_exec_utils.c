/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_exec_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:21:55 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:47:46 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command_path(char *cmd, t_shell *shell)
{
	char	**paths;
	char	*path_line;
	char	*result;

	if (!cmd || !cmd[0])
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (direct_path(cmd));
	path_line = find_path_line(shell);
	if (!path_line)
		return (NULL);
	paths = ft_split(path_line, ':');
	if (!paths)
		return (NULL);
	result = search_in_paths(paths, cmd);
	if (result)
	{
		free_path(paths);
		return (result);
	}
	free_path(paths);
	return (NULL);
}

int	is_single_builtin(t_command *p)
{
	return (p && p->next == NULL && p->args && p->args[0]
		&& is_builtin(p->args[0]));
}

void	run_child_path(t_command *p, t_shell *sh)
{
	char	*path;

	path = get_command_path(p->args[0], sh);
	if (!path)
	{
		if (ft_strchr(p->args[0], '/'))
		{
			if (access(p->args[0], F_OK) == 0)
				cleanup_and_exit(sh, 126);
			else
				cleanup_and_exit(sh, 127);
		}
		print_error_s((t_error_msg){
			.subject = p->args[0],
			.suffix = ": command not found"
		});
		cleanup_and_exit(sh, 127);
	}
	execve(path, p->args, sh->envp);
	perror("minishell: execve");
	free(path);
	cleanup_and_exit(sh, EXIT_FAILURE);
}

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
