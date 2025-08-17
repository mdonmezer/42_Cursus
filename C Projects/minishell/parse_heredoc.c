/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmeze <mdonmeze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:29:53 by beergin           #+#    #+#             */
/*   Updated: 2025/08/15 20:24:42 by mdonmeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc_token(t_command *cmd, t_token *tmp, t_shell *shell)
{
	(void)shell;
	if (tmp->next && tmp->next->type == TOKEN_WORD)
	{
		cmd->heredoc_delimiter = ft_strdup(tmp->next->value);
	}
}

void	parse_heredoc(t_command *cmd, t_token *token, t_shell *shell)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == TOKEN_HERE_DOC)
		{
			handle_heredoc_token(cmd, tmp, shell);
		}
		tmp = tmp->next;
	}
}
