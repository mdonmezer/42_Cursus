/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:42:55 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:47:14 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run_single_builtin_with_redirections(t_command *p, t_shell *sh)
{
	int		status;
	pid_t	pid;

	if (p->redirects)
	{
		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			if (handle_redirections(p) == -1)
				cleanup_and_exit(sh, EXIT_FAILURE);
			cleanup_and_exit(sh, execute_builtin(p, sh));
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			sh->last_exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			sh->last_exit_code = 128 + WTERMSIG(status);
	}
	else
		sh->last_exit_code = execute_builtin(p, sh);
}

static void	run_single_builtin(t_command *p, t_shell *sh)
{
	if (p->heredoc_delimiter)
	{
		if (execute_heredoc(p, sh) == -1)
		{
			sh->last_exit_code = 1;
			return ;
		}
	}
	if (p->args[0] && ft_strncmp(p->args[0], "exit", 5) == 0)
	{
		sh->last_exit_code = execute_builtin(p, sh);
		cleanup_and_exit(sh, sh->last_exit_code);
	}
	run_single_builtin_with_redirections(p, sh);
}

static void	run_child(t_command *p, t_shell *sh, int in_fd, int pipe_fd[2])
{
	int		exit_code;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (p->heredoc_delimiter)
	{
		if (execute_heredoc(p, sh) == -1)
			cleanup_and_exit(sh, 1);
	}
	setup_redirections(in_fd, pipe_fd, p);
	if (handle_redirections(p) == -1)
		cleanup_and_exit(sh, EXIT_FAILURE);
	if (is_builtin(p->args[0]))
	{
		if (ft_strncmp(p->args[0], "exit", 5) == 0)
		{
			exit_code = execute_builtin(p, sh);
			cleanup_and_exit(sh, exit_code);
		}
		cleanup_and_exit(sh, execute_builtin(p, sh));
	}
	run_child_path(p, sh);
}

static int	process_pipeline_node(t_command *p, t_shell *sh, int *in_fd,
							int (*pipe_fd)[2], pid_t *last_pid)
{
	pid_t	pid;

	if (p->next && pipe(*pipe_fd) == -1)
		return (perror("pipe"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
		run_child(p, sh, *in_fd, *pipe_fd);
	if (!p->next)
		*last_pid = pid;
	handle_parent((t_parent_ctx){
		.command = p,
		.shell = sh,
		.in_fd = in_fd,
		.pipe_fd = pipe_fd,
		.pid = pid
	});
	return (0);
}

void	execute_pipeline(t_command *pipeline, t_shell *shell)
{
	int		pipe_fd[2];
	int		in_fd;
	pid_t	last_pid;

	if (!pipeline || !pipeline->args || !pipeline->args[0])
		return ;
	if (is_single_builtin(pipeline))
		return (run_single_builtin(pipeline, shell));
	in_fd = STDIN_FILENO;
	last_pid = -1;
	while (pipeline)
	{
		if (process_pipeline_node(pipeline, shell, &in_fd, &pipe_fd, &last_pid))
			return ;
		pipeline = pipeline->next;
	}
	finalize_pipeline(last_pid, shell);
}
