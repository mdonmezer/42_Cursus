/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:11:04 by beergin           #+#    #+#             */
/*   Updated: 2025/08/13 12:28:49 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_parent(t_command *cmd, t_heredoc *hd)
{
	close(hd->pipe_fd[1]);
	waitpid(hd->pid, &hd->status, 0);
	if (WIFEXITED(hd->status) && WEXITSTATUS(hd->status) != 0)
	{
		close(hd->pipe_fd[0]);
		return (-1);
	}
	hd->heredoc_redir = malloc(sizeof(t_redirect));
	if (!hd->heredoc_redir)
	{
		close(hd->pipe_fd[0]);
		return (-1);
	}
	hd->heredoc_redir->type = REDIR_HEREDOC;
	hd->heredoc_redir->filename = NULL;
	hd->heredoc_redir->pipe_fd = hd->pipe_fd[0];
	hd->heredoc_redir->next = NULL;
	add_redirection(&cmd->redirects, hd->heredoc_redir);
	return (0);
}
