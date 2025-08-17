/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:11:04 by beergin           #+#    #+#             */
/*   Updated: 2025/08/13 12:28:49 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	merge_joined_tokens(t_token **token_iter, char **merged)
{
	char	*tmp;
	t_token	*cur;

	cur = *token_iter;
	while (cur->next && cur->next->type == TOKEN_WORD
		&& cur->next->joined_to_prev)
	{
		tmp = *merged;
		*merged = ft_strjoin(*merged, cur->next->value);
		free(tmp);
		if (!*merged)
			return (0);
		cur = cur->next;
	}
	*token_iter = cur;
	return (1);
}

static int	process_word_token(t_token **token_iter, t_command *new_cmd,
		t_command *cmd_head, int *i)
{
	char	*merged;

	merged = ft_strdup((*token_iter)->value);
	if (!merged)
		return (0);
	if (!merge_joined_tokens(token_iter, &merged))
		return (0);
	if (merged[0] == '\0')
	{
		free(merged);
		return (1);
	}
	new_cmd->args[*i] = merged;
	if (!new_cmd->args[*i])
	{
		free_commands(cmd_head);
		free(new_cmd->args);
		free(new_cmd);
		return (0);
	}
	(*i)++;
	return (1);
}

int	handle_token(t_token **token_iter, t_command *new_cmd, t_command *cmd_head,
		int *i)
{
	if ((*token_iter)->type == TOKEN_WORD)
	{
		if (!process_word_token(token_iter, new_cmd, cmd_head, i))
			return (0);
	}
	else if ((*token_iter)->type == TOKEN_REDIRECT_IN
		|| (*token_iter)->type == TOKEN_REDIRECT_OUT
		|| (*token_iter)->type == TOKEN_REDIRECT_APPEND)
	{
		if (!handle_redirects(token_iter, new_cmd, cmd_head))
			return (0);
	}
	else if ((*token_iter)->type == TOKEN_HERE_DOC)
	{
		if (!handle_heredoc(token_iter, new_cmd))
			return (0);
	}
	return (1);
}
