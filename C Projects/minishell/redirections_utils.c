/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:32:44 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/05 01:24:12 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_file_redirection(t_redirect *redir)
{
	int	fd;

	if (redir->type == REDIR_OUT)
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == REDIR_APPEND)
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir->type == REDIR_IN)
		fd = open(redir->filename, O_RDONLY);
	else
		return (-2);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(redir->filename);
		exit(1);
	}
	return (fd);
}

static void	handle_heredoc_redirection(t_redirect *redir)
{
	int	fd;

	fd = redir->pipe_fd;
	if (fd != -1)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	process_file_redirection(t_redirect *redir)
{
	int	fd;

	fd = handle_file_redirection(redir);
	if (fd == -2)
		return ;
	if (redir->type == REDIR_IN)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
}

int	handle_redirections(t_command *cmd)
{
	t_redirect	*redir;

	if (!cmd->redirects)
		return (0);
	redir = cmd->redirects;
	while (redir)
	{
		if (redir->type == REDIR_HEREDOC)
			handle_heredoc_redirection(redir);
		else
			process_file_redirection(redir);
		redir = redir->next;
	}
	return (0);
}
