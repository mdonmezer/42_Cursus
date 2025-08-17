/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:25:22 by mdonmeze          #+#    #+#             */
/*   Updated: 2025/08/15 20:25:23 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirections(t_redirect *head)
{
	t_redirect	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->filename)
			free(tmp->filename);
		if (tmp->type == REDIR_HEREDOC && tmp->pipe_fd != -1)
			close(tmp->pipe_fd);
		free(tmp);
	}
}

void	free_commands(t_command *head)
{
	t_command	*cmd_tmp;
	int			i;

	while (head)
	{
		cmd_tmp = head;
		head = head->next;
		if (cmd_tmp->args)
		{
			i = 0;
			while (cmd_tmp->args[i])
				free(cmd_tmp->args[i++]);
			free(cmd_tmp->args);
		}
		if (cmd_tmp->redirects)
			free_redirections(cmd_tmp->redirects);
		if (cmd_tmp->heredoc_delimiter)
			free(cmd_tmp->heredoc_delimiter);
		free(cmd_tmp);
	}
	head = NULL;
}
